#include "ai_system.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>

namespace rpg::ai {

// ============================================================================
// IMPLEMENTAZIONI AI ENTITY
// ============================================================================

void AIEntity::set_strategy([[maybe_unused]] AIStrategy strategy) {
	current_strategy_ = std::move(strategy);
}

void AIEntity::update([[maybe_unused]] const Position& player_pos) {
    current_strategy_(*this, player_pos);
}

// ============================================================================
// STRATEGIE PREDEFINITE
// ============================================================================

auto idle_strategy() -> AIStrategy {
    return [](AIEntity& e, const Position&) {
        // Entity rimane ferma
        std::cout << "[Idle] {" << e.name() << "} is currently in idle\n";
    };
}

auto patrol_strategy(float patrol_range) -> AIStrategy {
    // L'entità si muove dal punto di spawn in una direzione fino a patrol_range
    // Poi inverte e torna indietro
    // Suggerimento: usare entity.is_moving_forward() e entity.toggle_direction()
    
    return [patrol_range](AIEntity& e, const Position&) {
        [[maybe_unused]] const auto range = patrol_range;

        if (e.is_moving_forward())
        {
            // Muoviamo l'entità
            Position target;
			target.x = e.position().x + e.speed();  // Muovi verso destra
			target.y = e.position().y + e.speed();  // Muovi verso avanti
			e.set_position(target);

			// Quanto lontano siamo arrivati dal punto di spawn?
			float distanceFromSpawn = e.position().distance_to(e.spawn_position());
            if (distanceFromSpawn >= range)
            {
				e.toggle_direction();  // Inverti direzione
            }
        }

        std::cout << "[Patrol] {" << e.name() << "} at (" << e.position().x << ", " << e.position().y << ")\n";
    };
}

auto chase_strategy(float detection_range, float speed_mult) -> AIStrategy {
    // Se player è entro detection_range, muovi verso player
    // Altrimenti rimani fermo
    // Suggerimento: usare move_towards()
    
    return [detection_range, speed_mult](AIEntity& e, const Position& player) {
        [[maybe_unused]] const auto dr = detection_range;
        [[maybe_unused]] const auto sm = speed_mult;
        if (e.position().distance_to(player) <= dr)
        {
			Position pos = e.position();
			move_towards(pos, player, e.speed() * sm);
			e.set_position(pos);

            std::cout << "[Chase] {" << e.name() << "} is moving towards the player at (" << player.x << ", " << player.y << "). Current Progress: (" << e.position().x << ", " << e.position().y << "\n";
            return;
        }

        std::cout << "[Chase] {" << e.name() << "} is either too far from player or reached him.\n";
    };
}

auto flee_strategy(float flee_distance) -> AIStrategy {
    // Se player è entro flee_distance, scappa
    // Suggerimento: usare move_away_from()
    
    return [flee_distance](AIEntity& e, const Position& player) {
        [[maybe_unused]] const auto fd = flee_distance;
        if (e.position().distance_to(player) <= fd)
        {
			Position pos = e.position();
			move_away_from(pos, player, e.speed());
			e.set_position(pos);

            std::cout << "[Flee] {" << e.name() << "} is fleeing from the player at (" << player.x << ", " << player.y << "). Current Position: (" << e.position().x << ", " << e.position().y << "\n";
        }
    };
}

auto aggressive_strategy(float chase_range, float attack_range) -> AIStrategy {
    // Chase se player tra attack_range e chase_range
    // Stampa "Attacking!" se player entro attack_range
    
    return [chase_range, attack_range](AIEntity& e, const Position& player) {
        [[maybe_unused]] const auto cr = chase_range;
        [[maybe_unused]] const auto ar = attack_range;
        if (e.position().distance_to(player) > attack_range &&
            e.position().distance_to(player) <= chase_range)
        {
			e.set_strategy(chase_strategy(chase_range));  // Cambia a chase se entro chase_range
        }
        else if (e.position().distance_to(player) <= attack_range)
        {
            std::cout << "[Aggressive] {" << e.name() << "} is Attacking! Player at (" << player.x << ", " << player.y << ")\n";
		}
    };
}

auto defensive_strategy(float patrol_range, float flee_distance) -> AIStrategy {
    // Patrol se player lontano, flee se vicino
    
    return [patrol_range, flee_distance](AIEntity& e, const Position& player) {
        [[maybe_unused]] const auto pr = patrol_range;
        [[maybe_unused]] const auto fd = flee_distance;
        if (e.position().distance_to(player) <= flee_distance)
        {
			e.set_strategy(flee_strategy(fd));  // Cambia a flee se player troppo vicino
        }
        else
        {
			e.set_strategy(patrol_strategy(pr));  // Altrimenti patrol
        }
    };
}

// ============================================================================
// IMPLEMENTAZIONI AI MANAGER
// ============================================================================

void AIManager::add_entity([[maybe_unused]] std::unique_ptr<AIEntity> entity) {
	entities_.push_back(std::move(entity));
}

void AIManager::update_all([[maybe_unused]] const Position& player_pos) {
    for(const auto& entity : entities_) {
        entity->update(player_pos);
	}
}

void AIManager::remove_dead_entities() {
    // Suggerimento: usare std::remove_if + erase
    auto new_end = std::remove_if(entities_.begin(), entities_.end(),
		[](const std::unique_ptr<AIEntity>& e) 
        { 
            return !e->is_alive(); 
        });

	entities_.erase(new_end, entities_.end());
}

auto AIManager::get_entity_by_name([[maybe_unused]] const std::string& name) -> AIEntity* {
    // Suggerimento: usare std::find_if
	auto it = std::find_if(entities_.begin(), entities_.end(), 
        [name](const std::unique_ptr<AIEntity>& e) 
        { 
            return e->name() == name; 
		});

    if(it != entities_.end()) 
    {
        AIEntity* result = it->get();
	}
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
    // Passi:
    // 1) dx = target.x - current.x, dy = target.y - current.y
	float xDistance = target.x - current.x;
	float yDistance = target.y - current.y;
    // 2) distanza = sqrt(dx*dx + dy*dy)
	float distance = std::sqrt(xDistance * xDistance + yDistance * yDistance);
    // 3) se distanza < 0.5f -> return true (gia' arrivato)
    if(distance < 0.5f)
    {
        return true;
	}
    // 4) altrimenti normalizza: dir = (dx/distanza, dy/distanza)
	Position dir = { xDistance / distance, yDistance / distance };
    // 5) aggiorna current: current += dir * speed
	current.x += dir.x * speed;
	current.y += dir.y * speed;
    // 6) return false    
    return false;  
}

void move_away_from([[maybe_unused]] Position& current,
                    [[maybe_unused]] const Position& target,
                    [[maybe_unused]] float speed) {
    // Passi:
    // 1) dx = current.x - target.x, dy = current.y - target.y
    float xDistance = current.x - target.x;
    float yDistance = current.y - target.y;
    // 2) distanza = sqrt(dx*dx + dy*dy)
    float distance = std::sqrt(xDistance * xDistance + yDistance * yDistance);
    // 3) se distanza > epsilon: current += (dx/distanza, dy/distanza) * speed
    if (distance < 0.1f)
    {
        return;
    }
    Position dir = { xDistance / distance, yDistance / distance };
    current.x += dir.x * speed;
    current.y += dir.y * speed;
    // Nota: e' l'opposto di move_towards, che usa (target - current).
}

} // namespace rpg::ai
