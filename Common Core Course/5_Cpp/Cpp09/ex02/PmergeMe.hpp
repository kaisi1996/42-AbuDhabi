#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <deque>
# include <string>
# include <iostream>
# include <utility>
# include <algorithm>
# include <climits>
# include <ctime>



#include <vector>

class CustomException : public std::runtime_error
{
	public:
		explicit CustomException(std::string msg): runtime_error(msg) {}
};

void	print_before(char **argv);

void	create_list(std::list<int> *list, char **argv);
void	sort_pairs(std::list<int>& list, int& order);
void	insert_into_main_chain(std::list<int>& list, std::list<int>& main_chain, int order);
void	print_after(std::list<int> main_chain);

void	create_deque2(std::deque<int> *deque, char **argv);
void	sort_pairs2(std::deque<int>& deque, int& order);
void	insert_into_main_chain2(std::deque<int>& deque, std::deque<int>& main_chain, int order);
void	print_after2(std::deque<int> main_chain);


#endif