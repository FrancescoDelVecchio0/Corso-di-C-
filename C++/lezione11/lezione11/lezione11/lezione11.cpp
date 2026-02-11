
#include <stdio.h>
#include <utility>
#include <iostream>
#include <string>
#include <concepts>



template <typename T>
concept OnlyString = requires(T b) {
	std::cout << b;
};

template <typename T>
concept OnlyStringC = requires(T a) {
	std::cout << a
	{ a }->std::convertible_to<std::string>;
};
template <typename T>

class Box {
	
private:
	T value;
public:

	// universal reference constructor
	
	template <typename U>
	explicit Box(U&& newValue) : value(std::forward<U>(newValue)) {}

	[[nodiscard]] auto GetValue() const noexcept {
		return value;
	}


	// universal reference set
	template <typename U>
	void GetValue(U&& newValue) {
		value = std::forward<U>(newValue);
	}


	



};


int main()
{
	auto box1 = Box<int>(42);

	box1.GetValue(100);
	std::cout << "value:" << box1.GetValue() << std::endl;


	std::string str = "Hello, World!";
	auto box2 = Box<std::string>(std::move( str));
	std::cout << "value:" << box2.GetValue() << std::endl;
	double d = 3.14;
	auto box3 = Box<double>(d);
	std::cout << "value:" << box3.GetValue() << std::endl;
	auto box4 = Box<std::string>("Piero e Pongo");
	std::cout << "value:" << box4.GetValue() << std::endl;
}

