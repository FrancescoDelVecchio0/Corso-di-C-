
#include <iostream>
#include <vector>
#include <string>
 #include <algorithm>



int main()
{
    int multipler = 5;
	auto result = [multipler](int n) { return n * multipler; }(10);
    std::cout << "Result: " << result << std::endl;



	


	


	int contatore = 0;
	[&contatore]() { contatore += 1; }();
	for(int i = 0; i<10; i++)
	{
		[&contatore]() { contatore += 1; }();
		std::cout << contatore << " \n";
	
	}



	std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::transform(numbers.begin(), numbers.end(), numbers.begin(),
		[contatore](int n) { return n * contatore; });


	return 0;

}
