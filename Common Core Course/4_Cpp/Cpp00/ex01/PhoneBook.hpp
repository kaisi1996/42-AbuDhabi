#ifndef PHONEBOOK_HPP  
#define PHONEBOOK_HPP

#include <iostream>

#include "Contact.hpp"

# define MAX_CONTACT 8

class PhoneBook{
private:
    Contact	contacts[8];
    int	numOfContacts;
    int	counter;
public:
    PhoneBook();
	~PhoneBook();
    Contact createContact();
    void	addContact(Contact &contact);
    int     getNumOfContacts();
    void    displayContacts();
    void    chooseContact(int index);
    void    print(const std::string &str);
};

#endif