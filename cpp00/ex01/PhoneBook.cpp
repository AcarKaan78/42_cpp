#include "PhoneBook.hpp"
#include "util.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : _contactCount(0), _contactIndex(0)
{
		std::cout << \
		"Welcome to Crappy! Created an empty phonebook for up to 8 contacts" \
		<< std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook destroyed,See you soon!"  << std::endl;
}

bool PhoneBook::getInput(const std::string& prompt, std::string& input)
{
    std::cout << prompt;
    if (std::getline(std::cin, input))
    {
        if (input.empty())
        {
            std::cout << "\nInput cannot be empty.\n" << std::endl;
            return false;
        }
        return true;
    }
    else
    {
        if (std::cin.eof())
        {
			std::cout << " " << std::endl;
			this->~PhoneBook();
            exit(0);
        }
        std::cin.clear();
        return false;
    }
}

void PhoneBook::addContact()
{
    Contact contact;
    std::string input;

    std::cout << " " << std::endl;

    while (!getInput("First Name: ", input)) {}
    contact.setFirstName(input);

    while (!getInput("Last Name: ", input)) {}
    contact.setLastName(input);

    while (!getInput("Nick Name: ", input)) {}
    contact.setNickName(input);

    while (!getInput("Phone Number: ", input)) {}
    contact.setPhoneNumber(input);

    while (!getInput("Darkest Secret: ", input)) {}
    contact.setDarkestSecret(input);

    this->insertContact(contact);
    std::cout << "\nContact added with success!\n" << std::endl;
}

void PhoneBook::insertContact(const Contact &contact)
{	
	if (this->_contactIndex == 8)
		this->_contactIndex = 0;
	this->_contacts[this->_contactIndex] = contact;
	this->_contactIndex++;
	if (this->_contactCount < 8)
		this->_contactCount++;
}

void PhoneBook::searchContact() const
{
	int index;
	std::string input;

	if (this->_contactCount == 0)
	{
		std::cout << "\nPhoneBook is empty.\n" << std::endl;
		return;
	}
	else
	{
		this->displayContacts();
	}

	do
	{
		std::cout << "Search a contact with index : ";
        if (!std::getline(std::cin, input))
        {
            std::cout << " " << std::endl;
            exit(0);
        }
		if (!input.empty())
		{
			try
			{
				index = std::stoi(input);
				if (index < 0 || index >= this->_contactCount)
				{
					std::cout << "\nContact not found.\n" << std::endl;
				}
				else
				{
					break;
				}
			}
			catch (const std::invalid_argument &e)
			{
				std::cout << "\nPlease enter a numeric index.\n" << std::endl;
			}
		}
		else
		{
			std::cout << "\nIndex cannot be empty.\n" << std::endl;
		}
	} while (true);

	this->displayContact(index);
}

void PhoneBook::displayContacts() const
{

	std::cout
		<< "\n"
		<< std::setw(10) << "Index" << "|"
		<< std::setw(10) << "FirstName" << "|"
		<< std::setw(10) << "LastName" << "|"
		<< std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < this->_contactCount; i++)
	{
		std::cout
			<< std::setw(10) << i << "|"
			<< std::setw(10) << formatField(_contacts[i].getFirstName()) << "|"
			<< std::setw(10) << formatField(_contacts[i].getLastName()) << "|"
			<< std::setw(10) << formatField(_contacts[i].getNickName()) << std::endl;
	}

	std::cout << " " << std::endl;
}

void PhoneBook::displayContact(int i) const
{
	Contact contact;

	contact = this->_contacts[i];
	std::cout
		<< "\n"
		<< "FirstName : " << contact.getLastName() << "\n"
		<< "LastName : " << contact.getLastName() << "\n"
		<< "Nickname : " << contact.getNickName() << "\n"
		<< "PhoneNumber : " << contact.getPhoneNumber() << "\n"
		<< "DarkestSecret : " << contact.getDarkestSecret() << "\n"
		<< std::endl;
}
