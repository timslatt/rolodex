#include "Card.h"
#include <list>
#include <iterator>

using namespace std;

#ifndef ROLODEX_H
#define ROLODEX_H

class Rolodex
{

private:
	list<Card> rolo;
	list<Card>::iterator rolodexIterator;

public:
	void add(const Card& card);
	void remove();
	Card getCurrentCard();
	Card flip();
	bool search(const string& lastName, const string& firstName);
	void show(ostream& os);

};

#endif
