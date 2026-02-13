#include "ai_system.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>

namespace rpg::ai {

// ============================================================================
// IMPLEMENTAZIONI AI ENTITY
// ============================================================================

void AIEntity::set_strategy([[maybe_unused]] AIStrategy strategy) {
    // TODO: Assegnare nuova strategia
}

void AIEntity::update([[maybe_unused]] const Position& player_pos) {
    // TODO: Eseguire strategia corrente se presente
    // Chiamare: current_strategy_(*this, player_pos);
}

// ============================================================================
// STRATEGIE PREDEFINITE
// ============================================================================

auto idle_strategy() -> AIStrategy {
    // TODO: Ritornare lambda che non fa nulla
    return [](AIEntity&, const Position&) {
        // Entity rimane ferma
    };
}

auto patrol_strategy(float patrol_range) -> AIStrategy {
    // TODO: Implementare patrol
    // L'entità si muove dal punto di spawn in una direzione fino a patrol_range
    // Poi inverte e torna indietro
    // Suggerimento: usare entity.is_moving_forward() e entity.toggle_direction()
    
    return [patrol_range](AIEntity&, const Position&) {
        [[maybe_unused]] const auto range = patrol_range;
        // ... implementare
    };
}

auto chase_strategy(float detection_range, float speed_mult) -> AIStrategy {
    // TODO: Implementare chase
    // Se player è entro detection_range, muovi verso player
    // Altrimenti rimani fermo
    // Suggerimento: usare move_towards()
    
    return [detection_range, speed_mult](AIEntity&, const Position&) {
        [[maybe_unused]] const auto dr = detection_range;
        [[maybe_unused]] const auto sm = speed_mult;
        // ... implementare
    };
}

auto flee_strategy(float flee_distance) -> AIStrategy {
    // TODO: Implementare flee
    // Se player è entro flee_distance, scappa
    // Suggerimento: usare move_away_from()
    
    return [flee_distance](AIEntity&, const Position&) {
        [[maybe_unused]] const auto fd = flee_distance;
        // ... implementare
    };
}

auto aggressive_strategy(float chase_range, float attack_range) -> AIStrategy {
    // TODO: Implementare aggressive
    // Chase se player tra attack_range e chase_range
    // Stampa "Attacking!" se player entro attack_range
    
    return [chase_range, attack_range](AIEntity&, const Position&) {
        [[maybe_unused]] const auto cr = chase_range;
        [[maybe_unused]] const auto ar = attack_range;
        // ... implementare
    };
}

auto defensive_strategy(float patrol_range, float flee_distance) -> AIStrategy {
    // TODO: Implementare defensive
    // Patrol se player lontano, flee se vicino
    
    return [patrol_range, flee_distance](AIEntity&, const Position&) {
        [[maybe_unused]] const auto pr = patrol_range;
        [[maybe_unused]] const auto fd = flee_distance;
        // ... implementare
    };
}

// ============================================================================
// IMPLEMENTAZIONI AI MANAGER
// ============================================================================

void AIManager::add_entity([[maybe_unused]] std::unique_ptr<AIEntity> entity) {
    // TODO: Aggiungere entity al vector
}

void AIManager::update_all([[maybe_unused]] const Position& player_pos) {
    // TODO: Chiamare update() su tutte le entità
}

void AIManager::remove_dead_entities() {
    // TODO: Rimuovere entità morte
    // Suggerimento: usare std::remove_if + erase
}

auto AIManager::get_entity_by_name([[maybe_unused]] const std::string& name) -> AIEntity* {
    // TODO: Cercare entità per nome
    // Suggerimento: usare std::find_if
    return nullptr;  // PLACEHOLDER
}

void AIManager::print_all_positions() const {
    std::cout << "\n=== AI ENTITIES ===\n";
    for (const auto& entity : entities_) {
        std::cout << entity->name() << " at (" 
                  << entity->position().x << ", " 
                  << entity->position().y << ") "
                  << "HP: " << entity->health() << "\n";
    }
}

// ============================================================================
// UTILITY FUNCTIONS
// ============================================================================

auto move_towards([[maybe_unused]] Position& current,
                  [[maybe_unused]] const Position& target,
                  [[maybe_unused]] float speed) -> bool {
    // TODO: Muovere current verso target.
    // Passi:
    // 1) dx = target.x - current.x, dy = target.y - current.y
    // 2) distanza = sqrt(dx*dx + dy*dy)
    // 3) se distanza < 0.5f -> return true (gia' arrivato)
    // 4) altrimenti normalizza: dir = (dx/distanza, dy/distanza)
    // 5) aggiorna current: current += dir * speed
    // 6) return false
    
    return false;  // PLACEHOLDER
}

void move_away_from([[maybe_unused]] Position& current,
                    [[maybe_unused]] const Position& target,
                    [[maybe_unused]] float speed) {
    // TODO: Muovere current nella direzione opposta al target.
    // Passi:
    // 1) dx = current.x - target.x, dy = current.y - target.y
    // 2) distanza = sqrt(dx*dx + dy*dy)
    // 3) se distanza > epsilon: current += (dx/distanza, dy/distanza) * speed
    // Nota: e' l'opposto di move_towards, che usa (target - current).
}

} // namespace rpg::ai
