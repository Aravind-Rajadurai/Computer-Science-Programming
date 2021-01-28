/*
 * CustomerAddress.h
 *
 *  Created on: Mar 19, 2018
 *      Author: two
 */

#ifndef CUSTOMERADDRESS_H_
#define CUSTOMERADDRESS_H_

#include <string>
//
// CustomerAddress holds information on a Customer's home
// The Customer class references the CustomerAddress class
//  Customer has one unique CustomerAddress
//
class CustomerAddress {

private:
	int id;                                        // the unique id
	std::string address;                  // the street address
	std::string district;                   // a location within a city
	std::string city;                         // the city
	std::string country;                  // the country
	std::string postalCode;            // zip code (sorta)
	std::string phone;                    // phone number

	int stringToInt(std::string);

public:
	// Constructors
	CustomerAddress(int, std::string, std::string, std::string, std::string,
			std::string, std::string);
	CustomerAddress(std::string, std::string, std::string, std::string, std::string,
			std::string, std::string);

	// getters
	const std::string getAddress() const;
	const std::string getCity() const;
	const std::string getCountry() const;
	const std::string getDistrict() const;
	int getId() const;
	const std::string getPhone() const;
	const std::string getPostalCode() const;

	// utility function
	void print () const;

	// setters
	void setAddress(const std::string address);
	void setCity(const std::string city);
	void setCountry(const std::string country);
	void setDistrict(const std::string district);
	void setId(int id);
	void setPhone(const std::string phone);
	void setPostalCode(const std::string postalCode);

	// destructor
	virtual ~CustomerAddress();


};

#endif /* CUSTOMERADDRESS_H_ */
