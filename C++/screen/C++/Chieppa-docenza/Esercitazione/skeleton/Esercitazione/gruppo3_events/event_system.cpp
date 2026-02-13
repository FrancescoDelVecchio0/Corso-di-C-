#include "event_system.hpp"
#include <iostream>
#include <algorithm>

namespace rpg::events {

// ============================================================================
// IMPLEMENTAZIONI EVENT MANAGER
// ============================================================================

auto EventManager::subscribe([[maybe_unused]] EventType event_type, [[maybe_unused]] EventCallback callback) -> int {
    // TODO: Aggiungere callback alla lista per event_type
    // Generare e ritornare un ID univoco
    // Suggerimento: incrementare next_observer_id_
    
    return 0;  // PLACEHOLDER
}

void EventManager::unsubscribe([[maybe_unused]] int observer_id) {
    // TODO: Rimuovere observer con questo ID
    // Suggerimento: cercare in tutte le liste di callback
}

void EventManager::emit([[maybe_unused]] const EventData& event) {
    // TODO: Chiamare tutti i callback registrati per event.type
    // Suggerimento: trovare la lista corrispondente e iterare
}

void EventManager::clear_all() {
    // TODO: Pulire tutte le liste di observers
}

void EventManager::print_stats() const {
    // TODO: Stampare quanti observers sono registrati per ogni tipo
    std::cout << "Event Manager Stats:\n";
    // ... implementare
}

// ============================================================================
// OBSERVERS PREDEFINITI
// ============================================================================

auto create_logger_observer() -> EventCallback {
    // TODO: Ritornare una lambda che stampa l'evento
    // Es: "[EVENT] Enemy Defeated: Goblin (XP: 50)"
    
    return [](const EventData&) {
        // ... implementare
    };
}

// ============================================================================
// STATS TRACKER
// ============================================================================

auto StatsTracker::get_callback() -> EventCallback {
    // TODO: Ritornare lambda che aggiorna le statistiche
    // Catturare this per riferimento: [this]
    // Incrementare contatori appropriati in base a event.type
    
    return [this](const EventData&) {
        // ... implementare
    };
}

void StatsTracker::print_stats() const {
    std::cout << "\n=== PLAYER STATISTICS ===\n";
    std::cout << "Enemies Defeated: " << enemies_defeated_ << "\n";
    std::cout << "Items Collected: " << items_collected_ << "\n";
    std::cout << "Total XP Earned: " << total_xp_earned_ << "\n";
}

// ============================================================================
// ACHIEVEMENT SYSTEM
// ============================================================================

auto AchievementSystem::get_callback() -> EventCallback {
    // TODO: Ritornare lambda che controlla achievement
    // Es: se enemy_kill_count_ raggiunge 10, stampa achievement
    
    return [this](const EventData&) {
        // ... implementare
    };
}

void AchievementSystem::print_achievements() const {
    std::cout << "\n=== ACHIEVEMENTS ===\n";
    if (enemy_kill_count_ >= 10) {
        std::cout << "✓ Monster Slayer (Defeat 10 enemies)\n";
    }
    if (first_boss_killed_) {
        std::cout << "✓ Dragon Slayer (Defeat your first boss)\n";
    }
    if (collector_achievement_) {
        std::cout << "✓ Collector (Collect 20 items)\n";
    }
}

// ============================================================================
// UTILITY
// ============================================================================

auto event_type_to_string(EventType type) -> std::string {
    // TODO: Convertire enum in stringa leggibile
    switch (type) {
        case EventType::enemy_defeated: return "Enemy Defeated";
        // ... completare altri casi
        default: return "Unknown Event";
    }
}

} // namespace rpg::events
