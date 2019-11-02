#include <string>
#include <ostream>

using namespace std;

#ifndef CARD_H
#define CARD_H

class Card
{
private:

	string firstName;
	string lastName;
	string occupation;
	string address;
	string phoneNumber;

public:

	Card();
	Card(const string& first, const string& last, const string& occ, const string& add, const string& phone);
	void setFirst(const string& first);
	string getFirst() const;
	void setLast(const string& last);
	string getLast() const;
	void setOcc(const string& occup);
	string getOcc() const;
	void setAddress(const string& add);
	string getAddress() const;
	void setPhone(const string& phone);
	string getPhone() const;

	void show(ostream& os);


};




#endif
