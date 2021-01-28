/*
 * Utils.h
 *
 *  Created on: Mar 20, 2018
 *      Author: two
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <string>
#include <vector>
#include "Customer.h"
#include "CustomerAddress.h"
class Utils {
public:
	// The files the program reads to build the customer and customer
	// address vectors; values assigned in .cpp file
	 const static std::string CUSTOMER_INPUT_FILE;
	 const static std::string CUSTOMER_ADDRESS_INPUT_FILE;

	Utils();
	static CustomerAddress* findCustomerAddress (Customer *, std::vector <CustomerAddress *>) ;
	static void linkCustomersToAddresses (std::vector <Customer *>, std::vector <CustomerAddress*>);
	static std::vector <Customer *>  readCustomerData ();
	static std::vector <CustomerAddress *> readCustomerAddresses ();
	virtual ~Utils();
};

#endif /* UTILS_H_ */
