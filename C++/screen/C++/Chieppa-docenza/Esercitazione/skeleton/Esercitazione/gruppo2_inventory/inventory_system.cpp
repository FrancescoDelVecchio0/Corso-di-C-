#include "inventory_system.hpp"
#include <iostream>
#include <algorithm>
#include <numeric>

namespace rpg::inventory {

// ============================================================================
// IMPLEMENTAZIONI ITEM BASE
// ============================================================================

auto Item::get_info() const -> std::string {
    return name_ + " - " + description_ + " (Value: " + std::to_string(value_) + " gold)";
}

// ============================================================================
// IMPLEMENTAZIONI WEAPON
// ============================================================================

Weapon::Weapon(std::string name, std::string description, int value, int attack_bonus)
    : Item(std::move(name), std::move(description), ItemType::weapon, value)
    , attack_bonus_(attack_bonus)
{
}

void Weapon::use() {
    // TODO: Stampare messaggio di equipaggiamento
    // Es: "Equipped [nome arma]! Attack bonus: +[bonus]"
}

auto Weapon::get_info() const -> std::string {
    // TODO: Ritornare info completa con attack bonus
    return "";  // PLACEHOLDER
}

// ============================================================================
// IMPLEMENTAZIONI POTION
// ============================================================================

Potion::Potion(std::string name, std::string description, int value, int heal_amount)
    : Item(std::move(name), std::move(description), ItemType::potion, value)
    , heal_amount_(heal_amount)
{
}

void Potion::use() {
    // TODO: Stampare messaggio di cura
    // Es: "Used [nome pozione]! Restored [heal_amount] HP"
}

auto Potion::get_info() const -> std::string {
    // TODO: Ritornare info completa con heal amount
    return "";  // PLACEHOLDER
}

// ============================================================================
// IMPLEMENTAZIONI KEY_ITEM
// ============================================================================

KeyItem::KeyItem(std::string name, std::string description)
    : Item(std::move(name), std::move(description), ItemType::key_item, 0)
{
}

void KeyItem::use() {
    // TODO: Stampare messaggio descrittivo
    // Es: "Examined [nome]: [description]"
}

auto KeyItem::get_info() const -> std::string {
    // TODO: Ritornare info (key item non hanno valore)
    return "";  // PLACEHOLDER
}

// ============================================================================
// IMPLEMENTAZIONI INVENTORY
// ============================================================================

Inventory::Inventory(int max_capacity, int starting_gold)
    : max_capacity_(max_capacity)
    , gold_(starting_gold)
{
}

auto Inventory::add_item([[maybe_unused]] std::shared_ptr<Item> item) -> bool {
    // TODO: Controllare capacità e aggiungere item
    // Suggerimento: controllare items_.size() < max_capacity_
    return false;  // PLACEHOLDER
}

auto Inventory::remove_item([[maybe_unused]] const std::string& item_name) -> bool {
    // TODO: Trovare e rimuovere item per nome
    // Suggerimento: usare std::remove_if e items_.erase()
    return false;  // PLACEHOLDER
}

auto Inventory::find_item([[maybe_unused]] const std::string& item_name) -> std::optional<std::shared_ptr<Item>> {
    // TODO: Cercare item per nome
    // Suggerimento: usare std::find_if
    return std::nullopt;  // PLACEHOLDER
}

auto Inventory::use_item([[maybe_unused]] const std::string& item_name) -> bool {
    // TODO: Trovare item, chiamare use(), rimuoverlo se non è KeyItem
    // Ritornare true se item trovato e usato
    return false;  // PLACEHOLDER
}

auto Inventory::get_items_by_type([[maybe_unused]] ItemType type) const -> std::vector<std::shared_ptr<Item>> {
    // TODO: Filtrare items per tipo
    // Suggerimento: usare std::copy_if con back_inserter
    std::vector<std::shared_ptr<Item>> result;
    return result;  // PLACEHOLDER
}

void Inventory::list_items() const {
    // TODO: Stampare tutti gli item
    // Formato: "Inventory (3/20):"
    //          "1. [info item]"
    std::cout << "Inventory (" << items_.size() << "/" << max_capacity_ << "):\n";
    // ... completare
}

auto Inventory::calculate_total_value() const -> int {
    // TODO: Sommare valore di tutti gli item
    // Suggerimento: usare std::accumulate con lambda
    return 0;  // PLACEHOLDER
}

// ============================================================================
// FUNZIONI UTILITY
// ============================================================================

auto create_common_item(const std::string& item_name) -> std::shared_ptr<Item> {
    // TODO: Factory per creare item comuni
    // Implementare almeno: "health_potion", "iron_sword", "ancient_key"
    
    if (item_name == "health_potion") {
        // return std::make_shared<Potion>(...);
    }
    
    return nullptr;  // PLACEHOLDER
}

} // namespace rpg::inventory
