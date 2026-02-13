#include <iostream>
#include <chrono>

int main() {
    using namespace std::chrono;

    // system_clock - ora di sistema
    auto ora_attuale = system_clock::now();
    std::cout << "Ora attuale (timestamp): " << ora_attuale.time_since_epoch().count() << '\n';

    // steady_clock - per misurare durate (non risentente di aggiustamenti di sistema)
    auto inizio = steady_clock::now();
    // ... fai qualcosa ...
    auto fine = steady_clock::now();

    auto durata = duration_cast<milliseconds>(fine - inizio);
    std::cout << "Durata: " << durata.count() << " ms\n";

    return 0;
}