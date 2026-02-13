#include <iostream>
#include <vector>
#include <algorithm>

int main() noexcept {
    std::cout << "\n" << std::string(70, '=') << "\n";
    std::cout << "ESERCIZIO: std::transform con lambda per quadrato\n";
    std::cout << std::string(70, '=') << "\n\n";

    // ========================================================================
    // STEP 1: Crea il vector con i valori
    // ========================================================================
    std::cout << "--- STEP 1: Crea il vector ---\n";
    std::vector<int> numeri = {1, 2, 3, 4, 5};
    
    std::cout << "Vector originale: { ";
    for (int num : numeri) {
        std::cout << num << " ";
    }
    std::cout << "}\n\n";

    // ========================================================================
    // STEP 2: Scrivi la lambda che eleva al quadrato
    // ========================================================================
    std::cout << "--- STEP 2: Lambda per elevare al quadrato ---\n";
    
    // SCOMPOSIZIONE della lambda:
    //   [](int x)                → cattura nulla, parametro x
    //   noexcept                 → non lancia eccezioni
    //   { return x * x; }        → corpo: x moltiplicato per se stesso
    
    auto quadrato = [](int x) noexcept {
        return x * x;
    };

    std::cout << "Lambda creata: auto quadrato = [](int x) noexcept { return x * x; }\n";
    std::cout << "Questa lambda:\n";
    std::cout << "  • Non cattura nulla (le quadre sono vuote [])\n";
    std::cout << "  • Prende un int come parametro\n";
    std::cout << "  • Restituisce il quadrato (x * x)\n\n";

    // ========================================================================
    // STEP 3: Testa la lambda
    // ========================================================================
    std::cout << "--- STEP 3: Testa la lambda ---\n";
    std::cout << "quadrato(3) = " << quadrato(3) << " (3*3=9)\n";
    std::cout << "quadrato(5) = " << quadrato(5) << " (5*5=25)\n\n";

    // ========================================================================
    // STEP 4: Crea vector per i risultati
    // ========================================================================
    std::cout << "--- STEP 4: Prepara vector per risultati ---\n";
    std::vector<int> risultati(numeri.size());
    
    std::cout << "Vector risultati: { ";
    for (int r : risultati) {
        std::cout << r << " ";
    }
    std::cout << "} (inizialmente vuoto)\n";
    std::cout << "Dimensione: " << risultati.size() << " (stessa di numeri)\n\n";

    // ========================================================================
    // STEP 5: Usa std::transform
    // ========================================================================
    std::cout << "--- STEP 5: std::transform ---\n";
    std::cout << "Firma:\n";
    std::cout << "  std::transform(begin, end, dest, operazione)\n\n";
    
    std::cout << "Nel nostro caso:\n";
    std::cout << "  • begin = numeri.begin() (inizio input)\n";
    std::cout << "  • end = numeri.end() (fine input)\n";
    std::cout << "  • dest = risultati.begin() (dove salvare)\n";
    std::cout << "  • operazione = quadrato (la lambda)\n\n";

    // Esegui transform
    std::transform(numeri.begin(), numeri.end(), risultati.begin(), quadrato);

    std::cout << "std::transform eseguito!\n\n";

    // ========================================================================
    // STEP 6: Stampa i risultati
    // ========================================================================
    std::cout << "--- STEP 6: Risultati ---\n";
    std::cout << "Vector originale: { ";
    for (int num : numeri) {
        std::cout << num << " ";
    }
    std::cout << "}\n";

    std::cout << "Vector risultati: { ";
    for (int res : risultati) {
        std::cout << res << " ";
    }
    std::cout << "}\n\n";

    // ========================================================================
    // STEP 7: Mostra mapping elemento per elemento
    // ========================================================================
    std::cout << "--- STEP 7: Mapping elemento per elemento ---\n";
    for (std::size_t i = 0; i < numeri.size(); ++i) {
        std::cout << numeri[i] << "² = " << risultati[i] << "\n";
    }
    std::cout << "\n";

    // ========================================================================
    // ALTERNATIVA 1: Lambda inline (senza variabile)
    // ========================================================================
    std::cout << std::string(70, '=') << "\n";
    std::cout << "ALTERNATIVA 1: Lambda inline\n";
    std::cout << std::string(70, '=') << "\n\n";

    std::vector<int> risultati2(numeri.size());

    std::cout << "Codice:\n";
    std::cout << "std::transform(numeri.begin(), numeri.end(),\n";
    std::cout << "               risultati2.begin(),\n";
    std::cout << "               [](int x) { return x * x; });\n\n";

    std::transform(numeri.begin(), numeri.end(), risultati2.begin(),
                   [](int x) noexcept { return x * x; });

    std::cout << "Risultato: { ";
    for (int res : risultati2) {
        std::cout << res << " ";
    }
    std::cout << "}\n\n";

    // ========================================================================
    // ALTERNATIVA 2: Trasformazione più complessa
    // ========================================================================
    std::cout << std::string(70, '=') << "\n";
    std::cout << "ALTERNATIVA 2: Lambda più complessa\n";
    std::cout << std::string(70, '=') << "\n\n";

    std::vector<int> risultati3(numeri.size());

    std::cout << "Elevare al quadrato e aggiungere 10:\n";
    std::cout << "Lambda: [](int x) { return x * x + 10; }\n\n";

    std::transform(numeri.begin(), numeri.end(), risultati3.begin(),
                   [](int x) noexcept { return x * x + 10; });

    std::cout << "Risultati: { ";
    for (int res : risultati3) {
        std::cout << res << " ";
    }
    std::cout << "}\n";

    std::cout << "Mapping:\n";
    for (std::size_t i = 0; i < numeri.size(); ++i) {
        std::cout << numeri[i] << "² + 10 = " << risultati3[i] << "\n";
    }
    std::cout << "\n";

    // ========================================================================
    // ALTERNATIVA 3: Con cattura
    // ========================================================================
    std::cout << std::string(70, '=') << "\n";
    std::cout << "ALTERNATIVA 3: Lambda con cattura\n";
    std::cout << std::string(70, '=') << "\n\n";

    int fattore = 2;
    std::vector<int> risultati4(numeri.size());

    std::cout << "Elevare al quadrato e moltiplicare per fattore (" << fattore << "):\n";
    std::cout << "Lambda: [fattore](int x) { return x * x * fattore; }\n\n";

    std::transform(numeri.begin(), numeri.end(), risultati4.begin(),
                   [fattore](int x) noexcept { return x * x * fattore; });

    std::cout << "Risultati: { ";
    for (int res : risultati4) {
        std::cout << res << " ";
    }
    std::cout << "}\n";

    std::cout << "Mapping:\n";
    for (std::size_t i = 0; i < numeri.size(); ++i) {
        std::cout << numeri[i] << "² * " << fattore << " = " << risultati4[i] << "\n";
    }
    std::cout << "\n";

    // ========================================================================
    // RIEPILOGO: std::transform
    // ========================================================================
    std::cout << std::string(70, '=') << "\n";
    std::cout << "RIEPILOGO: std::transform\n";
    std::cout << std::string(70, '=') << "\n\n";

    std::cout << "Cos'è std::transform?\n";
    std::cout << "  • Algoritmo STL che applica una funzione a ogni elemento\n";
    std::cout << "  • Salva i risultati in un altro container\n";
    std::cout << "  • Come un 'map' nei linguaggi funzionali\n\n";

    std::cout << "Firma completa:\n";
    std::cout << "  template<class InputIt, class OutputIt, class UnaryOp>\n";
    std::cout << "  OutputIt transform(InputIt first, InputIt last,\n";
    std::cout << "                      OutputIt d_first, UnaryOp op);\n\n";

    std::cout << "Parametri:\n";
    std::cout << "  • first, last: range di input\n";
    std::cout << "  • d_first: dove iniziare a scrivere (destination)\n";
    std::cout << "  • op: operazione (funzione, lambda, functor)\n\n";

    std::cout << "Ritorna:\n";
    std::cout << "  • Iterator al fine della sequenza di output\n\n";

    std::cout << "Casi d'uso:\n";
    std::cout << "  ✓ Trasformazione elemento per elemento\n";
    std::cout << "  ✓ Conversione di tipo (int → double)\n";
    std::cout << "  ✓ Applicazione di formula matematica\n";
    std::cout << "  ✓ Mapping di valori\n\n";

    std::cout << "Vantaggi:\n";
    std::cout << "  ✓ Conciso e leggibile\n";
    std::cout << "  ✓ Funzionale (no side effects)\n";
    std::cout << "  ✓ Ottimizzabile dal compilatore\n";
    std::cout << "  ✓ Familiare a chi conosce FP\n\n";

    return 0;
}