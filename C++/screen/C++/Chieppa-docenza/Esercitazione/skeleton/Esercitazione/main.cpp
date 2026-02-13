#include "common/types.hpp"
#include "gruppo1_combat/combat_system.hpp"
#include "gruppo2_inventory/inventory_system.hpp"
#include "gruppo3_events/event_system.hpp"
#include "gruppo4_ai/ai_system.hpp"

#include <iostream>
#include <thread>
#include <chrono>

// ============================================================================
// MAIN - INTEGRAZIONE DI TUTTI I SISTEMI
// ============================================================================

int main() {
    std::cout << "==============================================\n";
    std::cout << "   RPG ENGINE - ESERCITAZIONE FINALE C++     \n";
    std::cout << "==============================================\n\n";

    // ------------------------------------------------------------------------
    // SETUP: Inizializzazione di tutti i sistemi
    // ------------------------------------------------------------------------

    // Sistema Eventi (Gruppo 3)
    rpg::events::EventManager event_manager;
    rpg::events::StatsTracker stats;
    rpg::events::AchievementSystem achievements;

    [[maybe_unused]] const auto logger_sub_id =
        event_manager.subscribe(rpg::events::EventType::enemy_defeated,
            rpg::events::create_logger_observer());
    [[maybe_unused]] const auto stats_sub_id =
        event_manager.subscribe(rpg::events::EventType::enemy_defeated,
            stats.get_callback());
    [[maybe_unused]] const auto achievements_sub_id =
        event_manager.subscribe(rpg::events::EventType::enemy_defeated,
            achievements.get_callback());

    // Registra observer anche per item_collected
    [[maybe_unused]] const auto stats_items_sub_id =
        event_manager.subscribe(rpg::events::EventType::item_collected,
            stats.get_callback());
    [[maybe_unused]] const auto achievements_items_sub_id =
        event_manager.subscribe(rpg::events::EventType::item_collected,
            achievements.get_callback());

    // Player e Inventario (Gruppo 1 & 2)
    rpg::combat::Player player("Hero");
    rpg::inventory::Inventory inventory(20, 100);

    // Aggiungi alcuni item iniziali E EMETTI EVENTI
    if (inventory.add_item(rpg::inventory::create_common_item("health_potion"))) {
        event_manager.emit(rpg::events::EventData{
            rpg::events::EventType::item_collected,
            "Found Health Potion",
            0
            });
    }
    if (inventory.add_item(rpg::inventory::create_common_item("iron_sword"))) {
        event_manager.emit(rpg::events::EventData{
            rpg::events::EventType::item_collected,
            "Found Iron Sword",
            0
            });
    }

    std::cout << "\n=== PLAYER SETUP ===\n";
    std::cout << player.get_description() << "\n";
    inventory.list_items();

    // Sistema AI (Gruppo 4)
    rpg::ai::AIManager ai_manager;

    auto goblin1 = std::make_unique<rpg::ai::AIEntity>("Goblin Patrol",
        rpg::Position{ 5.0f, 0.0f });
    goblin1->set_strategy(rpg::ai::patrol_strategy(5.0f));
    ai_manager.add_entity(std::move(goblin1));

    auto orc1 = std::make_unique<rpg::ai::AIEntity>("Orc Guard",
        rpg::Position{ 15.0f, 0.0f });
    orc1->set_strategy(rpg::ai::chase_strategy(10.0f));
    ai_manager.add_entity(std::move(orc1));

    // ------------------------------------------------------------------------
    // SIMULAZIONE GAMEPLAY
    // ------------------------------------------------------------------------

    std::cout << "\n\n=== STARTING GAMEPLAY SIMULATION ===\n";

    // Turno 1: Movimento e AI
    std::cout << "\n--- Turn 1: AI Behavior ---\n";
    rpg::Position player_pos{ 10.0f, 0.0f };
    ai_manager.update_all(player_pos);
    ai_manager.print_all_positions();

    // Turno 2: Combattimento
    std::cout << "\n--- Turn 2: Combat ---\n";
    auto enemy1 = rpg::combat::create_enemy("goblin");
    if (enemy1) {
        // Loop finché il nemico è vivo
        while (enemy1->is_alive() && player.is_alive()) {
            rpg::combat::execute_combat_turn(player, *enemy1);
            if (!enemy1->is_alive()) {
                event_manager.emit(rpg::events::EventData{
                    rpg::events::EventType::enemy_defeated,
                    "Defeated Goblin",
                    50  // XP
                    });
            }
        }
    }

    // Turno 3: Usa item
    std::cout << "\n--- Turn 3: Using Items ---\n";
    std::cout << player.get_description() << "\n";
    [[maybe_unused]] const auto used_health_potion = inventory.use_item("health_potion");
    player.heal(50);  // Simula effetto pozione
    std::cout << player.get_description() << "\n";

    // Turno 4: Boss fight
    std::cout << "\n--- Turn 4: Boss Encounter ---\n";
    auto dragon = rpg::combat::create_enemy("dragon");
    if (dragon) {
        event_manager.emit(rpg::events::EventData{
            rpg::events::EventType::boss_spawned,
            "Dragon appears!",
            0
            });

        // Cambia strategia dell'Orc quando appare il boss
        if (auto orc = ai_manager.get_entity_by_name("Orc Guard")) {
            orc->set_strategy(rpg::ai::flee_strategy(15.0f));
            std::cout << "Orc Guard is fleeing from the Dragon!\n";
        }

        // Loop finché il dragon è vivo (o il player muore)
        while (dragon->is_alive() && player.is_alive()) {
            rpg::combat::execute_combat_turn(player, *dragon);
            if (!dragon->is_alive()) {
                event_manager.emit(rpg::events::EventData{
                    rpg::events::EventType::enemy_defeated,
                    "Defeated Dragon",
                    200  // XP
                    });
            }
        }
    }

    // ------------------------------------------------------------------------
    // STATISTICHE FINALI
    // ------------------------------------------------------------------------

    std::cout << "\n\n==============================================\n";
    std::cout << "            FINAL STATISTICS                  \n";
    std::cout << "==============================================\n";

    std::cout << "\n" << player.get_description() << "\n";

    std::cout << "\nInventory value: " << inventory.calculate_total_value()
        << " gold\n";
    std::cout << "Current gold: " << inventory.gold() << "\n";

    stats.print_stats();
    achievements.print_achievements();

    std::cout << "\n==============================================\n";
    std::cout << "   ESERCITAZIONE COMPLETATA CON SUCCESSO!    \n";
    std::cout << "==============================================\n";

    return 0;
}