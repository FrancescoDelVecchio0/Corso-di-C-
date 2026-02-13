#include <iostream>
#include <memory>
#include <string>
#include <map>

struct Immagine {
    std::string nome;
    Immagine(std::string n) : nome(std::move(n)) { std::cout << "[Caricamento pesante] " << nome << "\n"; }
    ~Immagine() { std::cout << "[Rimozione] " << nome << "\n"; }
};

class ImageCache {
private:
    // La cache non possiede l'immagine, la osserva soltanto [cite: 318]
    std::map<std::string, std::weak_ptr<Immagine>> cache;

public:
    std::shared_ptr<Immagine> getImmagine(const std::string& nome) {
        // 1. Controlla se esiste nella cache e se è ancora valida [cite: 303, 319]
        if (auto osservatore = cache[nome].lock()) {
            std::cout << "Immagine '" << nome << "' recuperata dalla cache.\n";
            return osservatore;
        }

        // 2. Se non valida o non esistente, carica l'immagine [cite: 319]
        std::cout << "Immagine '" << nome << "' non trovata o scaduta. Caricamento...\n";
        auto nuovaImmagine = std::make_shared<Immagine>(nome);
        
        // Salva il weak_ptr nella cache per utilizzi futuri [cite: 319]
        cache[nome] = nuovaImmagine;
        
        return nuovaImmagine;
    }
};

int main() {
    ImageCache sistemaCache;

    {
        std::cout << "--- Richiesta 1 ---\n";
        auto img1 = sistemaCache.getImmagine("sfondo.png");

        std::cout << "\n--- Richiesta 2 (Cache Hit) ---\n";
        auto img2 = sistemaCache.getImmagine("sfondo.png");
    } 
    // img1 e img2 escono dallo scope: il contatore arriva a 0, l'immagine viene distrutta [cite: 295]

    std::cout << "\n--- Richiesta 3 (Dopo distruzione) ---\n";
    // La cache ha ancora il weak_ptr, ma lock() fallirà e ricaricherà l'immagine [cite: 304, 305]
    auto img3 = sistemaCache.getImmagine("sfondo.png");

    return 0;
}