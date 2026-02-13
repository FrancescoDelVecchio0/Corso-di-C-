#pragma once

#include <functional>
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>

// ============================================================================
// GRUPPO 3: SISTEMA DI EVENTI
// ============================================================================
//
// OBIETTIVO: Implementare observer pattern con lambda e functional
//
// TODO:
// 1. Implementare EventManager con pattern Observer
// 2. Usare std::function e lambda per callbacks
// 3. Gestire registrazione/cancellazione observers
// 4. Implementare eventi predefiniti del gioco
//
// TEMPO: 60 minuti
// ============================================================================

namespace rpg::events {

// Tipi di eventi del gioco
enum class EventType {
    enemy_defeated,
    player_level_up,
    item_collected,
    boss_spawned,
    quest_completed,
    player_death
};

// Struttura dati evento
struct EventData {
    EventType type;
    std::string message;
    int value{0};  // Valore generico (XP, gold, etc.)
    
    EventData(EventType t, std::string msg, int val = 0)
        : type(t), message(std::move(msg)), value(val)
    {}
};

// Tipo per callback degli observers
using EventCallback = std::function<void(const EventData&)>;

// ----------------------------------------------------------------------------
// EVENT MANAGER - Pattern Observer
// ----------------------------------------------------------------------------
class EventManager {
private:
    // TODO: Definire struttura dati per memorizzare observers
    // Suggerimento: std::unordered_map<EventType, std::vector<...>>
    // Ogni EventType ha una lista di callback
    
    int next_observer_id_{0};
    
public:
    EventManager() = default;
    
    // TODO: Implementare subscribe
    // Registra un observer per un tipo di evento
    // Ritorna un ID univoco per poter fare unsubscribe dopo
    [[nodiscard]] auto subscribe(EventType event_type, EventCallback callback) -> int;
    
    // TODO: Implementare unsubscribe
    // Rimuove un observer tramite ID
    void unsubscribe(int observer_id);
    
    // TODO: Implementare emit
    // Notifica tutti gli observer di un evento
    void emit(const EventData& event);
    
    // TODO: Implementare clear_all
    // Rimuove tutti gli observer
    void clear_all();
    
    // Utility per debugging
    void print_stats() const;
};

// ----------------------------------------------------------------------------
// GAME EVENT HANDLERS - Observers predefiniti
// ----------------------------------------------------------------------------

// TODO: Implementare funzione che crea un logger observer
// Questo observer stampa tutti gli eventi
auto create_logger_observer() -> EventCallback;

// TODO: Implementare la classe StatsTracker come observer
// Tiene traccia delle statistiche (nemici uccisi, etc.) tramite get_callback()
class StatsTracker {
private:
    int enemies_defeated_{0};
    int items_collected_{0};
    int total_xp_earned_{0};
    
public:
    // TODO: Implementare metodo che ritorna callback
    [[nodiscard]] auto get_callback() -> EventCallback;
    
    // Getters per stats
    [[nodiscard]] auto enemies_defeated() const noexcept -> int { return enemies_defeated_; }
    [[nodiscard]] auto items_collected() const noexcept -> int { return items_collected_; }
    [[nodiscard]] auto total_xp_earned() const noexcept -> int { return total_xp_earned_; }
    
    void print_stats() const;
};

// TODO: Implementare la classe AchievementSystem come observer
// Controlla condizioni per achievement tramite get_callback()
// Es: "Defeat 10 enemies" -> stampa "Achievement Unlocked!"
class AchievementSystem {
private:
    int enemy_kill_count_{0};
    bool first_boss_killed_{false};
    bool collector_achievement_{false};  // Raccogli 20 item
    
public:
    // TODO: Implementare get_callback che controlla achievement
    [[nodiscard]] auto get_callback() -> EventCallback;
    
    void print_achievements() const;
};

// ----------------------------------------------------------------------------
// UTILITY FUNCTIONS
// ----------------------------------------------------------------------------

// TODO: Implementare funzione helper per convertire EventType in stringa
[[nodiscard]] auto event_type_to_string(EventType type) -> std::string;

} // namespace rpg::events
