#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <utility>

struct Documento {
    std::string titolo;
    std::string contenuto;

    Documento(std::string t, std::string c) 
        : titolo(std::move(t)), contenuto(std::move(c)) {}
    
    ~Documento() { std::cout << "Documento '" << titolo << "' eliminato dalla memoria.\n"; }
};

class Editor {
public:
    // Restituisce la proprietà esclusiva al chiamante [cite: 315]
    std::unique_ptr<Documento> creaDocumento(const std::string& titolo) {
        return std::make_unique<Documento>(titolo, "Contenuto generato dall'editor.");
    }
};

class Archivio {
private:
    std::vector<std::unique_ptr<Documento>> documenti;

public:
    // Riceve la proprietà tramite move semantics [cite: 285, 316]
    void aggiungi(std::unique_ptr<Documento> doc) {
        if (doc) {
            std::cout << "Archiviazione di: " << doc->titolo << "\n";
            documenti.push_back(std::move(doc)); 
        }
    }
};

int main() {
    Editor mioEditor;
    Archivio mioArchivio;

    // 1. L'editor crea un documento (proprietà esclusiva)
    auto doc = mioEditor.creaDocumento("Lezione C++ Avanzato");

    // 2. Trasferimento della proprietà all'archivio [cite: 285]
    mioArchivio.aggiungi(std::move(doc)); 

    // Qui 'doc' è nullptr, la risorsa è gestita dal vector dentro l'archivio
    return 0;
}