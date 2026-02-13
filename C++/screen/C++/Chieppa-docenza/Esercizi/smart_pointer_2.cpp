#include <iostream>
#include <memory>
#include <string>
#include <string_view>

// ============================================================================
// SOLUZIONE: Osservatori di Nemici con weak_ptr
// ============================================================================
//
// CONCETTO SEMPLICE:
//   - Nemico è un oggetto nel gioco (shared_ptr lo mantiene in vita)
//   - Telecamere osservano il nemico (weak_ptr osserva senza possedere)
//   - Quando nemico muore, il weak_ptr diventa invalido
//   - Telecamere vedono che non c'è più nessuno
//
// ANALOGIA PER GAMING:
//   Nemico = Mostro nel gioco
//   shared_ptr = Game Engine che lo controlla
//   weak_ptr = Telecamera di sorveglianza che lo guarda
//   
//   Se il Game Engine elimina il mostro, la telecamera vede uno schermo vuoto
//
// ============================================================================

// ============================================================================
// CLASSE: Nemico
// ============================================================================

class Nemico {
private:
    std::string nome_;
    int hp_;
    int x_, y_;

public:
    // PUNTO CHIAVE 1: Constructor con explicit
    explicit Nemico(std::string_view nome, int hp) noexcept
        : nome_(nome), hp_(hp), x_(0), y_(0) {
        std::cout << "[SPAWN] Nemico '" << nome_ << "' e' apparso!\n";
    }

    // PUNTO CHIAVE 2: Destructor stampa quando muore
    ~Nemico() noexcept {
        std::cout << "[DEATH] Nemico '" << nome_ << "' e' stato eliminato!\n";
    }

    // PUNTO CHIAVE 3: Deleted copy (un nemico non si copia)
    Nemico(const Nemico&) = delete;
    Nemico& operator=(const Nemico&) = delete;

    // Move è OK (per future estensioni)
    Nemico(Nemico&&) noexcept = default;
    Nemico& operator=(Nemico&&) noexcept = default;

    // Getter: nome
    [[nodiscard]] std::string_view getNome() const& noexcept {
        return nome_;
    }

    // Getter: HP
    [[nodiscard]] int getHP() const& noexcept {
        return hp_;
    }

    // Stampa informazioni del nemico
    void stampaInfo() const& noexcept {
        std::cout << "  [Nemico] Nome: " << nome_ << ", HP: " << hp_
                  << ", Pos: (" << x_ << ", " << y_ << ")\n";
    }

    // Nemico si muove
    void muovi(int dx, int dy) & noexcept {
        x_ += dx;
        y_ += dy;
        std::cout << "  [MOVE] " << nome_ << " si sposta a (" << x_ << ", " << y_ << ")\n";
    }

    // Nemico subisce danno
    void subisciDanno(int danno) & noexcept {
        hp_ -= danno;
        if (hp_ < 0) hp_ = 0;
        std::cout << "  [DAMAGE] " << nome_ << " subisce " << danno 
                  << " danni. HP rimasti: " << hp_ << "\n";
    }
};

// ============================================================================
// CLASSE: Telecamera (Osservatore con weak_ptr)
// ============================================================================

class Telecamera {
private:
    std::string id_;
    // PUNTO CHIAVE 4: weak_ptr per osservare senza possedere
    // Se il Nemico viene distrutto, questo weak_ptr diventa invalido
    // Ma la telecamera rimane
    std::weak_ptr<Nemico> nemico_osservato_;

public:
    // Constructor
    explicit Telecamera(std::string_view id) noexcept
        : id_(id) {
        std::cout << "[CAM ONLINE] Telecamera '" << id_ << "' e' online\n";
    }

    // Destructor
    ~Telecamera() noexcept {
        std::cout << "[CAM OFFLINE] Telecamera '" << id_ << "' e' offline\n";
    }

    // Deleted copy, defaulted move
    Telecamera(const Telecamera&) = delete;
    Telecamera& operator=(const Telecamera&) = delete;

    Telecamera(Telecamera&&) noexcept = default;
    Telecamera& operator=(Telecamera&&) noexcept = default;

