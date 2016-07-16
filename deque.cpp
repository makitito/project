#include<iostream>
#include<deque>

using namespace std;

int main()
{
    std::deque<int> kaido{ 45, 78, 89, 67, 87, 34, 99, 76, 55, 44 };
	
    
    kaido.emplace_back(11); //Add at end
    
    kaido.emplace_front(0);//Adding at beginning
	
    
    for (int i = 0;i <kaido.size();++i) //Access elements - [] operator
        kaido[i] = kaido[i] * 2;
    
    
    for (int i = 0;i < kaido.size();++i) //Access elements - () function
        kaido.at(i) *= 10;
		
    cout << "First element:" << kaido.front() << endl;
   
    cout << "Last element:" << kaido.back() << endl;
    
    auto rbeginItr = kaido.rbegin(); //reverse iterators
    auto rendItr = kaido.rend();
    
    cout << "Reverse order: ";
    while (rbeginItr != rendItr)
    {
        std::cout << *rbeginItr << " ";
        ++rbeginItr;
    }
    std::cout << std::endl;
    return 0;
}