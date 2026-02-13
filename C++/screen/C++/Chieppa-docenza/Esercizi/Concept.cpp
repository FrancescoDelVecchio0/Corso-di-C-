#include <utility>
#include <iostream>
#include <concepts>
#include <string>

// Concept: accetta SOLO std::string
template<typename T>
concept StringType = std::same_as<T, std::string>;

template<StringType T>  // <-- Solo string!
class Box {
private:
    T value_;

public:
    // Costruttore con template per perfect forwarding
    template<typename U>
    explicit Box(U&& value) : value_(std::forward<U>(value)) {}

    [[nodiscard]] auto get() const noexcept {
        return value_;
    }

    template<typename U>    // se non uso UR posso solo passare per copia!
    void set(U&& value) noexcept {
        value_ = std::forward<U>(value);
    }
};

int main() {
    // ❌ Questi NON compilano più!
    // auto b = Box<int>(5);
    // auto n = Box<double>(v);
    
    // ✅ Solo string funziona
    std::string msg = "moving...";
    auto p = Box<std::string>(std::move(msg));
    std::cout << "value = " << p.get() << '\n';

    auto k = Box<std::string>("");
    k.set("hello"); // move semantic
    std::cout << "value = " << k.get() << '\n';
}