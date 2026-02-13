#include <utility>
#include  <iostream>

template<typename T>
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
    auto b = Box<int>(5); //move

    b.set(42);
    std::cout << "value = " << b.get() << '\n';

    std::string msg = "moving...";
    auto p = Box<std::string>(std::move(msg));
    std::cout << "value = " << p.get() << '\n';

    double v = 1.4;
    auto n = Box<double>(v); // copy
    std::cout << "value = " << n.get() << '\n';

    auto k = Box<std::string>("");
    k.set("hello"); // move semantic
    std::cout << "value = " << k.get() << '\n';
}