#include "PmergeMe.hpp"


////////////////////////// shared functions ///////////////////////////////////

void print_before(char **argv)
{
	int i = 1;
	int error = 0;

	std::cout << "Before: ";
	while (argv[i])
	{
		std::string input = argv[i];
		std::cout << input << " ";
		if (input.size() > 10 || std::atol(input.c_str()) > INT_MAX || std::atol(input.c_str()) < 0)
			error = 1;
		for (size_t j = 0; j < input.size(); j++)
		{
			if (!isdigit(input[j]))
				error = 1;
		}
		i++;
	}
	std::cout << "\n";
	if (error == 1)
		throw CustomException("Error: input is invalid");
}


////////////////////////// List functions //////////////////////////////////////

void create_list(std::list<int> *list, char **argv)
{
	int i = 1;
	std::list<int>::iterator it;

	while (argv[i])
	{
		it = std::find(list->begin(), list->end(), std::atoi(argv[i]));
		if (it != list->end()) 
			throw CustomException("Error: input has a duplicate value!");
		list->push_back(std::atoi(argv[i]));
		i++;
	}
}

void sort_pairs(std::list<int>& list, int& order)
{
	std::list<int>::iterator it0 = list.begin();
	std::list<int>::iterator it1 = list.begin();
	std::list<int>::iterator it2 = list.begin();
	int size = list.size();
	
	while (order * 2 <= size)
	{
		it0 = list.begin();
		it1 = list.begin();
		it2 = list.begin();
		std::advance(it1, order - 1);
		std::advance(it2, order * 2 - 1);
		for (int i = 0; i < size / (order * 2); i++)
		{
			if (order != 1)
			{
				if (*it1 > *it2)
				{
					std::advance(it1, 1);
					std::advance(it2, 1);
					list.splice(it2, list, it0, it1);
					if (i != size / (order * 2) - 1)
					{
						std::advance(it0, order);
						std::advance(it1, order * 3 - 1);
						std::advance(it2, order * 2 - 1);
					}
				}
				else
				{
					if (i != size / (order * 2) - 1)
					{
						std::advance(it0, order * 2);
						std::advance(it1, order * 2);
						std::advance(it2, order * 2);
					}
				}
			}
			else
			{
				if (*it1 > *it2)
				{
					std::swap(*it1, *it2);
				}
				if (i != size / (order * 2) - 1)
				{
					std::advance(it1, order * 2);
					std::advance(it2, order * 2);
				}
			}
		}
		order *= 2;
	}
	order /= 2;
}

void binary_search_insertion(std::list<int>& main_chain, std::list<int>::iterator end, int val)
{
	std::list<int>::iterator place_to_insert = std::lower_bound(main_chain.begin(), end, val);
	main_chain.insert(place_to_insert, val);
}

void insert_into_main_chain(std::list<int>& list, std::list<int>& main_chain, int order)
{
	size_t Jacobsthal[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765};
	int jacobsthal_idx = 1;
	std::list< std::pair<int, int> > main_pend;
	std::list<int>::iterator it1 = list.begin();
	std::list<int>::iterator it2 = list.begin();
	std::list< std::pair<int, int> >::iterator itp = main_pend.begin();
	std::list<int>::iterator itm_end;
	const int max_order = order;
	const int size = list.size();
	size_t size_pend;
	int j;

	if (++it1 == list.end())
	{
		main_chain.push_back(*(--it1));
		return;
	}
	while (order >= 1)
	{
		it1 = list.begin();
		it2 = list.begin();
		std::advance(it1, order - 1);
		std::advance(it2, order * 2 - 1);
		jacobsthal_idx = 1;
		//
		// get pend and main chains
		//
		for (int i = order; i <= size; i += order * 2)
		{
			if (i + order <= size && i == order && order == max_order)
			{
				main_chain.push_back(*it2);
				main_pend.push_back(std::make_pair(*it2, *it1));
				std::advance(it1, order * 2);
				std::advance(it2, order * 2);
			}
			else if (i == order && order == max_order)
			{
				main_pend.push_back(std::make_pair(-1, *it1));
			}
			else if (i + order <= size)
			{
				main_pend.push_back(std::make_pair(*it2, *it1));
				std::advance(it1, order * 2);
				std::advance(it2, order * 2);
			}
			else
			{
				main_pend.push_back(std::make_pair(-1, *it1));
			}
		}
		size_pend = main_pend.size();
		itp = main_pend.begin();
		j = 1;
		//
		// insert pend to main chain
		//
		while (!main_pend.empty())
		{
			if (j == 1)
			{
				main_chain.push_front(itp->second);
				itp = main_pend.erase(itp);
			}
			if (Jacobsthal[jacobsthal_idx] > size_pend)
			{
				j = 0;
				while (!main_pend.empty())
				{
					itp = main_pend.end();
					itp--;
					itm_end = std::find(main_chain.begin(), main_chain.end(), itp->first);
					if (itp->first == -1)
						binary_search_insertion(main_chain,  main_chain.end(), itp->second);
					else
					{
						itm_end++;
						binary_search_insertion(main_chain, itm_end, itp->second);
					}
					itp = main_pend.erase(itp);
				}
			}
			else
			{
				j = Jacobsthal[jacobsthal_idx] - Jacobsthal[jacobsthal_idx - 1];
				itp = main_pend.begin();
				std::advance(itp, j);
				while (j != 0)
				{
					itp--;
					itm_end = std::find(main_chain.begin(), main_chain.end(), itp->first);
					if (itp->first == -1)
						binary_search_insertion(main_chain,  main_chain.end(), itp->second);
					else
					{
						itm_end++;
						binary_search_insertion(main_chain,  itm_end, itp->second);
					}
					itp = main_pend.erase(itp);
					j--;

				}
				jacobsthal_idx++;
			}
			j = 2;
		}
		order /= 2;
	}
}

