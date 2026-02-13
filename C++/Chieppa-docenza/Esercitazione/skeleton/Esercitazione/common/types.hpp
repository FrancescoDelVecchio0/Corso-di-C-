#pragma once

#include <string>
#include <memory>
#include <vector>

// ============================================================================
// TIPI COMUNI - UTILIZZATI DA TUTTI I GRUPPI
// ============================================================================

namespace rpg {

// Enumerazioni base
enum class ItemType {
    weapon,
    potion,
    armor,
    key_item
};

enum class EntityType {
    player,
    enemy,
    npc
};

// Struct per rappresentare una posizione nel mondo
struct Position {
    float x{0.0f};
    float y{0.0f};
    
    [[nodiscard]] auto distance_to(const Position& other) const noexcept -> float;
};

// Classe base per tutte le entità del gioco
class Entity {
protected:
    std::string name_;
    int health_{100};
    int max_health_{100};
    Position position_;
    EntityType type_;

public:
    Entity(std::string name, int health, EntityType type)
        : name_(std::move(name))
        , health_(health)
        , max_health_(health)
        , type_(type)
    {}
    
    virtual ~Entity() = default;
    
    // Getters
    [[nodiscard]] auto name() const noexcept -> const std::string& { return name_; }
    [[nodiscard]] auto health() const noexcept -> int { return health_; }
    [[nodiscard]] auto max_health() const noexcept -> int { return max_health_; }
    [[nodiscard]] auto position() const noexcept -> const Position& { return position_; }
    [[nodiscard]] auto type() const noexcept -> EntityType { return type_; }
    [[nodiscard]] auto is_alive() const noexcept -> bool { return health_ > 0; }
    
    // Setters
    void set_position(const Position& pos) noexcept { position_ = pos; }
    void take_damage(int amount) noexcept { 
        health_ = std::max(0, health_ - amount); 
    }
    void heal(int amount) noexcept { 
        health_ = std::min(max_health_, health_ + amount); 
    }
    
    // Metodi virtuali per polimorfismo
    [[nodiscard]] virtual auto get_description() const -> std::string = 0;
};

} // namespace rpg