    // ========================================================================
    // METODO PRINCIPALE: osserva()
    // ========================================================================
    //
    // Questo metodo salva un weak_ptr al nemico
    // IMPORTANTE: non fa una copia, solo salva una "vista"
    //
    // Come funziona:
    //   shared_ptr nemico_live → punta a Nemico (reference_count = 1)
    //   weak_ptr nemico_osservato_ = nemico_live → punta a Nemico
    //                                             (reference_count NON aumenta!)
    //
    void osserva(std::shared_ptr<Nemico> nemico) & noexcept {
        // PUNTO CHIAVE 5: Assegna il weak_ptr
        // nemico è un shared_ptr passato dal Game Manager
        // Quando assegniamo a weak_ptr, NON aumenta reference count
        nemico_osservato_ = nemico;
        
        if (nemico) {
            std::cout << "[CAM] Telecamera '" << id_ << "' osserva '"
                      << nemico->getNome() << "'\n";
        }
    }

    // ========================================================================
    // METODO PRINCIPALE: verificaStatoNemico()
    // ========================================================================
    //
    // Questo è il cuore della lezione su weak_ptr
    // 
    // weak_ptr.lock() converte il weak_ptr a shared_ptr
    // Se l'oggetto è ancora in vita: restituisce shared_ptr valido
    // Se è stato deallocato: restituisce nullptr
    //
    void verificaStatoNemico() const& noexcept {
        std::cout << "[CAM] Telecamera '" << id_ << "' verifica nemico: ";

        // PUNTO CHIAVE 6: lock() è la chiave
        // lock() tenta di "bloccare" il nemico e crearne una copia shared_ptr
        if (auto nemico_vivo = nemico_osservato_.lock()) {
            // Success! Il nemico è ancora vivo
            // nemico_vivo è un shared_ptr valido
            std::cout << "nemico trovato!\n";
            nemico_vivo->stampaInfo();
        } else {
            // Il nemico è stato deallocato
            // weak_ptr.lock() restituisce nullptr
            std::cout << "nemico scomparso!\n";
        }
    }

    // Metodo: Smetti di osservare
    void smettiDiOsservare() & noexcept {
        // PUNTO CHIAVE 7: Azzera il weak_ptr
        // std::weak_ptr<T>() crea un weak_ptr vuoto
        nemico_osservato_ = std::weak_ptr<Nemico>();
        std::cout << "[CAM] Telecamera '" << id_ << "' ha smesso di osservare\n";
    }
};

// ============================================================================
// DEMO COMPLETA
// ============================================================================

