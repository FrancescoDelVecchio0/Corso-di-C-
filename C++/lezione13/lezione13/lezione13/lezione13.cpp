
#include <thread>
#include<vector>
#include <mutex>
#include <iostream>



std::vector<int> shared_list;
std::mutex list_mtx;


void add_numbers(int start, int end)
{
    for (int i = start; i < end; ++i)
    {
        std::scoped_lock lock(list_mtx); 
        shared_list.push_back(i);
    }
}



int main()
{
   
	std::jthread t1(add_numbers, 0, 10);
	std::jthread t2(add_numbers, 10, 20);
	
	t1.join();
    t2.join();
    

	std::cout << "Lista finale contiene " << shared_list.size() << " elementi: ";

    for (int num : shared_list)
    {
        std::cout << num << " ";
    }
	std::cout << std::endl;
	return 0;
}

