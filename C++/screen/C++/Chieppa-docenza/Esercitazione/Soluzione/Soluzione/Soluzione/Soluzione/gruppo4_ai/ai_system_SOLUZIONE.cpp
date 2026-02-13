#include "../gruppo4_ai/ai_system.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>

namespace rpg::ai {

// ============================================================================
// SOLUZIONI CHIAVE GRUPPO 4
// ============================================================================

// AIEntity::set_strategy
void AIEntity::set_strategy(AIStrategy strategy) {
    current_strategy_ = std::move(strategy);
}

// AIEntity::update
void AIEntity::update(const Position& player_pos) {
    if (current_strategy_) {
        current_strategy_(*this, player_pos);
    }
}

// idle_strategy
auto idle_strategy() -> AIStrategy {
    return [](AIEntity&, const Position&) {
        // Non fa nulla
    };
}

// patrol_strategy
auto patrol_strategy(float patrol_range) -> AIStrategy {
    return [patrol_range](AIEntity& entity, const Position&) {
        auto pos = entity.position();
        const auto spawn = entity.spawn_position();
        
        if (entity.is_moving_forward()) {
            pos.x += entity.speed();
            if (pos.distance_to(spawn) >= patrol_range) {
                entity.toggle_direction();
            }
        } else {
            pos.x -= entity.speed();
            if (pos.distance_to(spawn) <= 0.5f) {
                entity.toggle_direction();
            }
        }
        
        entity.set_position(pos);
    };
}

// chase_strategy
auto chase_strategy(float detection_range, float speed_mult) -> AIStrategy {
    return [detection_range, speed_mult](AIEntity& entity, const Position& player_pos) {
        const float distance = entity.position().distance_to(player_pos);
        
        if (distance <= detection_range) {
            auto pos = entity.position();
            [[maybe_unused]] const auto reached =
                move_towards(pos, player_pos, entity.speed() * speed_mult);
            entity.set_position(pos);
        }
    };
}

// flee_strategy
auto flee_strategy(float flee_distance) -> AIStrategy {
    return [flee_distance](AIEntity& entity, const Position& player_pos) {
        const float distance = entity.position().distance_to(player_pos);
        
        if (distance <= flee_distance) {
            auto pos = entity.position();
            move_away_from(pos, player_pos, entity.speed() * 1.5f);
            entity.set_position(pos);
        }
    };
}

// AIManager::add_entity
void AIManager::add_entity(std::unique_ptr<AIEntity> entity) {
    entities_.push_back(std::move(entity));
}

// AIManager::update_all
void AIManager::update_all(const Position& player_pos) {
    for (auto& entity : entities_) {
        if (entity->is_alive()) {
            entity->update(player_pos);
        }
    }
}

// AIManager::get_entity_by_name
auto AIManager::get_entity_by_name(const std::string& name) -> AIEntity* {
    auto it = std::find_if(entities_.begin(), entities_.end(),
        [&name](const auto& entity) {
            return entity->name() == name;
        });
    
    return (it != entities_.end()) ? it->get() : nullptr;
}

// move_towards
auto move_towards(Position& current, const Position& target, float speed) -> bool {
    const float dx = target.x - current.x;
    const float dy = target.y - current.y;
    const float distance = std::sqrt(dx * dx + dy * dy);
    
    if (distance < 0.5f) {
        return true;  // Arrivato
    }
    
    // Normalizza direzione e muovi
    current.x += (dx / distance) * speed;
    current.y += (dy / distance) * speed;
    
    return false;
}

// move_away_from
void move_away_from(Position& current, const Position& target, float speed) {
    const float dx = current.x - target.x;
    const float dy = current.y - target.y;
    const float distance = std::sqrt(dx * dx + dy * dy);
    
    if (distance > 0.01f) {
        current.x += (dx / distance) * speed;
        current.y += (dy / distance) * speed;
    }
}

// ============================================================================
// METODI PRINT MANCANTI
// ============================================================================

// AIManager::print_all_positions
void AIManager::print_all_positions() const {
    std::cout << "\n=== AI Entity Positions ===\n";
    for (const auto& entity : entities_) {
        const auto& pos = entity->position();
        std::cout << entity->name() << ": (" 
                  << pos.x << ", " << pos.y << ") "
                  << "HP: " << entity->health() << "\n";
    }
}

} // namespace rpg::ai
