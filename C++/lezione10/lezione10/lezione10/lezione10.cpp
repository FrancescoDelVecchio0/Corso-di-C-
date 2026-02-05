#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

int main()
{
	auto now = std::chrono::system_clock::now();
	//std::time_t t_now = system_clock::to_time_t(now);
	
	std:tm tm_now{};
	//localtime_s(&tm_now, &t_now);

    std::cout << "Data: " << std::put_time(&tm_now, "%Y-%m-%d") << '\n';
	
	std::cout << "Ora: " << std::put_time(&tm_now, "%H:%M:%S") << '\n';
	

	//funzione
	std::time_t t = std::chrono::system_clock::to_time_t(now);
	std::tm* tm = new std::tm;	
	localtime_s(tm, &t);
	std::cout << "Data e ora corrente: " << std::put_time(tm, "%Y-%m-%d %H:%M:%S") << '\n';




	//auto future = now + hour(24 * 7);
	auto future = now + std::chrono::hours(24 * 7);
	std::time_t t_future = std::chrono::system_clock::to_time_t(future);
	std::tm tm_future{};
	localtime_s(&tm_future, &t_future);
	std::cout << "Tra 7 giorni; " << std::put_time(&tm_future, "%Y-%m-%d %H:%M:%S") << '\n';


	return 0;
}
