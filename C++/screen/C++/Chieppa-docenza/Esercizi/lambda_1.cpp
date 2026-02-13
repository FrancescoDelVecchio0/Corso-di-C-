#include <iostream>
#include <vector>
#include <algorithm>

int main() noexcept {
    std::cout << "\n" << std::string(70, '=') << "\n";
    std::cout << "ESERCIZIO: Lambda con cattura per valore\n";
    std::cout << std::string(70, '=') << "\n\n";

    // ========================================================================
    // STEP 1: Crea la variabile moltiplicatore
    // ========================================================================
    std::cout << "--- STEP 1: Variabile moltiplicatore ---\n";
    int moltiplicatore = 5;
    std::cout << "moltiplicatore = " << moltiplicatore << "\n\n";

    // ========================================================================
    // STEP 2: Scrivi la lambda che cattura moltiplicatore per valore
    // ========================================================================
    std::cout << "--- STEP 2: Lambda con cattura per valore ---\n";
    
    // SCOMPOSIZIONE della lambda:
    //   [moltiplicatore]      → cattura moltiplicatore per VALORE
    //   (int numero)          → parametro: numero da moltiplicare
    //   noexcept              → non lancia eccezioni
    //   { return numero * moltiplicatore; }  → corpo: esegui moltiplicazione
    
    auto moltiplica = [moltiplicatore](int numero) noexcept {
        return numero * moltiplicatore;
    };

    std::cout << "Lambda creata: auto moltiplica = [moltiplicatore](int numero) {...}\n";
    std::cout << "La lambda cattura moltiplicatore per VALORE\n\n";

    // ========================================================================
    // STEP 3: Usa la lambda su alcuni numeri
    // ========================================================================
    std::cout << "--- STEP 3: Testa la lambda ---\n";
    std::cout << "moltiplica(2) = " << moltiplica(2) << "\n";
    std::cout << "moltiplica(10) = " << moltiplica(10) << "\n";
    std::cout << "moltiplica(3) = " << moltiplica(3) << "\n\n";

    // ========================================================================
    // STEP 4: Crea un vector<int>
    // ========================================================================
    std::cout << "--- STEP 4: Vector di numeri ---\n";
    std::vector<int> numeri = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    std::cout << "Vector: ";
    for (int num : numeri) {
        std::cout << num << " ";
    }
    std::cout << "\n\n";

    // ========================================================================
    // STEP 5: Applica la lambda a ogni numero del vector
    // ========================================================================
    std::cout << "--- STEP 5: Applica lambda al vector ---\n";
    std::cout << "Risultati dopo moltiplicazione per " << moltiplicatore << ":\n";
    std::cout << "{ ";
    for (int num : numeri) {
        std::cout << moltiplica(num) << " ";
    }
    std::cout << "}\n\n";

    // ========================================================================
    // STEP 6: Alternativa con std::transform
    // ========================================================================
    std::cout << "--- STEP 6: Con std::transform ---\n";
    std::vector<int> risultati(numeri.size());
    
    // std::transform applica la lambda a ogni elemento
    std::transform(numeri.begin(), numeri.end(), risultati.begin(), moltiplica);
    
    std::cout << "Risultati nel nuovo vector:\n";
    std::cout << "{ ";
    for (int res : risultati) {
        std::cout << res << " ";
    }
    std::cout << "}\n\n";

    // ========================================================================
    // STEP 7: Cosa succede se cambiamo moltiplicatore?
    // ========================================================================
    std::cout << "--- STEP 7: Modifica moltiplicatore ---\n";
    moltiplicatore = 10;
    std::cout << "Cambio moltiplicatore = " << moltiplicatore << "\n";
    std::cout << "moltiplica(5) = " << moltiplica(5) << "\n";
    std::cout << "⚠️ ATTENZIONE: Risultato è ancora 25 (5*5), non 50!\n";
    std::cout << "Perché? La lambda ha CATTURATO per VALORE il valore originale (5)\n";
    std::cout << "Non vede il nuovo valore di moltiplicatore\n\n";

    // ========================================================================
    // LEZIONE: Cattura per valore vs cattura per riferimento
    // ========================================================================
    std::cout << "--- LEZIONE: Differenza cattura per valore vs riferimento ---\n\n";

    int fattore = 3;
    
    // Lambda 1: Cattura per VALORE [fattore]
    auto per_valore = [fattore](int x) noexcept { return x * fattore; };
    
    // Lambda 2: Cattura per RIFERIMENTO [&fattore]
    auto per_riferimento = [&fattore](int x) noexcept { return x * fattore; };
    
    std::cout << "fattore = " << fattore << "\n";
    std::cout << "per_valore(10) = " << per_valore(10) << " (10*3=30)\n";
    std::cout << "per_riferimento(10) = " << per_riferimento(10) << " (10*3=30)\n\n";
    
    fattore = 7;
    std::cout << "Cambio fattore = " << fattore << "\n";
    std::cout << "per_valore(10) = " << per_valore(10) << " (10*3=30) ← Usa il VECCHIO valore!\n";
    std::cout << "per_riferimento(10) = " << per_riferimento(10) << " (10*7=70) ← Usa il NUOVO valore!\n\n";

    // ========================================================================
    // RIEPILOGO
    // ========================================================================
    std::cout << std::string(70, '=') << "\n";
    std::cout << "RIEPILOGO\n";
    std::cout << std::string(70, '=') << "\n\n";

    std::cout << "1. Lambda con cattura per VALORE [variabile]:\n";
    std::cout << "   - Copia il valore al momento della creazione\n";
    std::cout << "   - Se variabile cambia, lambda usa il VECCHIO valore\n";
    std::cout << "   - Sicura e prevedibile\n\n";

    std::cout << "2. Lambda con cattura per RIFERIMENTO [&variabile]:\n";
    std::cout << "   - Vede il riferimento (address) della variabile\n";
    std::cout << "   - Se variabile cambia, lambda vede il NUOVO valore\n";
    std::cout << "   - Attenzione: variabile deve rimanere in scope!\n\n";

    std::cout << "3. std::transform:\n";
    std::cout << "   - Applica una funzione a ogni elemento di un container\n";
    std::cout << "   - Salva risultati in un altro container\n";
    std::cout << "   - Perfetto per operazioni elemento per elemento\n\n";

    return 0;
}