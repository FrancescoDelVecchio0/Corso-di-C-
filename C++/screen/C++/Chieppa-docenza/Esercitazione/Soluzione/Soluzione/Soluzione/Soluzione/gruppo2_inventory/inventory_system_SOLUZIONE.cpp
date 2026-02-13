#include "../gruppo2_inventory/inventory_system.hpp"
#include <iostream>
#include <algorithm>
#include <numeric>

namespace rpg::inventory {

// ============================================================================
// SOLUZIONI CHIAVE GRUPPO 2
// ============================================================================

// ============================================================================
// COSTRUTTORI MANCANTI
// ============================================================================

// Costruttore Weapon
Weapon::Weapon(std::string name, std::string description, int value, int attack_bonus)
    : Item(std::move(name), std::move(description), ItemType::weapon, value)
    , attack_bonus_(attack_bonus)
{}

// Costruttore Potion
Potion::Potion(std::string name, std::string description, int value, int heal_amount)
    : Item(std::move(name), std::move(description), ItemType::potion, value)
    , heal_amount_(heal_amount)
{}

// Costruttore KeyItem
KeyItem::KeyItem(std::string name, std::string description)
    : Item(std::move(name), std::move(description), ItemType::key_item, 0)
{}

// Costruttore Inventory
Inventory::Inventory(int max_capacity, int starting_gold)
    : max_capacity_(max_capacity)
    , gold_(starting_gold)
{}

// ============================================================================
// METODI GET_INFO
// ============================================================================

// Item::get_info (base)
auto Item::get_info() const -> std::string {
    return name_ + " - " + description_;
}

// Weapon::get_info
auto Weapon::get_info() const -> std::string {
    return name_ + " (Weapon) - " + description_ + " [ATK+" + std::to_string(attack_bonus_) + "]";
}

// Potion::get_info
auto Potion::get_info() const -> std::string {
    return name_ + " (Potion) - " + description_ + " [Heal:" + std::to_string(heal_amount_) + "]";
}

// KeyItem::get_info
auto KeyItem::get_info() const -> std::string {
    return name_ + " (Key Item) - " + description_;
}

// KeyItem::use
void KeyItem::use() {
    std::cout << "Examined " << name_ << ": " << description_ << "\n";
}

// ============================================================================
// METODI USE
// ============================================================================

// Weapon::use()
void Weapon::use() {
    std::cout << "Equipped " << name_ << "! Attack bonus: +" << attack_bonus_ << "\n";
}

// Potion::use()
void Potion::use() {
    std::cout << "Used " << name_ << "! Restored " << heal_amount_ << " HP\n";
}

// Inventory::add_item
auto Inventory::add_item(std::shared_ptr<Item> item) -> bool {
    if (items_.size() >= static_cast<size_t>(max_capacity_)) {
        std::cout << "Inventory full! Cannot add " << item->name() << "\n";
        return false;
    }
    items_.push_back(std::move(item));
    return true;
}

// Inventory::remove_item
auto Inventory::remove_item(const std::string& item_name) -> bool {
    auto it = std::remove_if(items_.begin(), items_.end(),
        [&item_name](const auto& item) {
            return item->name() == item_name;
        });
    
    if (it != items_.end()) {
        items_.erase(it, items_.end());
        return true;
    }
    return false;
}

// Inventory::find_item
auto Inventory::find_item(const std::string& item_name) -> std::optional<std::shared_ptr<Item>> {
    auto it = std::find_if(items_.begin(), items_.end(),
        [&item_name](const auto& item) {
            return item->name() == item_name;
        });
    
    if (it != items_.end()) {
        return *it;
    }
    return std::nullopt;
}

// Inventory::use_item
auto Inventory::use_item(const std::string& item_name) -> bool {
    auto item_opt = find_item(item_name);
    if (!item_opt) {
        std::cout << "Item not found: " << item_name << "\n";
        return false;
    }
    
    auto item = *item_opt;
    item->use();
    
    // Rimuovi item solo se non è KeyItem
    if (item->type() != ItemType::key_item) {
        [[maybe_unused]] const auto removed = remove_item(item_name);
    }
    
    return true;
}

// Inventory::get_items_by_type
auto Inventory::get_items_by_type(ItemType type) const -> std::vector<std::shared_ptr<Item>> {
    std::vector<std::shared_ptr<Item>> result;
    std::copy_if(items_.begin(), items_.end(), std::back_inserter(result),
        [type](const auto& item) {
            return item->type() == type;
        });
    return result;
}

// Inventory::calculate_total_value
auto Inventory::calculate_total_value() const -> int {
    return std::accumulate(items_.begin(), items_.end(), 0,
        [](int sum, const auto& item) {
            return sum + item->value();
        });
}

// Inventory::list_items
void Inventory::list_items() const {
    std::cout << "Inventory (" << items_.size() << "/" << max_capacity_ << "):\n";
    if (items_.empty()) {
        std::cout << "  (empty)\n";
        return;
    }
    
    int index = 1;
    for (const auto& item : items_) {
        std::cout << "  " << index++ << ". " << item->get_info() << "\n";
    }
}

// create_common_item factory
auto create_common_item(const std::string& item_name) -> std::shared_ptr<Item> {
    if (item_name == "health_potion") {
        return std::make_shared<Potion>("Health Potion", "Restores 50 HP", 20, 50);
    }
    else if (item_name == "iron_sword") {
        return std::make_shared<Weapon>("Iron Sword", "A sturdy iron blade", 100, 5);
    }
    else if (item_name == "ancient_key") {
        return std::make_shared<KeyItem>("Ancient Key", "Opens the temple door");
    }
    else if (item_name == "mana_potion") {
        return std::make_shared<Potion>("Mana Potion", "Restores 30 MP", 15, 30);
    }
    else if (item_name == "steel_armor") {
        // Nota: dovremmo avere una classe Armor, ma semplifichiamo
        return std::make_shared<Weapon>("Steel Armor", "Heavy protection", 200, 0);
    }
    
    return nullptr;
}

} // namespace rpg::inventory
