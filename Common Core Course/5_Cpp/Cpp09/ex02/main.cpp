#include "PmergeMe.hpp"


int	main(int argc, char **argv)
{
	if (argc < 2)
		return (std::cerr << "Not enough arguments provided\n", 1);
	
	// first approach: std::list
	{
		std::cout << "using std::list" << std::endl;
		clock_t start = clock();
		std::list<int> list;
		std::list<int> main_chain;
		std::vector<int> vect;
		
		try
		{
			print_before(argv);
			create_list(&list, argv);
			int order = 1;
			sort_pairs(list, order);
			insert_into_main_chain(list, main_chain, order);
			print_after(main_chain);
			
			clock_t end = clock();
			std::cout << "Time to process a range of " << main_chain.size() << " elements with std::list: " << static_cast<double>(end - start) / 1000 << " millisec" << std::endl << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	
	// second approach: std::deque
	{
		std::cout << "using std::deque" << std::endl;
		clock_t start = clock();
		std::deque<int> deque;
		std::deque<int> main_chain;
		int order = 1;

		try
		{
			print_before(argv);
			create_deque2(&deque, argv);
			sort_pairs2(deque, order);
			insert_into_main_chain2(deque, main_chain, order);
			print_after2(main_chain);
			
			clock_t end = clock();
			std::cout << "Time to process a range of " << main_chain.size() << " elements with std::deque: " << static_cast<double>(end - start) / 1000 << " millisec" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}
