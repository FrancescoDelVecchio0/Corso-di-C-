#pragma once

#include "../common/types.hpp"
#include <functional>
#include <memory>
#include <string>

// ============================================================================
// GRUPPO 4: SISTEMA DI AI (STRATEGY PATTERN)
// ============================================================================
//
// OBIETTIVO: Implementare comportamenti AI con Strategy pattern e lambda
//
// TODO:
// 1. Implementare Strategy pattern per comportamenti AI
// 2. Usare std::function per strategies intercambiabili
// 3. Implementare strategie diverse (idle, patrol, chase, flee, aggressive, defensive)
// 4. Permettere cambio di strategia a runtime
//
// TEMPO: 60 minuti
// ============================================================================

namespace rpg::ai {

// Forward declaration
class AIEntity;

// Tipo per la strategia AI: prende AIEntity e posizione del player
using AIStrategy = std::function<void(AIEntity&, const Position& player_pos)>;

// ----------------------------------------------------------------------------
// AI ENTITY - Entità con AI intercambiabile
// ----------------------------------------------------------------------------
class AIEntity {
private:
    std::string name_;
    Position position_;
    Position spawn_position_;  // Punto di partenza per patrol
    float speed_{1.0f};
    int health_{50};
    
    AIStrategy current_strategy_;
    
    // Per pattern patrol
    bool moving_forward_{true};
    float patrol_distance_{10.0f};

public:
    AIEntity(std::string name, const Position& pos, float speed = 1.0f)
        : name_(std::move(name))
        , position_(pos)
        , spawn_position_(pos)
        , speed_(speed)
    {}
    
    // Cambia la strategia corrente
    void set_strategy(AIStrategy strategy);
    
    // Esegue la strategia corrente passando this e player_pos
    void update(const Position& player_pos);
    
    // Getters/Setters
    [[nodiscard]] auto name() const noexcept -> const std::string& { return name_; }
    [[nodiscard]] auto position() const noexcept -> const Position& { return position_; }
    [[nodiscard]] auto spawn_position() const noexcept -> const Position& { return spawn_position_; }
    [[nodiscard]] auto health() const noexcept -> int { return health_; }
    [[nodiscard]] auto speed() const noexcept -> float { return speed_; }
    
    void set_position(const Position& pos) noexcept { position_ = pos; }
    void take_damage(int amount) noexcept { health_ = std::max(0, health_ - amount); }
    [[nodiscard]] auto is_alive() const noexcept -> bool { return health_ > 0; }
    
    // Per patrol strategy
    [[nodiscard]] auto is_moving_forward() const noexcept -> bool { return moving_forward_; }
    void toggle_direction() noexcept { moving_forward_ = !moving_forward_; }
    [[nodiscard]] auto patrol_distance() const noexcept -> float { return patrol_distance_; }
};

// ----------------------------------------------------------------------------
// STRATEGIE PREDEFINITE
// ----------------------------------------------------------------------------

// L'entità non fa nulla
[[nodiscard]] auto idle_strategy() -> AIStrategy;

// L'entità si muove avanti/indietro dal punto di spawn
// Parametri: patrol_range (distanza massima dal spawn)
[[nodiscard]] auto patrol_strategy(float patrol_range) -> AIStrategy;

// L'entità insegue il player se è entro detection_range
// Parametri: detection_range, chase_speed_multiplier
[[nodiscard]] auto chase_strategy(float detection_range, float speed_mult = 1.0f) -> AIStrategy;

// L'entità scappa dal player se è troppo vicino
// Parametri: flee_distance
[[nodiscard]] auto flee_strategy(float flee_distance) -> AIStrategy;

// Combina chase quando lontano, attacca quando vicino
// Parametri: chase_range, attack_range
[[nodiscard]] auto aggressive_strategy(float chase_range, float attack_range) -> AIStrategy;

// Combina patrol quando player lontano, flee quando vicino
// Parametri: patrol_range, flee_distance
[[nodiscard]] auto defensive_strategy(float patrol_range, float flee_distance) -> AIStrategy;

// ----------------------------------------------------------------------------
// AI MANAGER - Gestisce multiple entità
// ----------------------------------------------------------------------------
class AIManager {
private:
    std::vector<std::unique_ptr<AIEntity>> entities_;
    
public:
    AIManager() = default;
    
    // Aggiunge nuova entità AI
    void add_entity(std::unique_ptr<AIEntity> entity);
    
    // Aggiorna tutte le entità passando player_pos
    void update_all(const Position& player_pos);
    
    // Rimuove entità con health <= 0
    void remove_dead_entities();
    
    // Trova entità per nome
    [[nodiscard]] auto get_entity_by_name(const std::string& name) -> AIEntity*;
    
    // Utility
    [[nodiscard]] auto entity_count() const noexcept -> size_t { return entities_.size(); }
    void print_all_positions() const;
};

// ----------------------------------------------------------------------------
// UTILITY FUNCTIONS
// ----------------------------------------------------------------------------

// Idea pratica:
// 1) calcola il vettore verso il target: (target - current)
// 2) calcola la distanza con sqrt(dx*dx + dy*dy)
// 3) se distanza < soglia (es. 0.5f), ritorna true (arrivato)
// 4) altrimenti normalizza il vettore (dx/distanza, dy/distanza)
// 5) aggiorna current aggiungendo direzione_normalizzata * speed
// Ritorna true se arrivato, altrimenti false.
[[nodiscard]] auto move_towards(Position& current, const Position& target, float speed) -> bool;

// Idea pratica:
// 1) calcola il vettore opposto rispetto a move_towards: (current - target)
// 2) normalizza il vettore (dividi per la distanza)
// 3) aggiorna current con quella direzione * speed
// Se distanza ~0, non muovere per evitare divisione per zero.
void move_away_from(Position& current, const Position& target, float speed);

} // namespace rpg::ai
