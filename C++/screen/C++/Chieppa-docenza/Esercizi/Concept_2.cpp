#include <utility>
#include <iostream>
#include <concepts>
#include <string>
#include <string_view>

// Concept: accetta tutto ciò da cui si può costruire std::string
template<typename T>
concept StringConvertible = std::constructible_from<std::string, T>;

template<StringConvertible T>
class Box {
private:
    T value_;

public:
    template<typename U>
    explicit Box(U&& value) : value_(std::forward<U>(value)) {}

    [[nodiscard]] auto get() const noexcept {
        return value_;
    }

    template<typename U>
    void set(U&& value) noexcept {
        value_ = std::forward<U>(value);
    }
};

int main() {
    // ✅ std::string
    std::string msg = "moving...";
    auto p = Box<std::string>(std::move(msg));
    std::cout << "value = " << p.get() << '\n';

    // ✅ const char* (convertibile a string)
    auto k = Box<const char*>("hello");
    k.set("world");
    std::cout << "value = " << k.get() << '\n';

    // ✅ std::string_view (convertibile a string)
    std::string_view sv = "string_view";
    auto m = Box<std::string_view>(sv);
    std::cout << "value = " << m.get() << '\n';

    // ❌ int NON è convertibile a string
    // auto b = Box<int>(5);  // Errore!
    
    // ❌ double NON è convertibile a string
    // auto n = Box<double>(1.4);  // Errore!
}