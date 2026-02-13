#pragma once

#include "../common/types.hpp"
#include <memory>
#include <vector>
#include <optional>
#include <string>

// ============================================================================
// GRUPPO 2: SISTEMA DI INVENTARIO
// ============================================================================
//
// OBIETTIVO: Gestire oggetti con smart pointers e STL containers
//
// TODO:
// 1. Implementare la classe Item e sue derivate
// 2. Implementare la classe Inventory usando smart pointers
// 3. Usare std::vector, std::find_if, algoritmi STL
// 4. Implementare add, remove, find con optional
//
// TEMPO: 60 minuti
// ============================================================================

namespace rpg::inventory {

// ----------------------------------------------------------------------------
// CLASSE BASE ITEM
// ----------------------------------------------------------------------------
class Item {
protected:
    std::string name_;
    std::string description_;
    ItemType type_;
    int value_{0};  // Valore in oro

public:
    Item(std::string name, std::string description, ItemType type, int value)
        : name_(std::move(name))
        , description_(std::move(description))
        , type_(type)
        , value_(value)
    {}
    
    virtual ~Item() = default;
    
    // Metodo virtuale puro: ogni tipo di item ha un effetto diverso
    virtual void use() = 0;
    
    // Getters
    [[nodiscard]] auto name() const noexcept -> const std::string& { return name_; }
    [[nodiscard]] auto description() const noexcept -> const std::string& { return description_; }
    [[nodiscard]] auto type() const noexcept -> ItemType { return type_; }
    [[nodiscard]] auto value() const noexcept -> int { return value_; }
    
    [[nodiscard]] virtual auto get_info() const -> std::string;
};

// ----------------------------------------------------------------------------
// WEAPON - Arma
// ----------------------------------------------------------------------------
class Weapon : public Item {
private:
    int attack_bonus_{0};

public:
    // TODO: Implementare costruttore
    // Armi hanno type = ItemType::weapon
    Weapon(std::string name, std::string description, int value, int attack_bonus);
    
    // TODO: Implementare use() override
    // Stampa messaggio che l'arma è stata equipaggiata
    void use() override;
    
    [[nodiscard]] auto attack_bonus() const noexcept -> int { return attack_bonus_; }
    [[nodiscard]] auto get_info() const -> std::string override;
};

// ----------------------------------------------------------------------------
// POTION - Pozione curativa
// ----------------------------------------------------------------------------
class Potion : public Item {
private:
    int heal_amount_{0};

public:
    // TODO: Implementare costruttore  
    // Pozioni hanno type = ItemType::potion
    Potion(std::string name, std::string description, int value, int heal_amount);
    
    // TODO: Implementare use() override
    // Stampa messaggio di cura
    void use() override;
    
    [[nodiscard]] auto heal_amount() const noexcept -> int { return heal_amount_; }
    [[nodiscard]] auto get_info() const -> std::string override;
};

// ----------------------------------------------------------------------------
// KEY_ITEM - Oggetto chiave (non vendibile)
// ----------------------------------------------------------------------------
class KeyItem : public Item {
public:
    // TODO: Implementare costruttore
    // KeyItem hanno type = ItemType::key_item e value = 0
    KeyItem(std::string name, std::string description);
    
    // TODO: Implementare use() override
    // Stampa messaggio descrittivo
    void use() override;
    
    [[nodiscard]] auto get_info() const -> std::string override;
};

// ----------------------------------------------------------------------------
// INVENTORY - Gestione inventario
// ----------------------------------------------------------------------------
class Inventory {
private:
    std::vector<std::shared_ptr<Item>> items_;
    int max_capacity_{20};
    int gold_{100};  // Oro del giocatore

public:
    explicit Inventory(int max_capacity = 20, int starting_gold = 100);
    
    // TODO: Implementare add_item
    // Aggiunge item se c'è spazio, ritorna true se successo
    [[nodiscard]] auto add_item(std::shared_ptr<Item> item) -> bool;
    
    // TODO: Implementare remove_item
    // Rimuove item per nome, ritorna true se trovato e rimosso
    [[nodiscard]] auto remove_item(const std::string& item_name) -> bool;
    
    // TODO: Implementare find_item
    // Cerca item per nome, ritorna optional<shared_ptr<Item>>
    [[nodiscard]] auto find_item(const std::string& item_name) -> std::optional<std::shared_ptr<Item>>;
    
    // TODO: Implementare use_item
    // Usa e rimuove l'item (tranne KeyItem che rimangono)
    [[nodiscard]] auto use_item(const std::string& item_name) -> bool;
    
    // TODO: Implementare get_items_by_type
    // Ritorna vector di item del tipo specificato
    [[nodiscard]] auto get_items_by_type(ItemType type) const -> std::vector<std::shared_ptr<Item>>;
    
    // TODO: Implementare list_items
    // Stampa tutti gli item nell'inventario
    void list_items() const;
    
    // TODO: Implementare calculate_total_value
    // Calcola valore totale di tutti gli item
    [[nodiscard]] auto calculate_total_value() const -> int;
    
    // Getters/Setters
    [[nodiscard]] auto size() const noexcept -> size_t { return items_.size(); }
    [[nodiscard]] auto capacity() const noexcept -> int { return max_capacity_; }
    [[nodiscard]] auto gold() const noexcept -> int { return gold_; }
    void add_gold(int amount) noexcept { gold_ += amount; }
    void spend_gold(int amount) noexcept { gold_ = std::max(0, gold_ - amount); }
};

// ----------------------------------------------------------------------------
// FUNZIONI UTILITY
// ----------------------------------------------------------------------------

// TODO: Implementare funzione per creare item comuni
// Factory che crea item predefiniti
auto create_common_item(const std::string& item_name) -> std::shared_ptr<Item>;

} // namespace rpg::inventory
