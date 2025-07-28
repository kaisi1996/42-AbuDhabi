#include "Contact.hpp"


Contact::Contact()
{
	firstName = "";
	lastName = "";
	nickName = "";
	phoneNumber = "";
	darkestSecret = "";
};

Contact::Contact(std::string fName, std::string lName, std::string nName, std::string pNumber, std::string dSecret)
{
	firstName = fName;
	lastName = lName;
	nickName = nName;
	phoneNumber = pNumber;
	darkestSecret = dSecret;
}

void	Contact::setAll(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
	this->firstName = firstName;
    this->lastName = lastName;
    this->nickName = nickName;
    this->phoneNumber = phoneNumber;
    this->darkestSecret = darkestSecret;
}

std::string	Contact::getFirstName()
{
	return (firstName);
}

std::string	Contact::getLastName()
{
	return (lastName);
}

std::string Contact::getNickName()
{
	return (nickName);
}

std::string Contact::getPhoneNumber()
{
	return (phoneNumber);
}

std::string	Contact::getDarkestSecret()
{
	return (darkestSecret);
}
