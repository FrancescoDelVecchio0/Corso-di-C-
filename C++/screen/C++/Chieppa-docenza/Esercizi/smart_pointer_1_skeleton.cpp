#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <utility>

// ============================================================================
// ESERCIZIO: Documento + Editor
// ============================================================================
// 
// OBIETTIVI:
// 1. Implementare una classe Documento con titolo e contenuto
// 2. Implementare una classe Editor che crea e archivia documenti
// 3. Usare unique_ptr per la gestione della memoria
// 4. Applicare idiomi C++20: [[nodiscard]], const&, noexcept, ecc.
//
// IMPORTANTE: Non modificare la firma dei metodi, solo il corpo!
//
// ============================================================================

// ============================================================================
// Classe Documento
// ============================================================================

class Documento {
private:
    // TODO: Dichiara due member private per titolo e contenuto
    // Usa std::string per entrambi
    // Suggerimento: usa il suffisso _ per i member (es. titolo_)
    
    // ... COMPLETA QUI ...

public:
    // Costruttore: prende il titolo come std::string_view
    // Inizializza il contenuto a stringa vuota
    // ATTENZIONE: usa explicit e noexcept
    explicit Documento(std::string_view titolo) noexcept {
        // ... COMPLETA QUI ...
    }

    // Costruttore con titolo e contenuto
    // Prende entrambi come std::string_view
    Documento(std::string_view titolo, std::string_view contenuto) noexcept {
        // ... COMPLETA QUI ...
    }

    // TODO: Elimina il copy constructor (= delete)
    Documento(const Documento&) = delete;
    
    // TODO: Elimina il copy assignment (= delete)
    Documento& operator=(const Documento&) = delete;

    // TODO: Abilita move constructor (= default)
    // ... COMPLETA QUI ...

    // TODO: Abilita move assignment (= default)
    // ... COMPLETA QUI ...

    // TODO: Dichiara il destructor come default
    // ... COMPLETA QUI ...

    // Getter per il titolo
    // NOTA: const&, [[nodiscard]], noexcept sono già forniti
    // Tu completa il corpo: restituisci titolo_
    [[nodiscard]] const std::string& getTitolo() const& noexcept {
        // ... COMPLETA QUI ...
    }

    // TODO: Implementa getter per il contenuto
    // Firma: [[nodiscard]] const std::string& getContenuto() const& noexcept
    // ... COMPLETA QUI ...

    // TODO: Implementa setter per il contenuto
    // Firma: void setContenuto(std::string_view nuovo_contenuto) & noexcept
    // Suggerimento: assegna nuovo_contenuto a contenuto_
    // ... COMPLETA QUI ...

    // TODO: Implementa un metodo che aggiunge contenuto
    // Firma: void aggiungiContenuto(std::string_view testo) & noexcept
    // Suggerimento: usa += per concatenare
    // ... COMPLETA QUI ...

    // Metodo per stampare il documento
    // Fornito come esempio di uso di const& e noexcept
    void stampa() const& noexcept {
        std::cout << "--- Documento: " << getTitolo() << " ---\n"
                  << "Contenuto: " << getContenuto() << "\n\n";
    }
};

// ============================================================================
// Classe Editor
// ============================================================================

class Editor {
private:
    // TODO: Dichiara un vector di unique_ptr<Documento> per l'archivio
    // Suggerimento: std::vector<std::unique_ptr<Documento>> archivio_;
    // ... COMPLETA QUI ...

public:
    // Costruttore di default
    Editor() noexcept = default;

    // TODO: Elimina il copy constructor
    Editor(const Documento&) = delete;
    
    // TODO: Elimina il copy assignment
    Editor& operator=(const Documento&) = delete;

    // TODO: Abilita move constructor (= default)
    // ... COMPLETA QUI ...

    // TODO: Abilita move assignment (= default)
    // ... COMPLETA QUI ...

    // TODO: Dichiara il destructor come default
    // ... COMPLETA QUI ...

    // Factory method statico che crea un Documento
    // Restituisce std::unique_ptr<Documento>
    // NOTA: [[nodiscard]] è già fornito
    [[nodiscard]] static std::unique_ptr<Documento> 
    creaDocumento(std::string_view titolo) noexcept {
        // TODO: Usa std::make_unique<Documento>(titolo) e restituisci
        // ... COMPLETA QUI ...
    }

    // Archivia un documento nel vettore interno
    // IMPORTANTE: questo metodo prende ownership (move semantics)
    // Firma: void archivio(std::unique_ptr<Documento> doc) & noexcept
    // 
    // Cosa fare:
    // 1. Controlla che doc non sia nullptr (se è nullptr, stampa un errore e return)
    // 2. Usa push_back con std::move(doc) per aggiungere al vettore
    void archivio(std::unique_ptr<Documento> doc) & noexcept {
        // ... COMPLETA QUI ...
    }

    // TODO: Implementa un metodo per stampare tutti i documenti archiviati
    // Firma: void stampaArchivio() const& noexcept
    // 
    // Cosa fare:
    // 1. Se archivio_ è vuoto, stampa "Archivio vuoto." e return
    // 2. Stampa un header come "=== ARCHIVIO EDITOR ==="
    // 3. Stampa il numero di documenti: archivio_.size()
    // 4. Itera su archivio_ con range-based for (const auto& doc)
    // 5. Se doc è valido, chiama doc->stampa()
    // ... COMPLETA QUI ...

    // TODO: Implementa un metodo che conta i documenti
    // Firma: [[nodiscard]] std::size_t contaDocumenti() const& noexcept
    // Suggerimento: restituisci archivio_.size()
    // ... COMPLETA QUI ...

    // TODO: Implementa un metodo che accede a un documento per indice
    // Firma: [[nodiscard]] const Documento* getDocumento(std::size_t indice) const& noexcept
    // 
    // Cosa fare:
    // 1. Se indice >= archivio_.size(), restituisci nullptr
    // 2. Altrimenti, restituisci archivio_[indice].get()
    // ... COMPLETA QUI ...
};

// ============================================================================
// Funzione di test
// ============================================================================

void test() noexcept {
    std::cout << "\n" << std::string(60, '=') << "\n";
    std::cout << "TEST: Documento + Editor\n";
    std::cout << std::string(60, '=') << "\n\n";

    // TODO: Completa il codice di test qui sotto seguendo questi step:
    
    // 1. Crea un oggetto Editor
    // ... COMPLETA QUI ...

    // 2. Crea tre documenti usando Editor::creaDocumento()
    //    - "Relazione Q1"
    //    - "Presentazione finale"
    //    - "Note di progetto"
    // ... COMPLETA QUI ...

    // 3. Modifica i documenti creati usando setContenuto() e aggiungiContenuto()
    //    Suggerimento: controlla che il unique_ptr non sia nullptr prima di usarlo
    // ... COMPLETA QUI ...

    // 4. Archivia i documenti usando editor.archivio(std::move(doc))
    //    Nota: dopo std::move(), il unique_ptr diventa nullptr
    // ... COMPLETA QUI ...

    // 5. Stampa l'archivio usando editor.stampaArchivio()
    // ... COMPLETA QUI ...

    // 6. Accedi al primo documento usando editor.getDocumento(0)
    //    e stampa il suo titolo e contenuto
    // ... COMPLETA QUI ...

    // 7. Stampa il numero totale di documenti usando editor.contaDocumenti()
    // ... COMPLETA QUI ...

    std::cout << "\nTest completato!\n\n";
}

// ============================================================================
// Main
// ============================================================================

int main() noexcept {
    try {
        test();
        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Errore: " << e.what() << "\n";
        return 1;
    }
}