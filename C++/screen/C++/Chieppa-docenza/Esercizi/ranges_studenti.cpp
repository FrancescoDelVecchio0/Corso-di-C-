#include <ranges>
#include <vector>
#include <string>
#include <iostream>

struct Student {
    std::string name;
    int grade;
};

int main() {
    std::vector<Student> students = {
        {"Alice", 25},
        {"Bob", 16},
        {"Charlie", 28},
        {"Diana", 22},
        {"Eve", 15},
        {"Frank", 30},
        {"Grace", 19}
    };

    auto result = students
        | std::views::filter([](const Student& s) { return s.grade >= 18; })
        | std::views::take(3)
        | std::views::transform([](const Student& s) { return s.name; });

    for (const auto& name : result) {
        std::cout << name << " ";  // Alice Charlie Diana
    }
    std::cout << "\n";
}