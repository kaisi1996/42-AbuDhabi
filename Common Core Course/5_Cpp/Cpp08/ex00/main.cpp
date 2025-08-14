#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <cstdlib> 
#include <ctime>

template <typename T>
typename T::value_type seqcont_insert(T& cont, size_t size, size_t index)
{
        for (size_t i = 0; i < size; ++i)
        {
                typename T::value_type val = i * i;
                cont.push_back(val);
        }
        size_t i = 0;
        for (typename T::iterator it = cont.begin(); it != cont.end(); it++)
        {
            if(index == i++)
            {
                std::cout << "look for: " << *it << std::endl;
                return (static_cast<typename T::value_type>(*it));
            }
        }
        typename T::iterator it = cont.begin();
        return (static_cast<typename T::value_type>(*it));
}

template <typename T>
void find(T &cont, int n)
{
    try
    {
        typename T::iterator r = easyfind(cont, n);
        std::cout << "found : " << *r << " in the cointainer\n";
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

template <typename Container>
void printContainer(const Container& container) 
{
    
    for (typename Container::const_iterator it = container.begin(); it != container.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main(void)
{
        srand(static_cast<unsigned int>(time(NULL)));
        std::vector<int> vec;
        std::list<float> lst;
        std::deque<double> dq;
        std::vector<int> empt;

        int i = seqcont_insert(vec, 20, 4);
        float f = seqcont_insert(lst, 10, 7);
        double d = seqcont_insert(dq, 42, 11);
        
        std::cout << "\nprinting the container content\n";
        printContainer(vec);
        printContainer(lst);
        printContainer(dq);
        printContainer(empt);
        
        find(vec, i);
        find(lst, f);
        find(dq, d);

        std::cout << "\nTest : looking for 100 in empty container\n";
        find(empt, 100);
}