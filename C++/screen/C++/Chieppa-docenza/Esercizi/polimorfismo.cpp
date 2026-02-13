#include <iostream>
#include <vector>
#include <memory>
#include <string>

// --- CLASSE BASE ---
class Nemico {
public:
    // Il distruttore virtuale è FONDAMENTALE per il polimorfismo con smart pointers [cite: 66, 140]
    virtual ~Nemico() { 
        std::cout << "Distruttore Nemico (Base) chiamato\n"; 
    }

    // Metodo virtuale puro: rende la classe astratta [cite: 130, 131]
    virtual void attacca() const = 0; 
};

// --- CLASSI DERIVATE ---
class Orco final : public Nemico {
public:
    ~Orco() override { 
        std::cout << "Distruttore Orco (Derivato) - Risorse liberate!\n"; 
    }

    void attacca() const override { 
        std::cout << "L'Orco colpisce con la clava! [Danno pesante]\n"; 
    }
};

class Arciere final : public Nemico {
private:
    std::string tipo_frecce = "Incendiarie"; // Risorsa specifica
public:
    ~Arciere() override { 
        std::cout << "Distruttore Arciere (Derivato) - Frecce " << tipo_frecce << " rimosse!\n"; 
    }

    void attacca() const override { 
        std::cout << "L'Arciere scaglia una freccia " << tipo_frecce << "!\n"; 
    }
};

// --- MAIN ---
int main() {
    std::cout << "--- CREAZIONE ESERCITO POLIMORFICO ---\n";

    // Usiamo unique_ptr per gestire la memoria in modo RAII [cite: 250, 280]
    // Il vector gestisce la proprietà esclusiva dei nemici [cite: 282]
    std::vector<std::unique_ptr<Nemico>> esercito;

    esercito.push_back(std::make_unique<Orco>());
    esercito.push_back(std::make_unique<Arciere>());

    std::cout << "\n--- INIZIO ATTACCO (Runtime Dispatch) ---\n";
    for (const auto& nemico : esercito) {
        // Il compilatore usa la V-Table per decidere quale attacca() chiamare [cite: 71, 72]
        nemico->attacca(); 
    }

    std::cout << "\n--- DISTRUZIONE (L'importanza di virtual ~) ---\n";
    // Quando il vector esce dallo scope, distrugge i unique_ptr.
    // Se il distruttore della base è virtual, viene chiamata tutta la catena [cite: 67, 69]
    return 0;
}


/*
3. Il Bonus: Simulare il Memory Leak
Per mostrare il problema del distruttore:



Fagli commentare virtual nel distruttore di Nemico.

Riesegui il codice.

Noteranno che i messaggi "Distruttore Orco" e "Distruttore Arciere" scompaiono.


Conclusione: Se l'Arciere avesse allocato memoria dinamica o aperto un file, quella risorsa sarebbe rimasta appesa nel sistema (Memory Leak).
*/