#include "PhoneBook.hpp"
#include <limits>
#include <cstdlib>

void	printMenu()
{
	std::cout << "Please Enter a command (ADD, SEARCH, EXIT): " << std::endl;
}

void    addContact(PhoneBook &phoneBook)
{
    Contact newContact;

    newContact = phoneBook.createContact();
	phoneBook.addContact(newContact);
	printMenu();
}

void	contactHeader()
{
	std::cout << "     index|first name| last name|  nickname\n";
	std::cout << "----------|----------|----------|----------\n";
}
void	contactFooter()
{
	std::cout << "-------------------------------------------\n";
}

int	takeIndex(PhoneBook &phoneBook)
{
	int	index;
	while (true)
	{
		std::cout << "Enter the index of the contact you want to view: ";
		if (std::cin >> index && index >= 0 && index < phoneBook.getNumOfContacts())
		{
			break ;
		}
		else if (std::cin.eof())
			exit (0);
		else if (std::cin.fail() || index < 0 || index >= phoneBook.getNumOfContacts())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid index, please try again\n";
		}
	}
	return index;
}
void	SearchContact(PhoneBook &phoneBook)
{
	int	numOfContacts;
	int	index;

	numOfContacts = phoneBook.getNumOfContacts();
	if (numOfContacts == 0)
	{
		std::cout << "No contacts available" << std::endl;
		printMenu();
		return ;
	}
	contactHeader();
	phoneBook.displayContacts();
	contactFooter();
	index = takeIndex(phoneBook);
	phoneBook.chooseContact(index);
	printMenu();
}

int main()
{
	PhoneBook	phoneBook;
	std::string	input;

	printMenu();

	while (true)
	{
		if(!(getline(std::cin, input)))
			break ;
		if (input == "ADD" )
			addContact(phoneBook);
		else if (input == "SEARCH")
			SearchContact(phoneBook);
		else if (input == "EXIT")
			break ;
	}
	return (0);
}