void print_after(std::list<int> main_chain)
{
	std::cout << "After: ";
	for (std::list<int>::iterator it = main_chain.begin(); it != main_chain.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << '\n';
}


////////////////////////// Deque functions /////////////////////////////////////

void create_deque2(std::deque<int> *deque, char **argv)
{
	int i = 1;
	std::deque<int>::iterator it;

	while (argv[i])
	{
		it = std::find(deque->begin(), deque->end(), std::atoi(argv[i]));
		if (it != deque->end()) 
			throw CustomException("Error: input has a duplicate value!");
		deque->push_back(std::atoi(argv[i]));
		i++;
	}
}

void sort_pairs2(std::deque<int>& deque, int& order)
{
	std::deque<int>::iterator it1 = deque.begin();
	std::deque<int>::iterator it2 = deque.begin();
	int size = deque.size();
	int count;
	
	while (order * 2 <= size)
	{
		it1 = deque.begin();
		it2 = deque.begin();
		std::advance(it1, order - 1);
		std::advance(it2, order * 2 - 1);
		for (int i = 0; i < size / (order * 2); i++)
		{
			if (order != 1)
			{
				if (*it1 > *it2)
				{
					count = order;
					while (count != 0)
					{
						std::swap(*it1, *it2);
						it2--;
						it1--;
						count--;
					}
					if (i != size / (order * 2) - 1)
					{
						std::advance(it1, order * 3);
						std::advance(it2, order * 3);
					}
				}
				else
				{
					if (i != size / (order * 2) - 1)
					{
						std::advance(it1, order * 2);
						std::advance(it2, order * 2);
					}
				}
			}
			else
			{
				if (*it1 > *it2)
				{
					std::swap(*it1, *it2);
				}
				if (i != size / (order * 2) - 1)
				{
					std::advance(it1, order * 2);
					std::advance(it2, order * 2);
				}
			}
		}
		order *= 2;
	}
	order /= 2;
}

void binary_search_insertion2(std::deque<int>& main_chain, std::deque<int>::iterator end, int val)
{
	std::deque<int>::iterator place_to_insert = std::lower_bound(main_chain.begin(), end, val);
	main_chain.insert(place_to_insert, val);
}


void insert_into_main_chain2(std::deque<int>& deque, std::deque<int>& main_chain, int order)
{
	size_t Jacobsthal[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765};
	int jacobsthal_idx = 1;
	std::deque< std::pair<int, int> > main_pend;
	std::deque<int>::iterator it1 = deque.begin();
	std::deque<int>::iterator it2 = deque.begin();
	std::deque< std::pair<int, int> >::iterator itp = main_pend.begin();
	std::deque<int>::iterator itm_end;
	const int max_order = order;
	const int size = deque.size();
	size_t size_pend;
	int j;

	if (++it1 == deque.end())
	{
		main_chain.push_back(*(--it1));
		return;
	}
	while (order >= 1)
	{
		it1 = deque.begin();
		it2 = deque.begin();
		std::advance(it1, order - 1);
		std::advance(it2, order * 2 - 1);
		jacobsthal_idx = 1;
		//
		// get pend and main chains
		//
		for (int i = order; i <= size; i += order * 2)
		{
			if (i + order <= size && i == order && order == max_order)
			{
				main_chain.push_back(*it2);
				main_pend.push_back(std::make_pair(*it2, *it1));
				std::advance(it1, order * 2);
				std::advance(it2, order * 2);
			}
			else if (i == order && order == max_order)
			{
				main_pend.push_back(std::make_pair(-1, *it1));
			}
			else if (i + order <= size)
			{
				main_pend.push_back(std::make_pair(*it2, *it1));
				std::advance(it1, order * 2);
				std::advance(it2, order * 2);
			}
			else
			{
				main_pend.push_back(std::make_pair(-1, *it1));
			}
		}
		size_pend = main_pend.size();
		itp = main_pend.begin();
		j = 1;
		//
		// insert pend to main chain
		//
		while (!main_pend.empty())
		{
			if (j == 1)
			{
				main_chain.push_front(itp->second);
				itp = main_pend.erase(itp);
			}
			if (Jacobsthal[jacobsthal_idx] > size_pend)
			{
				j = 0;
				while (!main_pend.empty())
				{
					itp = main_pend.end();
					itp--;
					itm_end = std::find(main_chain.begin(), main_chain.end(), itp->first);
					if (itp->first == -1)
						binary_search_insertion2(main_chain,  main_chain.end(), itp->second);
					else
					{
						itm_end++;
						binary_search_insertion2(main_chain, itm_end, itp->second);
					}
					itp = main_pend.erase(itp);
				}
			}
			else
			{
				j = Jacobsthal[jacobsthal_idx] - Jacobsthal[jacobsthal_idx - 1];
				itp = main_pend.begin();
				std::advance(itp, j);
				while (j != 0)
				{
					itp--;
					itm_end = std::find(main_chain.begin(), main_chain.end(), itp->first);
					if (itp->first == -1)
						binary_search_insertion2(main_chain,  main_chain.end(), itp->second);
					else
					{
						itm_end++;
						binary_search_insertion2(main_chain,  itm_end, itp->second);
					}
					itp = main_pend.erase(itp);
					j--;

				}
				jacobsthal_idx++;
			}
			j = 2;
		}
		order /= 2;
	}
}

void print_after2(std::deque<int> main_chain)
{
	std::cout << "After: ";
	for (std::deque<int>::iterator it = main_chain.begin(); it != main_chain.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << '\n';
}
