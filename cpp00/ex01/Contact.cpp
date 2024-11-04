#include "Contact.hpp"
#include <iostream>

Contact::Contact() { }

Contact::~Contact() { }

void Contact::setFirstName(const std::string firstName) 
{ 
	this->_firstName = firstName; 
}

void Contact::setLastName(const std::string lastName)
{ 
	this->_lastName = lastName; 
}

void Contact::setNickName(const std::string nickName) 
{ 
	this->_nickName = nickName; 
}

void Contact::setPhoneNumber(const std::string phoneNumber) 
{ 
	this->_phoneNumber = phoneNumber; 
}

void Contact::setDarkestSecret(const std::string darkestSecret) 
{ 
	this->_darkestSecret = darkestSecret; 
}

const std::string Contact::getFirstName() const 
{ 
	return this->_firstName;
}

const std::string Contact::getLastName() const 
{ 
	return this->_lastName;
}

const std::string Contact::getNickName() const 
{ 
	return this->_nickName;
}

const std::string Contact::getPhoneNumber() const 
{ 
	return this->_phoneNumber;
}

const std::string Contact::getDarkestSecret() const 
{ 
	return this->_darkestSecret;
}
