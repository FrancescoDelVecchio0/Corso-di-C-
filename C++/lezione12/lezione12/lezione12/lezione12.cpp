
#include <iostream>
#include <vector>
#include <ranges>
#include <string>


struct Student
{
    std::string name;
    int grade;
};




int main()
{
    std::vector<Student> students = {
        {"Francesco", 80},
        {"Piero", 67},
        {"Pongo", 76},
        {"Mattia", 90}
	};

	auto passed_students = students | std::views::filter([](const Student& s) { return s.grade >= 70; });

    for (const auto& student : passed_students | std::views::take(3))
    {
        std::cout << student.name << std::endl;
	}


}


