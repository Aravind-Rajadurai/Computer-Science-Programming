/*
 * Address.cpp

 *
 *  Created on: Mar 19, 2018
 *      Author: two
 */
#include "CustomerAddress.h"

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>

CustomerAddress::CustomerAddress(int id, std::string address, std::string district,
		std::string city, std::string country, std::string postalCode,
		std::string phone) {
	this->id = id;
	this->address = address;
	this->city = city;
	this->country = country;
	this->district = district;
	this->phone = phone;
	this->postalCode = postalCode;
}

CustomerAddress::CustomerAddress(std::string id, std::string address,
		std::string district, std::string city, std::string country,
		std::string postalCode, std::string phone) {
	this->id = stringToInt(id);
	this->address = address;
	this->city = city;
	this->country = country;
	this->district = district;
	this->phone = phone;
	this->postalCode = postalCode;
}



const std::string CustomerAddress::getAddress() const {
	return address;
}

const std::string CustomerAddress::getCity() const {
	return city;
}

const std::string CustomerAddress::getCountry() const {
	return country;
}

const std::string CustomerAddress::getDistrict() const {
	return district;
}

int CustomerAddress::getId() const {
	return id;
}

const std::string CustomerAddress::getPhone() const {
	return phone;
}

const std::string CustomerAddress::getPostalCode() const {
	return postalCode;
}

void CustomerAddress::print ()  const {
	std::cout << "CustomerAddress [ id: " << id <<
			", address: "       << address      <<
			", city: "              << city             <<
			", district: "        << district        <<
			", country: "       << country       <<
			", postal code: " << postalCode <<
			", phone: "         << phone         <<
			"] " << std::endl;
}

void CustomerAddress::setAddress(const std::string address) {
	this->address = address;
}

void CustomerAddress::setCity(const std::string city) {
	this->city = city;
}

void CustomerAddress::setCountry(const std::string country) {
	this->country = country;
}

void CustomerAddress::setDistrict(const std::string district) {
	this->district = district;
}

void CustomerAddress::setId(int id) {
	this->id = id;
}

void CustomerAddress::setPhone(const std::string phone) {
	this->phone = phone;
}

void CustomerAddress::setPostalCode(const std::string postalCode) {
	this->postalCode = postalCode;
}

CustomerAddress::~CustomerAddress() {
	// TODO Auto-generated destructor stub
}

int CustomerAddress::stringToInt(std::string aString) {
	int aValue = atoi(aString.c_str());
	std::stringstream converter(aString);
	int intValue;
	converter >> intValue;
	return intValue;
}
