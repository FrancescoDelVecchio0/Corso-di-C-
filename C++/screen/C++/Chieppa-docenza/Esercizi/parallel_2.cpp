#include <algorithm>
#include <execution>
#include <vector>
#include <iostream>
#include <cstdint>

struct Pixel {
    uint8_t r, g, b;
};

int main() {
    std::vector<Pixel> image(3840 * 2160);

    for (auto& p : image) {
        p.r = rand() % 256;
        p.g = rand() % 256;
        p.b = rand() % 256;
    }

    std::for_each(std::execution::par,
        image.begin(), image.end(),
        [](Pixel& p) {
            uint8_t gray = static_cast<uint8_t>(
                0.299 * p.r + 0.587 * p.g + 0.114 * p.b
                );
    p.r = p.g = p.b = gray;
        });

    std::cout << "Primo pixel dopo conversione:\n";
    std::cout << "R=" << (int)image[0].r
        << " G=" << (int)image[0].g
        << " B=" << (int)image[0].b << "\n";

    bool is_grayscale = (image[0].r == image[0].g && image[0].g == image[0].b);
    std::cout << "Grayscale: " << (is_grayscale ? "SI" : "NO") << "\n";

    return 0;
}