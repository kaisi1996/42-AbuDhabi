#include "iter.hpp"

void power_two(int &iter)
{
	iter *= iter;
}

void to_upper(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
}

int main( void )
{
	std::cout << "Test 1: int array" << std::endl;
	int int_arr[] = {4, 7, 9, 12};

	::iter(int_arr, 4, power_two);
	for (int i = 0; i < 4; i++)
		std::cout << int_arr[i] << std::endl;

	std::cout << "Test 2: string array" << std::endl;
	std::string str_arr[] = {"Abdulrahman", "Marwan", "Alkaisi"};
	::iter(str_arr, 3, to_upper);
	for (int i = 0; i < 3; i++)
		std::cout << str_arr[i] << std::endl;

	return 0;
}