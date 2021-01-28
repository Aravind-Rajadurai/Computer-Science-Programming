/*
 * Customer.cpp
 *
 *  Created on: Mar 20, 2018
 *      Author: two
 */
#include <sstream>
#include <iostream>
#include "Customer.h"

Customer::Customer(std::string id, std::string firstName, std::string lastName,
		std::string emailAddress, std::string customerAddressId) {
	this->id = stringToInt(id);
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->customerAddressId = stringToInt(customerAddressId);
	this->customerAddress     = nullptr;
}

Customer::Customer(int id, std::string firstName, std::string lastName,
		std::string emailAddress, CustomerAddress *customerAddress) {
	this->id = id;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->customerAddress = customerAddress;
	if (customerAddress != nullptr) this->customerAddressId = customerAddress->getId();
	else customerAddressId = -1;
}

const CustomerAddress* Customer::getCustomerAddress() const {
	return customerAddress;
}

int Customer::getCustomerAddressId() const {
	return customerAddressId;
}

const std::string Customer::getEmailAddress() const {
	return emailAddress;
}

const std::string Customer::getFirstName() const {
	return firstName;
}

int Customer::getId() const {
	return id;
}

const std::string Customer::getLastName() const {
	return lastName;
}

void Customer::print () const {
	std::cout << "Customer [ id: "  << id <<
			", firstName: "        << firstName                <<
			", lastName: "        << lastName                 <<
			", email Address: " << emailAddress          <<
			", address id: "       << customerAddressId <<
			"]" << std::endl;
}
void Customer::printWithAddress() const {
	  this->print();
      if (customerAddress != nullptr) {
    	  std::cout << "---- address: " ;
    	  customerAddress->print();
    	  std::cout << std::endl << std::endl;
      }
}

void Customer::setCustomerAddress( CustomerAddress* customerAddress ) {
	this->customerAddress = customerAddress;
}

void Customer::setCustomerAddressId(int customerAddressId) {
	this->customerAddressId = customerAddressId;
}

void Customer::setEmailAddress(const std::string emailAddress) {
    this->emailAddress = emailAddress;
}

void Customer::setFirstName(const std::string firstName) {
    this->firstName = firstName;
}

void Customer::setId(int id) {
   this->id = id;
}

void Customer::setLastName(const std::string lastName) {
   this->lastName = lastName;
}

Customer::~Customer() {

}

int Customer::stringToInt(std::string aString) {
	std::stringstream converter(aString);
	int intValue;
	converter >> intValue;
	return intValue;
}
