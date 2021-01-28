/*
 * Customer.h
 *
 *  Created on: Mar 20, 2018
 *      Author: two
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include "CustomerAddress.h"

//
//   This class holds information on a single customer
//
//    The class references another class that is the customer
//    address (CustomerAddress). Until the Customer instance
//    and CustomerAddress instance are "linked up", the customerAddress
//    pointer is null.
//
//    The "linking up" process requires that the CustomerAddress pointer in
//     Customer be validly set to reference a  CustomerAddress object.
//     That CustomerAddress object is identified by the int value customerAddressId
//     read in from the data file and stored in the Customer object
//
class Customer {
private:
	int id;                                    // the unique id
	std::string firstName;           // customer first name
	std::string lastName;           // customer last name
	std::string emailAddress;    //  customer email address
	int customerAddressId;       // id of the CustomerAddress object
	CustomerAddress *customerAddress = nullptr;

	int stringToInt (std::string);

public:
	// Constructors
	Customer(std::string id, std::string firstName, std::string lastName, std::string emailAddress, std::string customerAddressId);
	Customer(int id, std::string firstName, std::string lastName, std::string emailAddress, CustomerAddress*);

	// getters
	const CustomerAddress* getCustomerAddress() const;
	int getCustomerAddressId() const;
	const std::string getEmailAddress() const;
	const std::string getFirstName() const;
	int getId() const;
	const std::string getLastName() const;

	// utility methods
	void print () const;
	void printWithAddress () const;

	// setters
	void setCustomerAddress( CustomerAddress* customerAddress = nullptr);
	void setCustomerAddressId(int customerAddressId);
	void setEmailAddress(const std::string emailAddress);
	void setFirstName(const std::string firstName);
	void setId(int id);
	void setLastName(const std::string lastName);

   // destructor
	virtual ~Customer();
};

#endif /* CUSTOMER_H_ */
