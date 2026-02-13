#include "../gruppo1_combat/combat_system.hpp"
#include <iostream>
#include <random>

namespace rpg::combat {

// Utility per generare numeri casuali
namespace {
    auto random_int(int min, int max) -> int {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(min, max);
        return dis(gen);
    }
}

// ============================================================================
// SOLUZIONE PLAYER
// ============================================================================

Player::Player(const std::string& name) 
    : Entity(name, 100, EntityType::player)
    , attack_power_(10)
    , defense_(5)
{
}

auto Player::attack() const noexcept -> int {
    return attack_power_ + random_int(0, 5);
}

auto Player::calculate_damage_taken(int incoming_damage) const noexcept -> int {
    const int reduced_damage = incoming_damage - defense_;
    return std::max(1, reduced_damage);
}

auto Player::get_description() const -> std::string {
    return "Player: " + name_ + 
           " (HP: " + std::to_string(health_) + "/" + std::to_string(max_health_) + 
           ", ATK: " + std::to_string(attack_power_) + 
           ", DEF: " + std::to_string(defense_) + ")";
}

// ============================================================================
// SOLUZIONE GOBLIN
// ============================================================================

Goblin::Goblin() 
    : Enemy("Goblin", 30, 5)
{
}

auto Goblin::attack() const noexcept -> int {
    return attack_power_ + random_int(0, 3);
}

auto Goblin::get_description() const -> std::string {
    return "Goblin (HP: " + std::to_string(health_) + "/" + std::to_string(max_health_) + 
           ", ATK: " + std::to_string(attack_power_) + ")";
}

// ============================================================================
// SOLUZIONE ORC
// ============================================================================

Orc::Orc() 
    : Enemy("Orc", 50, 15)
{
}

auto Orc::attack() const noexcept -> int {
    return attack_power_ + random_int(0, 10);
}

auto Orc::get_description() const -> std::string {
    return "Orc (HP: " + std::to_string(health_) + "/" + std::to_string(max_health_) + 
           ", ATK: " + std::to_string(attack_power_) + ")";
}

// ============================================================================
// SOLUZIONE DRAGON
// ============================================================================

Dragon::Dragon() 
    : Enemy("Dragon", 100, 25)
{
}

auto Dragon::attack() const noexcept -> int {
    return attack_power_ + random_int(0, 15);
}

auto Dragon::get_description() const -> std::string {
    return "Dragon (HP: " + std::to_string(health_) + "/" + std::to_string(max_health_) + 
           ", ATK: " + std::to_string(attack_power_) + ")";
}

// ============================================================================
// SOLUZIONE FUNZIONI UTILITY
// ============================================================================

void execute_combat_turn(Player& player, Enemy& enemy) {
    std::cout << "\n=== COMBAT TURN ===\n";
    std::cout << player.get_description() << "\n";
    std::cout << "vs\n";
    std::cout << enemy.get_description() << "\n\n";
    
    // Player attacca
    const int player_damage = player.attack();
    enemy.take_damage(player_damage);
    std::cout << player.name() << " attacks for " << player_damage << " damage!\n";
    std::cout << enemy.name() << " HP: " << enemy.health() << "/" << enemy.max_health() << "\n";
    
    // Se il nemico è ancora vivo, contrattacca
    if (enemy.is_alive()) {
        const int enemy_raw_damage = enemy.attack();
        const int actual_damage = player.calculate_damage_taken(enemy_raw_damage);
        player.take_damage(actual_damage);
        std::cout << "\n" << enemy.name() << " counterattacks for " << enemy_raw_damage 
                  << " damage (" << actual_damage << " after defense)!\n";
        std::cout << player.name() << " HP: " << player.health() << "/" << player.max_health() << "\n";
    } else {
        std::cout << "\n" << enemy.name() << " defeated!\n";
    }
}

auto create_enemy(const std::string& enemy_type) -> std::unique_ptr<Enemy> {
    if (enemy_type == "goblin") {
        return std::make_unique<Goblin>();
    }
    else if (enemy_type == "orc") {
        return std::make_unique<Orc>();
    }
    else if (enemy_type == "dragon") {
        return std::make_unique<Dragon>();
    }
    
    // Default: ritorna goblin se tipo sconosciuto
    return std::make_unique<Goblin>();
}

} // namespace rpg::combat
