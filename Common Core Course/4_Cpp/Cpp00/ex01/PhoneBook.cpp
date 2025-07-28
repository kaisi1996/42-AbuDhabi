#include "PhoneBook.hpp"
#include <cstdlib>


PhoneBook::PhoneBook()
{
	numOfContacts = 0;
	counter = 0;
}
PhoneBook::~PhoneBook()
{

}

int	PhoneBook::getNumOfContacts()
{
	return (numOfContacts);
}

Contact PhoneBook::createContact()
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

	std::cout << "First Name: ";
	if(!std::getline(std::cin >> std::ws, firstName))
		exit(0);
	std::cout << "Last Name: ";
	if(!std::getline(std::cin >> std::ws, lastName))
		exit(0);
	std::cout << "Nick Name: ";
	if(!std::getline(std::cin >> std::ws, nickName))
		exit(0);
	std::cout << "Phone Number: ";
	if(!std::getline(std::cin >> std::ws, phoneNumber))
		exit(0);
	std::cout << "Darkest Secret: ";
	if(!std::getline(std::cin >> std::ws, darkestSecret))
		exit(0);

	Contact newContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	return (newContact);
}

void	PhoneBook::addContact(Contact &contact)
{
	if (counter == MAX_CONTACT)
		counter = 0;
	if (numOfContacts < MAX_CONTACT)
		numOfContacts++;
	contacts[counter++] = contact;
}

void    PhoneBook::print(const std::string &str)
{
    if (str.length() <= 10)
    {
        for (int x = 0; x < (10 - (int)str.length()); x++)
			std::cout << " ";
		std::cout << str;
    }
    else
    {
        std::cout <<  str.substr(0, 9) + ".";
    }
}
void PhoneBook::displayContacts()
{
    for (int i = 0; i < numOfContacts; i++)
    {
        std::cout << "         " << i << "|";
        print(contacts[i].getFirstName());
        std::cout << "|";
        print(contacts[i].getLastName());
        std::cout << "|";
        print(contacts[i].getNickName());
        std::cout << std::endl;
    }
}

void    PhoneBook::chooseContact(int index)
{
    if (index < 0 || index >= numOfContacts)
    {
        std::cout << "Invalid index" << std::endl;
		return;
    }
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nick Name: " << contacts[index].getNickName() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}
