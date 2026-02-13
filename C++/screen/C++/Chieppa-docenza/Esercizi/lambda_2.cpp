#include <iostream>

int main() noexcept {
    std::cout << "\n" << std::string(70, '=') << "\n";
    std::cout << "ESERCIZIO: Lambda con cattura per RIFERIMENTO\n";
    std::cout << std::string(70, '=') << "\n\n";

    // ========================================================================
    // STEP 1: Crea il contatore
    // ========================================================================
    std::cout << "--- STEP 1: Variabile contatore ---\n";
    int contatore = 0;
    std::cout << "contatore = " << contatore << "\n\n";

    // ========================================================================
    // STEP 2: Scrivi la lambda che cattura per RIFERIMENTO
    // ========================================================================
    std::cout << "--- STEP 2: Lambda con cattura per RIFERIMENTO ---\n";
    
    // SCOMPOSIZIONE della lambda:
    //   [&contatore]          → cattura contatore per RIFERIMENTO
    //                            (& = "dammi l'indirizzo, non il valore")
    //   ()                    → nessun parametro
    //   noexcept              → non lancia eccezioni
    //   { ++contatore; }      → incrementa il contatore
    
    auto incrementa = [&contatore]() noexcept {
        ++contatore;
    };

    std::cout << "Lambda creata: auto incrementa = [&contatore]() {...}\n";
    std::cout << "La lambda cattura contatore per RIFERIMENTO (&)\n";
    std::cout << "Significa: la lambda vede l'indirizzo del contatore originale\n";
    std::cout << "Se contatore cambia, la lambda lo vede subito!\n\n";

    // ========================================================================
    // STEP 3: Chiama la lambda 10 volte
    // ========================================================================
    std::cout << "--- STEP 3: Chiama la lambda 10 volte ---\n";
    for (int i = 1; i <= 10; ++i) {
        incrementa();
        std::cout << "Chiamata " << i << ": contatore = " << contatore << "\n";
    }
    std::cout << "\n";

    // ========================================================================
    // STEP 4: Stampa il contatore finale
    // ========================================================================
    std::cout << "--- STEP 4: Contatore finale ---\n";
    std::cout << "contatore = " << contatore << "\n";
    std::cout << "✅ SUCCESS! Il contatore è stato incrementato 10 volte\n\n";

    // ========================================================================
    // STEP 5: Confronto con cattura per VALORE
    // ========================================================================
    std::cout << std::string(70, '=') << "\n";
    std::cout << "CONFRONTO: Per valore vs Per riferimento\n";
    std::cout << std::string(70, '=') << "\n\n";

    std::cout << "--- Versione 1: Cattura per VALORE [contatore] ---\n";
    int count_value = 0;
    
    auto incrementa_per_valore = [count_value]() mutable noexcept {
        ++count_value;  // Incrementa la COPIA
    };

    std::cout << "count_value PRIMA: " << count_value << "\n";
    for (int i = 0; i < 5; ++i) {
        incrementa_per_valore();
    }
    std::cout << "count_value DOPO 5 chiamate: " << count_value << "\n";
    std::cout << "⚠️ RESTA 0! Perché?\n";
    std::cout << "   La lambda ha una COPIA di count_value\n";
    std::cout << "   Incrementa la copia, non l'originale\n";
    std::cout << "   L'originale rimane 0\n";
    std::cout << "   Attenzione: serve 'mutable' per modificare la copia\n\n";

    std::cout << "--- Versione 2: Cattura per RIFERIMENTO [&contatore] ---\n";
    int count_ref = 0;
    
    auto incrementa_per_riferimento = [&count_ref]() noexcept {
        ++count_ref;  // Incrementa l'ORIGINALE tramite riferimento
    };

    std::cout << "count_ref PRIMA: " << count_ref << "\n";
    for (int i = 0; i < 5; ++i) {
        incrementa_per_riferimento();
    }
    std::cout << "count_ref DOPO 5 chiamate: " << count_ref << "\n";
    std::cout << "✅ DIVENTA 5! Perché?\n";
    std::cout << "   La lambda ha un RIFERIMENTO a count_ref\n";
    std::cout << "   Incrementa l'originale tramite il riferimento\n";
    std::cout << "   L'originale cambia davvero\n";
    std::cout << "   Non serve 'mutable'\n\n";

    // ========================================================================
    // STEP 6: Visualizzazione Memory
    // ========================================================================
    std::cout << std::string(70, '=') << "\n";
    std::cout << "VISUALIZZAZIONE: Memory e riferimenti\n";
    std::cout << std::string(70, '=') << "\n\n";

    std::cout << "Cattura per VALORE [x]:\n";
    std::cout << "┌─────────────┐        ┌─────────────┐\n";
    std::cout << "│ x = 5       │        │ Lambda      │\n";
    std::cout << "│ (originale) │        │ x_copy = 5  │\n";
    std::cout << "└─────────────┘        └─────────────┘\n";
    std::cout << "     ↑                        ↑\n";
    std::cout << "     └─── Copia fatta al momento della creazione\n";
    std::cout << "Modificare x_copy NON modifica x\n\n";

    std::cout << "Cattura per RIFERIMENTO [&x]:\n";
    std::cout << "┌─────────────┐        ┌─────────────┐\n";
    std::cout << "│ x = 5       │◄───────│ Lambda      │\n";
    std::cout << "│ (originale) │ (ref)  │ &x = 0x1234 │\n";
    std::cout << "└─────────────┘        └─────────────┘\n";
    std::cout << "     ↑\n";
    std::cout << "     └─── Riferimento: punta allo stesso posto\n";
    std::cout << "Modificare tramite &x MODIFICA x\n\n";

    // ========================================================================
    // STEP 7: Differenze riassunto
    // ========================================================================
    std::cout << std::string(70, '=') << "\n";
    std::cout << "TABELLA COMPARATIVA\n";
    std::cout << std::string(70, '=') << "\n\n";

    std::cout << "┌─────────────────────┬──────────────────┬──────────────────┐\n";
    std::cout << "│ Aspetto             │ Per valore [x]   │ Per rif. [&x]     │\n";
    std::cout << "├─────────────────────┼──────────────────┼──────────────────┤\n";
    std::cout << "│ Copia?              │ ✅ SÌ            │ ❌ NO             │\n";
    std::cout << "│ Se x cambia?        │ ❌ Non vede      │ ✅ Vede           │\n";
    std::cout << "│ Modifica originale? │ ❌ NO            │ ✅ SÌ             │\n";
    std::cout << "│ Serve 'mutable'?    │ ✅ Per modificare│ ❌ NO             │\n";
    std::cout << "│ Scope problem?      │ ❌ NO            │ ⚠️ SÌ (dangling)  │\n";
    std::cout << "│ Sicurezza           │ ✅ Sicura        │ ⚠️ Più rischiosa  │\n";
    std::cout << "│ Caso d'uso          │ Snapshot         │ Modificare        │\n";
    std::cout << "│                     │ Immutabile       │ Contatori, stato  │\n";
    std::cout << "└─────────────────────┴──────────────────┴──────────────────┘\n\n";

    // ========================================================================
    // STEP 8: Attenzione al scope
    // ========================================================================
    std::cout << std::string(70, '=') << "\n";
    std::cout << "⚠️ ATTENZIONE: Dangling reference\n";
    std::cout << std::string(70, '=') << "\n\n";

    std::cout << "❌ SBAGLIATO:\n";
    std::cout << "auto creaLambda() {\n";
    std::cout << "    int locale = 10;\n";
    std::cout << "    return [&locale]() { return locale; };  // PERICOLO!\n";
    std::cout << "}  // locale è distrutto qui\n";
    std::cout << "// Lambda punta a memoria non più valida!\n\n";

    std::cout << "✅ CORRETTO:\n";
    std::cout << "int globale = 10;\n";
    std::cout << "auto lambda = [&globale]() { return globale; };\n";
    std::cout << "// globale rimane in scope durante uso della lambda\n\n";

    // ========================================================================
    // RIEPILOGO FINALE
    // ========================================================================
    std::cout << std::string(70, '=') << "\n";
    std::cout << "RIEPILOGO: Quando usare cosa?\n";
    std::cout << std::string(70, '=') << "\n\n";

    std::cout << "Usa [x] (per VALORE) quando:\n";
    std::cout << "  • Vuoi uno 'snapshot' del valore\n";
    std::cout << "  • La variabile potrebbe cambiare, ma tu vuoi il valore vecchio\n";
    std::cout << "  • La lambda è passata fuori scope\n";
    std::cout << "  • Esempio: moltiplica = [factor](int x) { return x * factor; }\n\n";

    std::cout << "Usa [&x] (per RIFERIMENTO) quando:\n";
    std::cout << "  • Vuoi modificare la variabile originale\n";
    std::cout << "  • Vuoi contatore, stato mutevole\n";
    std::cout << "  • La variabile rimane in scope\n";
    std::cout << "  • Esempio: incrementa = [&count]() { ++count; }\n\n";

    std::cout << "Usa [=] (cattura tutto per valore) quando:\n";
    std::cout << "  • Vuoi isolamento totale\n";
    std::cout << "  • La lambda è passata lontano\n";
    std::cout << "  • Esempio: auto lambda = [=](int x) { ... }\n\n";

    std::cout << "Usa [&] (cattura tutto per riferimento) quando:\n";
    std::cout << "  • Vuoi accesso a tutto locale\n";
    std::cout << "  • La lambda rimane locale\n";
    std::cout << "  • Esempio: auto lambda = [&](int x) { ... }\n\n";

    return 0;
}