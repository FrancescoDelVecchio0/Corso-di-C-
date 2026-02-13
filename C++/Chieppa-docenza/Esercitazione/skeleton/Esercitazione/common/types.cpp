#include "types.hpp"
#include <cmath>

namespace rpg {

auto Position::distance_to(const Position& other) const noexcept -> float {
    const float dx = x - other.x;
    const float dy = y - other.y;
    return std::sqrt(dx * dx + dy * dy);
}

} // namespace rpg
