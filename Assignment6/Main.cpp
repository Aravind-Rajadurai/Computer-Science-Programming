/*
 * Main.cpp
 *
 *  Created on: Mar 20, 2018
 *      Author: two
 */
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "CustomerAddress.h"
#include "Utils.h"

int main () {
	std::vector <Customer *> customers = Utils::readCustomerData();
	std::vector <CustomerAddress *> addresses = Utils::readCustomerAddresses();
    Utils::linkCustomersToAddresses(customers, addresses);
}


