// Rolodex.cpp
// Name: Tim Slatt
// Date: 10/26/19
// INFO.2680-061
// This program contains the functions performed on the rolodex itself

#include "Rolodex.h"
#include <iostream>
#include <algorithm>

using namespace std;

// sort function - sorts cards in rolodex by last name first, then first name, then occupation
bool sort(const Card& firstCard, const Card& secondCard) 
{

	if (firstCard.getLast() != secondCard.getLast()) 
	{
		return firstCard.getLast() < secondCard.getLast();
	}
	else 
	{
		if (firstCard.getFirst() != secondCard.getFirst()) 
		{
			return firstCard.getFirst() < secondCard.getFirst();
		}
		else 
		{
			return firstCard.getOcc() < secondCard.getOcc();
		}

	}
}

// overload operator for ==
bool operator== (const Card& firstCard, const Card& secondCard)
{
	return firstCard.getLast() == secondCard.getLast();
	return firstCard.getFirst() == secondCard.getFirst();
	return firstCard.getAddress() == secondCard.getAddress();
	return firstCard.getOcc() == secondCard.getOcc();
	return firstCard.getPhone() == secondCard.getPhone();
}

// function to add card to the rolodex and insert in the proper place with sort function
void Rolodex::add(const Card& card)
{
	
	if (rolo.empty())
	{
		rolodexIterator = rolo.begin();
		rolo.push_back(card);
	}
	else
	{
		rolodexIterator = rolo.begin();
		rolo.push_back(card);
		rolo.sort(sort);
		rolodexIterator = find(rolo.begin(), rolo.end(), card);
	}
	
}

// function to remove the current card from the rolodex
void Rolodex::remove()
{
	rolo.erase(rolodexIterator++);

	if (rolodexIterator == rolo.end())
	{
		rolodexIterator = rolo.begin();
	}
}

// returns the current card in the rolodex
Card Rolodex::getCurrentCard()
{
	return *rolodexIterator;
}

// function to flip to the next card in the rolodex
Card Rolodex::flip()
{
	rolodexIterator++;

	if (rolodexIterator == rolo.end())
	{
		rolodexIterator = rolo.begin();
	}

	return *rolodexIterator;
}

// function to search the rolodex by first and last name
bool Rolodex::search(const string& lastName, const string& firstName)
{
	list<Card>::iterator tempIterator = rolodexIterator;

	rolodexIterator = rolo.begin();

	while (rolodexIterator != rolo.end())
	{
		if (!rolodexIterator->getLast().compare(lastName) && !rolodexIterator->getFirst().compare(firstName))
		{
			return true;
		}
		else
		{
			for (int i = 0; i < rolo.size(); i++)
			{
				char list = rolodexIterator->getLast().at(i);
				char input = lastName.at(i);

				if (list > input)
				{
					return true;
				}
				else
				{
					break;
				}
			}

			rolodexIterator++;
		}
	}

	rolodexIterator = tempIterator;

	cout << "Could not find name." << endl;
}

// shows entire rolodex in sorted order, calls individual card show() function until the last card is reached
void Rolodex::show(ostream& os)
{
	for (rolodexIterator = rolo.begin(); rolodexIterator != rolo.end(); rolodexIterator++) 
	{
		rolodexIterator->Card::show(os);
	}
}
