#include <iostream>
#include <memory>
#include <string>
#include <vector>

// --- 1. I COMPONENTI (I NOSTRI MATTONCINI) ---
struct Posizione { 
    float x, y; 
    void debug() const { std::cout << "[Posizione: " << x << ", " << y << "] "; }
};

struct Salute { 
    int hp; 
    void debug() const { std::cout << "[Salute: " << hp << " HP] "; }
};

struct Attacco { 
    int danno; 
    void debug() const { std::cout << "[Attacco: " << danno << " DMG] "; }
};

// --- 2. IL CONTENITORE UNIVERSALE (COMPOSIZIONE) ---
class Entita {
public:
    std::string nome;
    
    // Composizione: l'entità "ha" dei componenti opzionali
    std::unique_ptr<Posizione> pos;
    std::unique_ptr<Salute> vita;
    std::unique_ptr<Attacco> arma;

    explicit Entita(std::string n) : nome(std::move(n)) {}

    void mostraStato() const {
        std::cout << "Entita: " << nome << " -> ";
        if (pos) pos->debug();
        if (vita) vita->debug();
        if (arma) arma->debug();
        if (!pos && !vita && !arma) std::cout << "(Vuota)";
        std::cout << std::endl;
    }
};

// --- 3. TEST NEL MAIN ---
int main() {
    std::cout << "--- CREAZIONE ENTITA TRAMITE COMPOSIZIONE ---\n";

    // MURO: Ha solo salute
    auto muro = std::make_unique<Entita>("Muro di Pietra");
    muro->vita = std::make_unique<Salute>(500);
    muro->mostraStato();

    // TORRETTA: Salute e Attacco (Fissa)
    auto torretta = std::make_unique<Entita>("Torretta Difensiva");
    torretta->vita = std::make_unique<Salute>(200);
    torretta->arma = std::make_unique<Attacco>(50);
    torretta->mostraStato();

    // DRONE: Posizione, Salute e Attacco
    auto drone = std::make_unique<Entita>("Drone Scout");
    drone->pos = std::make_unique<Posizione>(10.5f, 20.0f);
    drone->vita = std::make_unique<Salute>(50);
    drone->arma = std::make_unique<Attacco>(10);
    drone->mostraStato();
}