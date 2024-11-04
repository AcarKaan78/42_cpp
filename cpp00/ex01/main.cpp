#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
	PhoneBook phonebook;

	std::string command;
	
	std::cout 
		<< "ADD : Add a contact" << "\n"
		<< "SEARCH : Search a contact" << "\n"
		<< "EXIT : Exit the PhoneBook" <<  "\n" 
	<< std::endl;

	while (true)
	{
	
		std::cout << "Command : ";
		
		if (std::getline(std::cin, command).fail() == 1)
		{
			std::cout << " " << std::endl;
			break;
		}
		else
		{
			if (command == "ADD")
			{
				phonebook.addContact();
			}
			else if (command == "SEARCH")
			{
				phonebook.searchContact();
			}
			else if (command == "EXIT")
			{
				break;
			}
			else
			{
				std::cout << "\nUnknow command\n" << std::endl;
			}
		}
	}
	return (0);
}