void demo() noexcept {
    std::cout << "\n" << std::string(70, '=') << "\n";
    std::cout << "ESERCIZIO: Osservatori di Nemici con weak_ptr\n";
    std::cout << std::string(70, '=') << "\n\n";

    // STEP 1: Crea il nemico (shared_ptr = Game Engine possiede)
    std::cout << "--- STEP 1: Crea il nemico ---\n";
    auto nemico_live = std::make_shared<Nemico>("Goblin", 50);
    nemico_live->stampaInfo();
    std::cout << "\n";

    // STEP 2: Crea telecamere
    std::cout << "--- STEP 2: Crea telecamere ---\n";
    Telecamera cam1("CAM_1");
    Telecamera cam2("CAM_2");
    Telecamera cam3("CAM_3");
    std::cout << "\n";

    // STEP 3: Telecamere osservano il nemico
    std::cout << "--- STEP 3: Telecamere osservano il nemico ---\n";
    cam1.osserva(nemico_live);
    cam2.osserva(nemico_live);
    cam3.osserva(nemico_live);
    
    std::cout << "\nMemory state:\n";
    std::cout << "  shared_ptr (Game Engine) → Nemico (reference_count = 1)\n";
    std::cout << "  weak_ptr (CAM_1)         → Nemico (NON conta nel ref_count)\n";
    std::cout << "  weak_ptr (CAM_2)         → Nemico (NON conta nel ref_count)\n";
    std::cout << "  weak_ptr (CAM_3)         → Nemico (NON conta nel ref_count)\n";
    std::cout << "\n";

    // STEP 4: Verifica stato (nemico vivo)
    std::cout << "--- STEP 4: Verifica stato (nemico vivo) ---\n";
    cam1.verificaStatoNemico();
    cam2.verificaStatoNemico();
    cam3.verificaStatoNemico();
    std::cout << "\n";

    // STEP 5: Nemico si muove
    std::cout << "--- STEP 5: Nemico si muove ---\n";
    nemico_live->muovi(5, 3);
    std::cout << "\n";

    // STEP 6: Nemico subisce danno
    std::cout << "--- STEP 6: Nemico subisce danno ---\n";
    nemico_live->subisciDanno(20);
    std::cout << "\n";

    // STEP 7: Verifica di nuovo (ancora vivo)
    std::cout << "--- STEP 7: Verifica stato (ancora vivo) ---\n";
    cam1.verificaStatoNemico();
    std::cout << "\n";

    // STEP 8: Nemico muore!
    std::cout << "--- STEP 8: Nemico muore! (Game Engine lo elimina) ---\n";
    nemico_live.reset();  // Simula: Game Engine elimina il nemico
    std::cout << "Il nemico e' stato eliminato dal Game Engine\n";
    std::cout << "\nMemory state DOPO reset:\n";
    std::cout << "  Nemico deallocato (destructor chiamato)\n";
    std::cout << "  weak_ptr (CAM_1) → invalido (nullptr)\n";
    std::cout << "  weak_ptr (CAM_2) → invalido (nullptr)\n";
    std::cout << "  weak_ptr (CAM_3) → invalido (nullptr)\n";
    std::cout << "\n";

    // STEP 9: Telecamere provano a vedere (scomparso!)
    std::cout << "--- STEP 9: Telecamere verificano (nemico scomparso!) ---\n";
    cam1.verificaStatoNemico();
    cam2.verificaStatoNemico();
    cam3.verificaStatoNemico();
    std::cout << "\n";

    // STEP 10: Una telecamera smette di osservare
    std::cout << "--- STEP 10: CAM_1 esce dal gioco ---\n";
    cam1.smettiDiOsservare();
    std::cout << "\n";

    std::cout << "--- Fine della demo ---\n";
    std::cout << "Quando le telecamere escono di scope, i loro destructor vengono chiamati\n";
}

// ============================================================================
// MAIN
// ============================================================================

int main() noexcept {
    try {
        demo();

        std::cout << "\n" << std::string(70, '=') << "\n";
        std::cout << "LEZIONE: Cosa abbiamo imparato?\n";
        std::cout << std::string(70, '=') << "\n\n";

        std::cout << "1. shared_ptr vs weak_ptr:\n";
        std::cout << "   - shared_ptr POSSIEDE l'oggetto (mantiene in vita)\n";
        std::cout << "   - weak_ptr OSSERVA l'oggetto (non lo mantiene in vita)\n\n";

        std::cout << "2. weak_ptr.lock():\n";
        std::cout << "   - Se oggetto esiste: restituisce shared_ptr valido\n";
        std::cout << "   - Se oggetto è deallocato: restituisce nullptr\n\n";

        std::cout << "3. Ciclo di vita:\n";
        std::cout << "   - Nemico nasce (shared_ptr creato)\n";
        std::cout << "   - Telecamere lo osservano (weak_ptr creato)\n";
        std::cout << "   - Nemico muore (shared_ptr distrutto)\n";
        std::cout << "   - Telecamere vedono nullptr (weak_ptr invalido)\n";
        std::cout << "   - Telecamere scompaiono (destructor)\n\n";

        std::cout << "4. Use cases in gaming:\n";
        std::cout << "   - Nemici osservati da telecamere\n";
        std::cout << "   - Giocatori con power-up debuff temporanei\n";
        std::cout << "   - NPC che seguono il giocatore\n";
        std::cout << "   - Boss con fasi (oggetti che appaiono/scompaiono)\n\n";

        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Errore: " << e.what() << "\n";
        return 1;
    }
}