#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <utility>

// ============================================================================
// Classe Documento
// ============================================================================

class Documento {
private:
    std::string titolo_;
    std::string contenuto_;

public:
    // Costruttore con parametri
    explicit Documento(std::string_view titolo) noexcept
        : titolo_(titolo), contenuto_("") {}

    // Costruttore con titolo e contenuto
    Documento(std::string_view titolo, std::string_view contenuto) noexcept
        : titolo_(titolo), contenuto_(contenuto) {}

    // Deleted copy constructor e assignment (documenti non sono copiabili)
    Documento(const Documento&) = delete;
    Documento& operator=(const Documento&) = delete;

    // Move semantics (abilitati di default, ma li scriviamo esplicitamente)
    Documento(Documento&&) noexcept = default;
    Documento& operator=(Documento&&) noexcept = default;

    // ~Documento() = default; // Non necessario, ma esplicito
    ~Documento() noexcept = default;

    // Getter per il titolo
    [[nodiscard]] const std::string& getTitolo() const& noexcept {
        return titolo_;
    }

    // Getter per il contenuto
    [[nodiscard]] const std::string& getContenuto() const& noexcept {
        return contenuto_;
    }

    // Setter per il contenuto
    void setContenuto(std::string_view nuovo_contenuto) & noexcept {
        contenuto_ = nuovo_contenuto;
    }

    // Metodo per aggiungere contenuto
    void aggiungiContenuto(std::string_view testo) & noexcept {
        contenuto_ += testo;
    }

    // Stampa il documento
    void stampa() const& noexcept {
        std::cout << "--- Documento: " << titolo_ << " ---\n"
                  << "Contenuto: " << contenuto_ << "\n\n";
    }
};

// ============================================================================
// Classe Editor
// ============================================================================

class Editor {
private:
    std::vector<std::unique_ptr<Documento>> archivio_;

public:
    Editor() noexcept = default;

    // Deleted copy (un editor non si copia)
    Editor(const Editor&) = delete;
    Editor& operator=(const Editor&) = delete;

    // Move è OK (semantica di spostamento)
    Editor(Editor&&) noexcept = default;
    Editor& operator=(Editor&&) noexcept = default;

    ~Editor() noexcept = default;

    // Crea un documento con il titolo fornito
    // Restituisce std::unique_ptr<Documento>
    [[nodiscard]] static std::unique_ptr<Documento>
    creaDocumento(std::string_view titolo) noexcept {
        return std::make_unique<Documento>(titolo);
    }

    // Archivia un documento nel vettore interno
    // Prende ownership del documento (move semantics)
    void archivio(std::unique_ptr<Documento> doc) & noexcept {
        if (!doc) {
            std::cerr << "Errore: tentativo di archiviare un documento null\n";
            return;
        }
        archivio_.push_back(std::move(doc));
    }

    // Stampa tutti i documenti archiviati
    void stampaArchivio() const& noexcept {
        if (archivio_.empty()) {
            std::cout << "Archivio vuoto.\n\n";
            return;
        }

        std::cout << "=== ARCHIVIO EDITOR ===\n";
        std::cout << "Totale documenti: " << archivio_.size() << "\n\n";

        for (const auto& doc : archivio_) {
            if (doc) {
                doc->stampa();
            }
        }
        std::cout << "======================\n\n";
    }

    // Restituisce il numero di documenti archiviati
    [[nodiscard]] std::size_t contaDocumenti() const& noexcept {
        return archivio_.size();
    }

    // Accedi a un documento per indice (con bounds checking)
    [[nodiscard]] const Documento* getDocumento(std::size_t indice) const& noexcept {
        if (indice >= archivio_.size()) {
            return nullptr;
        }
        return archivio_[indice].get();
    }

    // Restituisce const reference al vettore interno
    [[nodiscard]] const std::vector<std::unique_ptr<Documento>>&
    getArchivio() const& noexcept {
        return archivio_;
    }
};

// ============================================================================
// Funzione helper per mostrare l'utilizzo
// ============================================================================

void dimostrazione() noexcept {
    std::cout << "\n" << std::string(60, '=') << "\n";
    std::cout << "DIMOSTRAZIONE: Documento + Editor con C++20 idioms\n";
    std::cout << std::string(60, '=') << "\n\n";

    // Creiamo un editor
    Editor editor;

    // Creiamo dei documenti usando la factory method statica
    auto doc1 = Editor::creaDocumento("Relazione Q1");
    auto doc2 = Editor::creaDocumento("Presentazione finale");
    auto doc3 = Editor::creaDocumento("Note di progetto");

    // Modifichiamo i documenti
    if (doc1) {
        doc1->setContenuto("Questo è il contenuto della relazione Q1...");
    }
    if (doc2) {
        doc2->setContenuto("Slide della presentazione finale...");
    }
    if (doc3) {
        doc3->aggiungiContenuto("Prima nota: ");
        doc3->aggiungiContenuto("ricordare di controllare i deadline");
    }

    // Archiviamo i documenti (trasferimento di ownership)
    std::cout << "Archiviando i documenti...\n\n";
    editor.archivio(std::move(doc1));
    editor.archivio(std::move(doc2));
    editor.archivio(std::move(doc3));

    // doc1, doc2, doc3 sono ora nullptr (ownership trasferita)
    if (!doc1) {
        std::cout << "✓ doc1 è ora nullptr (ownership trasferita)\n\n";
    }

    // Stampiamo l'archivio
    editor.stampaArchivio();

    // Accediamo a un documento specifico
    std::cout << "Accesso al primo documento:\n";
    if (const auto& primo = editor.getDocumento(0)) {
        std::cout << "Titolo: " << primo->getTitolo() << "\n";
        std::cout << "Contenuto: " << primo->getContenuto() << "\n\n";
    }

    // Conteggio documenti
    std::cout << "Totale documenti in archivio: " << editor.contaDocumenti()
              << "\n\n";

    // Esempio: creazione e archiviazione in una sola riga
    std::cout << "Aggiungendo un documento ad-hoc...\n";
    auto temp = Editor::creaDocumento("Documento temporaneo");
    if (temp) {
        temp->setContenuto("Questo documento è stato creato al volo");
    }
    editor.archivio(std::move(temp));

    std::cout << "\nNuovo totale documenti: " << editor.contaDocumenti()
              << "\n\n";

    // Stampa finale
    editor.stampaArchivio();
}

// ============================================================================
// Main
// ============================================================================

int main() noexcept {
    try {
        dimostrazione();
        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Errore: " << e.what() << "\n";
        return 1;
    }
}