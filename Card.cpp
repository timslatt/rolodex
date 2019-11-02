// Card.cpp
// Name: Tim Slatt
// Date: 10/26/19
// INFO.2680-061
// This program contains the functions performed on the individual cards in the rolodex

#include "Card.h"

using namespace std;

// default constructor
Card::Card()
{
	firstName = "";
	lastName = "";
	occupation = "";
	address = "";
	phoneNumber = "";
}

// copy constructor
Card::Card(const string& first, const string& last, const string& occ, const string& add, const string& phone)
{
	firstName = first;
	lastName = last;
	occupation = occ;
	address = add;
	phoneNumber = phone;
}

// set contact first name
void Card::setFirst(const string& first)
{
	firstName = first;
}

// get contact first name
string Card::getFirst() const
{
	return firstName;
}

// set contact last name
void Card::setLast(const string& last)
{
	lastName = last;
}

// get contact last name
string Card::getLast() const
{
	return lastName;
}

// set contact occupation
void Card::setOcc(const string& occup)
{
	occupation = occup;
}

// get contact occupation
string Card::getOcc() const
{
	return occupation;
}

// set contact address
void Card::setAddress(const string& add)
{
	address = add;
}

// get contact address
string Card::getAddress() const
{
	return address;
}

// set contact phone number
void Card::setPhone(const string& phone)
{
	phoneNumber = phone;
}

// get contact phone number
string Card::getPhone() const
{
	return phoneNumber;
}

// show all card info to console
void Card::show(ostream& os)
{
	os << "\nName: " << getLast() << ", " << getFirst() << "\nOccupation: " << getOcc() <<
		  "\nAddress: " << getAddress() << "\nPhone Number: " << getPhone() << endl;
}

