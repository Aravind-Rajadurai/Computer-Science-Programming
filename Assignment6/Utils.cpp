/*
 * Utils.cpp

 *
 *  Created on: Mar 20, 2018
 *      Author: two
 */

#include <fstream>
#include <iostream>
#include "Utils.h"

// The input files for building the customer, address vectors
const   std::string Utils::CUSTOMER_INPUT_FILE = "customers.csv";
const   std::string Utils::CUSTOMER_ADDRESS_INPUT_FILE = "addresses.csv";

Utils::Utils() {
	// nothing to do: we don't create an instance
}

//
// Returns the CustomerAddress whose id matches that stored in customer->getCustomerAddressId
// Uses binary search to search addresses vector -- addresses vector must be in sorted order by
//     address identifier
// Returns nullptr if address is not found
//
CustomerAddress * Utils:: findCustomerAddress (Customer *customer, std::vector <CustomerAddress *> addresses)  {
	int customerAddressId = customer->getCustomerAddressId();

	int lowerBound  = 0;
	int upperBound = addresses.size() - 1;
	int middle          = upperBound / 2;

	CustomerAddress *address = nullptr;
    
    while(lowerBound <= upperBound)
    {
        address = addresses.at(middle);
        
        int addressid = address -> getid();
        
        if(customerAddressId == addressid)
            return address;
        
        if(customerAddressId < addressid)
        {
            upperBound = middle -1;
        }
        else
        {
            lowerBound = middle +1;
        }
        middle = (lowerBound + upperBound)/2
    }
    
    return address;
}

//
// Links the customer to it's customer address, e.g., sets the pointer in customer to point to
// the CustomerAddress object whose id is stored in the customer instance
//
void Utils:: linkCustomersToAddresses (std::vector <Customer *> customers, std::vector <CustomerAddress*> addresses) {

    for(int = 0; i < customers.size(); i++)
    {
        Customer *customer = customers.at(i);
        CustomerAddress *addresses = Utils::findCustomerAddress(customer,addresses);
        customer -> setCustomerAddress(address);
        customer -> printWithAddress();
    }
}

// Reads the customer information from the file and creates
// Customer instances. Returns a vector of the instances
std::vector<Customer *> Utils::readCustomerData() {

    std::ifstream customerFile;
    std::vector<Customer*>customers;
    
    std::string header;
    customerFile.open(Utils::CUSTOMER_INPUT_FILE.c_str(), std::ios::in);
    std::getline(customerFile, header);
    
    while (customerFile) {
        // these variables hold input data used to create Customer objects
        std::string id;
        std::string address;
        std::string district;
        std::string city;
        std::string country;
        std::string postalCode;
        std::string phone;
        
        std::getline(addressFile, id, ',');
        std::getline(addressFile, address, ',');
        std::getline(addressFile, district, ',');
        std::getline(addressFile, city, ',');
        std::getline(addressFile, country, ',');
        std::getline(addressFile, postalCode, ',');
        std::getline(addressFile, phone, '\n');
        
        // Create new Customer, print it, put it in the vector
        Customer*customer = new Customer(id, address, district, city, country, postalCode, phone);
        customer->print();
        customers.push_back(customer);
    }
    return customerAddresses;
    
//	std::vector <Customer *> emptyVector;
//	return emptyVector;
}

std::vector<CustomerAddress *> Utils::readCustomerAddresses() {
	std::ifstream addressFile;   // file for reading address data
	std::vector<CustomerAddress *> customerAddresses;

	std::string header;
	addressFile.open(Utils::CUSTOMER_ADDRESS_INPUT_FILE.c_str(), std::ios::in);
	std::getline(addressFile, header);

	while (addressFile) {
		// these variables hold input data used to create CustomerAddress objects
		std::string id;
		std::string address;
		std::string district;
		std::string city;
		std::string country;
		std::string postalCode;
		std::string phone;

		std::getline(addressFile, id, ',');
		std::getline(addressFile, address, ',');
		std::getline(addressFile, district, ',');
		std::getline(addressFile, city, ',');
		std::getline(addressFile, country, ',');
		std::getline(addressFile, postalCode, ',');
		std::getline(addressFile, phone, '\n');

		// Create new CustomerAddress, print it, put it in the vector
		CustomerAddress *customerAddress = new CustomerAddress(id, address,
				district, city, country, postalCode, phone);
		customerAddress->print();
		customerAddresses.push_back(customerAddress);
	}
	return customerAddresses;
}

Utils::~Utils() {

}

