#include "../gruppo3_events/event_system.hpp"
#include <iostream>
#include <algorithm>

namespace rpg::events {

    // ============================================================================
    // SOLUZIONI CHIAVE GRUPPO 3 - VERSIONE CORRETTA
    // ============================================================================

    // Struttura per memorizzare observers con il loro ID
    struct ObserverInfo {
        int id;
        EventType event_type;
        EventCallback callback;
    };

    // Storage statico per gli observer (semplificazione per evitare pImpl)
    static std::vector<ObserverInfo> g_observers;

    // EventManager::subscribe - VERSIONE CORRETTA
    auto EventManager::subscribe(EventType event_type, EventCallback callback) -> int {
        const int id = next_observer_id_++;

        // SALVA la callback nella lista degli observer
        g_observers.push_back(ObserverInfo{ id, event_type, callback });

        return id;
    }

    // EventManager::unsubscribe
    void EventManager::unsubscribe(int observer_id) {
        g_observers.erase(
            std::remove_if(g_observers.begin(), g_observers.end(),
                [observer_id](const ObserverInfo& obs) {
                    return obs.id == observer_id;
                }),
            g_observers.end()
                    );
    }

    // EventManager::emit - VERSIONE CORRETTA
    void EventManager::emit(const EventData& event) {
        // Stampa messaggio evento
        std::cout << "[EVENT] " << event_type_to_string(event.type)
            << ": " << event.message << "\n";

        // NOTIFICA tutti gli observer registrati per questo tipo di evento
        for (const auto& obs : g_observers) {
            if (obs.event_type == event.type) {
                obs.callback(event);  // CHIAMA la callback!
            }
        }
    }

    // EventManager::clear_all
    void EventManager::clear_all() {
        g_observers.clear();
        next_observer_id_ = 0;
    }

    // EventManager::print_stats
    void EventManager::print_stats() const {
        std::cout << "\n=== Event Manager Stats ===\n";
        std::cout << "Total observers: " << g_observers.size() << "\n";
        std::cout << "Next observer ID: " << next_observer_id_ << "\n";
    }

    // create_logger_observer
    auto create_logger_observer() -> EventCallback {
        return [](const EventData& event) {
            std::cout << "[LOG] " << event_type_to_string(event.type)
                << ": " << event.message;
            if (event.value > 0) {
                std::cout << " (Value: " << event.value << ")";
            }
            std::cout << "\n";
        };
    }

    // StatsTracker::get_callback
    auto StatsTracker::get_callback() -> EventCallback {
        return [this](const EventData& event) {
            switch (event.type) {
            case EventType::enemy_defeated:
                enemies_defeated_++;
                total_xp_earned_ += event.value;
                break;
            case EventType::item_collected:
                items_collected_++;
                break;
            default:
                break;
            }
        };
    }

    // StatsTracker::print_stats
    void StatsTracker::print_stats() const {
        std::cout << "\n=== Statistics ===\n";
        std::cout << "Enemies Defeated: " << enemies_defeated_ << "\n";
        std::cout << "Items Collected: " << items_collected_ << "\n";
        std::cout << "Total XP Earned: " << total_xp_earned_ << "\n";
    }

    // AchievementSystem::get_callback
    auto AchievementSystem::get_callback() -> EventCallback {
        // Contatore items per achievement (static per persistenza tra chiamate)
        static int item_count = 0;

        return [this](const EventData& event) {
            if (event.type == EventType::enemy_defeated) {
                enemy_kill_count_++;

                if (enemy_kill_count_ == 10) {
                    std::cout << "\n🏆 ACHIEVEMENT UNLOCKED: Monster Slayer!\n";
                }

                if (event.message.find("Dragon") != std::string::npos ||
                    event.message.find("dragon") != std::string::npos) {
                    first_boss_killed_ = true;
                    std::cout << "\n🏆 ACHIEVEMENT UNLOCKED: Dragon Slayer!\n";
                }
            }
            else if (event.type == EventType::item_collected) {
                item_count++;

                // Achievement "Collector" a 20 item
                if (item_count >= 20 && !collector_achievement_) {
                    collector_achievement_ = true;
                    std::cout << "\n🏆 ACHIEVEMENT UNLOCKED: Collector - Collected 20 items!\n";
                }
            }
        };
    }

    // AchievementSystem::print_achievements
    void AchievementSystem::print_achievements() const {
        std::cout << "\n=== Achievements ===\n";

        if (first_boss_killed_) {
            std::cout << "🏆 Boss Slayer - Defeated your first boss!\n";
        }
        if (collector_achievement_) {
            std::cout << "🏆 Collector - Collected 20 items!\n";
        }
        if (enemy_kill_count_ >= 10) {
            std::cout << "🏆 Monster Hunter - Defeated 10 enemies!\n";
        }
        if (enemy_kill_count_ == 1) {
            std::cout << "🏆 First Blood - Defeated your first enemy!\n";
        }

        if (!first_boss_killed_ && !collector_achievement_ && enemy_kill_count_ < 1) {
            std::cout << "(No achievements unlocked yet)\n";
        }
    }

    // event_type_to_string
    auto event_type_to_string(EventType type) -> std::string {
        switch (type) {
        case EventType::enemy_defeated: return "Enemy Defeated";
        case EventType::player_level_up: return "Player Level Up";
        case EventType::item_collected: return "Item Collected";
        case EventType::boss_spawned: return "Boss Spawned";
        case EventType::quest_completed: return "Quest Completed";
        case EventType::player_death: return "Player Death";
        default: return "Unknown Event";
        }
    }

} // namespace rpg::events