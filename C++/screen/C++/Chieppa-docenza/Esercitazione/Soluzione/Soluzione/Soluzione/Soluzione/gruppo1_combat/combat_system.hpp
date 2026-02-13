#pragma once

#include "../common/types.hpp"
#include <memory>
#include <vector>

// ============================================================================
// GRUPPO 1: SISTEMA DI COMBATTIMENTO
// ============================================================================
//
// OBIETTIVO: Implementare un sistema di combattimento con polimorfismo
//
// TODO:
// 1. Completare le classi Player e Enemy che ereditano da Entity
// 2. Implementare i metodi attack() con logica diversa per ogni tipo
// 3. Implementare get_description() per ogni classe
// 4. Usare smart pointer (unique_ptr/shared_ptr) dove appropriato
//
// TEMPO: 60 minuti
// ============================================================================

namespace rpg::combat {

// ----------------------------------------------------------------------------
// CLASSE PLAYER
// ----------------------------------------------------------------------------
class Player : public Entity {
private:
    int attack_power_{10};
    int defense_{5};

public:
    // TODO: Implementare costruttore
    // Il player inizia con 100 HP, attack_power=10, defense=5
    Player(const std::string& name);
    
    // TODO: Implementare metodo attack
    // Ritorna il danno inflitto (attack_power_ + valore casuale tra 0-5)
    [[nodiscard]] auto attack() const noexcept -> int;
    
    // TODO: Implementare metodo per calcolare danno ricevuto
    // Il danno ricevuto è ridotto dalla defense (minimo 1 danno)
    [[nodiscard]] auto calculate_damage_taken(int incoming_damage) const noexcept -> int;
    
    // TODO: Implementare get_description (override)
    [[nodiscard]] auto get_description() const -> std::string override;
    
    // Getters
    [[nodiscard]] auto attack_power() const noexcept -> int { return attack_power_; }
    [[nodiscard]] auto defense() const noexcept -> int { return defense_; }
    
    // Setters per power-ups
    void increase_attack(int amount) noexcept { attack_power_ += amount; }
    void increase_defense(int amount) noexcept { defense_ += amount; }
};

// ----------------------------------------------------------------------------
// CLASSE BASE ENEMY
// ----------------------------------------------------------------------------
class Enemy : public Entity {
protected:
    int attack_power_{5};
    
public:
    Enemy(const std::string& name, int health, int attack_power)
        : Entity(name, health, EntityType::enemy)
        , attack_power_(attack_power)
    {}
    
    virtual ~Enemy() = default;
    
    // TODO: Rendere questo metodo virtuale puro (= 0)
    // Ogni tipo di nemico avrà un attacco diverso
    [[nodiscard]] virtual auto attack() const noexcept -> int = 0;
    
    [[nodiscard]] auto attack_power() const noexcept -> int { return attack_power_; }
};

// ----------------------------------------------------------------------------
// NEMICO: GOBLIN (attacco debole ma veloce)
// ----------------------------------------------------------------------------
class Goblin : public Enemy {
public:
    // TODO: Implementare costruttore
    // Goblin: 30 HP, attacco 5
    Goblin();
    
    // TODO: Implementare attack() override
    // Attacco: attack_power + valore casuale 0-3
    [[nodiscard]] auto attack() const noexcept -> int override;
    
    // TODO: Implementare get_description override
    [[nodiscard]] auto get_description() const -> std::string override;
};

// ----------------------------------------------------------------------------
// NEMICO: ORC (attacco forte ma lento)
// ----------------------------------------------------------------------------
class Orc : public Enemy {
public:
    // TODO: Implementare costruttore
    // Orc: 50 HP, attacco 15
    Orc();
    
    // TODO: Implementare attack() override
    // Attacco: attack_power + valore casuale 0-10
    [[nodiscard]] auto attack() const noexcept -> int override;
    
    // TODO: Implementare get_description override
    [[nodiscard]] auto get_description() const -> std::string override;
};

// ----------------------------------------------------------------------------
// BOSS: DRAGON (molto forte)
// ----------------------------------------------------------------------------
class Dragon : public Enemy {
public:
    // TODO: Implementare costruttore
    // Dragon: 100 HP, attacco 25
    Dragon();
    
    // TODO: Implementare attack() override
    // Attacco: attack_power + valore casuale 0-15
    [[nodiscard]] auto attack() const noexcept -> int override;
    
    // TODO: Implementare get_description override  
    [[nodiscard]] auto get_description() const -> std::string override;
};

// ----------------------------------------------------------------------------
// FUNZIONI UTILITY
// ----------------------------------------------------------------------------

// TODO: Implementare funzione che esegue un turno di combattimento
// Parametri: player attacca enemy, enemy contrattacca se vivo
// Stampa il log del combattimento
void execute_combat_turn(Player& player, Enemy& enemy);

// TODO: Implementare factory per creare nemici
// Ritorna unique_ptr<Enemy> del tipo specificato
auto create_enemy(const std::string& enemy_type) -> std::unique_ptr<Enemy>;

} // namespace rpg::combat
