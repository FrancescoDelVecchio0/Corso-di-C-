// Con std::pair
auto [nemici, danno_tot] = statistiche(player);  // ✅ Structured binding

// Equivalente a
std::pair<int, int> result = statistiche(player);
int nemici = result.first;
int danno_tot = result.second;