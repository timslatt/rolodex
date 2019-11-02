// main.cpp
// Name: Tim Slatt
// Date: 10/26/19
// INFO.2680-061
// This program contains the user interface to perform all the rolodex and card functions
// from Rolodex.cpp and Card.cpp

#include "Card.h"
#include "Rolodex.h"
#include <string>
#include <cstring>
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{

	Rolodex timsRolodex;

	// preload rolodex with a set of data
	timsRolodex.add(Card("Tony", "Hansen", "Writer", "12 E St NY, NY 33333", "555-9999"));
	timsRolodex.add(Card("Jon", "Smyth", "Computer Hardware", "CMU Computer Services - Pittsburgh, PA", "555-1324"));
	timsRolodex.add(Card("Alonza", "Heard", "Mechanic", "123 Anyplace Ave Malden, MA", "555-5678"));
	timsRolodex.add(Card("Jen", "Reyes", "Graphic artist", "325 Oak Rd Wilmington, MA", "555-4950"));
	timsRolodex.add(Card("Alan", "Lupine", "Vet", "1 Bigelow Ave Lawrence, MA", "555-7654"));
	timsRolodex.add(Card("Jewel", "Proverb", "Landscaper", "34 Washington St Waltham, MA", "555-3333"));
	timsRolodex.add(Card("Paul", "Revere", "Radical Revolutionary", "45 Commonwealth Ave Boston, MA", "555-1776"));
	timsRolodex.add(Card("Adolf", "Coors", "Beer Manufacturer", "Boston MA", "555-2337"));
	timsRolodex.add(Card("Seymour", "Papert", "Lego Professor", "MIT", "555-1111"));
	timsRolodex.add(Card("Fred", "Milton", "Sales", "12 Freedom Way Nashua, NH", "555-9981"));

	// variable to store user entry for main program
	string userEntry = "";  

	// while loop to allow user to enter rolodex options, entering 'quit' exits the loop and the program
	while (userEntry != "quit")
	{
		// displays options for user
		cout << "\n\nEnter command:\n" <<
			"list - displays the entire rolodex\n" <<
			"view - displays the card in the current position in the rolodex\n" <<
			"flip - display the next card in the rolodex\n" <<
			"add - add a new card to the rolodex\n" <<
			"remove - removes the card in the current position\n" <<
			"search - search for a card by first and last name\n" <<
			"quit - quit program\n\n" << endl;

		// store user selection 
		cin >> userEntry;
		// clear the input buffer (ruined an hour of my day till I figured this out)
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (userEntry == "list")
		{
			// list entire rolodex
			cout << "Displaying entire rolodex." << endl;

			// call rolodex 'show()' function to display all the cards
			timsRolodex.Rolodex::show(cout);
		}
		else if (userEntry == "view")
		{
			// display current card
			cout << "Current card in rolodex: \n\n" << endl;

			timsRolodex.Rolodex::getCurrentCard().Card::show(cout);
		}
		else if (userEntry == "flip")
		{
			// flips to next card in rolodex and displays it
			cout << "Next card in rolodex:\n\n" << endl;

			timsRolodex.Rolodex::flip().Card::show(cout);	
		}
		else if (userEntry == "add")
		{
			// adds a new card to the rolodex
			cout << "Add a card to the rolodex:" << endl;
			
			// variables for strings to be added to the card - reinitialized as null in each loop
			string firstName = "";
			string lastName = "";
			string occupation = "";
			string address = "";
			string phoneNumber = "";
			
			// prompt for each field value
			cout << "Enter the first name: " << endl;
			cin >> firstName;
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			cout << "Enter the last name: " << endl;
			getline(cin, lastName);
			cout << "Enter the occupation: " << endl;
			getline(cin, occupation);
			cout << "Enter the address: " << endl;
			getline(cin, address);
			cout << "Enter the phone number: " << endl;
			getline(cin, phoneNumber);
			
			// create new card to load user entered data into
			Card newCard;

			newCard.setFirst(firstName);
			newCard.setLast(lastName);
			newCard.setOcc(occupation);
			newCard.setAddress(address);
			newCard.setPhone(phoneNumber);

			// call add() function to add user entered data into rolodex as new card
			timsRolodex.Rolodex::add(newCard);

		}
		else if (userEntry == "remove")
		{
			// removes the card from the current position

			// variable to hold user entry - 'yes' will remove the card, anything else will break the loop
			string yesNo;

			cout << "Remove this card from the rolodex?\n" << endl;

			// call 'show()' function to display current card
			timsRolodex.Rolodex::getCurrentCard().Card::show(cout);

			cout <<	"Enter 'yes' to confirm: " << endl;
			cin >> yesNo;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			// if 'yes' entered, call 'remove()' function to remove the card
			// if anything but 'yes' entered, continue

			if (yesNo == "yes")
			{
				timsRolodex.Rolodex::remove();
				cout << "Card was removed.\n";
			}
			else
			{
				cout << "No card removed.\n";
				continue;
			}

						
		}
		else if (userEntry == "search")
		{
			// finds and displays a card
			cout << "Search for a card. Enter a first and last name to search for:\n" << endl;

			// prompt user for a first and last name to search for
			string lastNameSearch;
			string firstNameSearch;

			cout << "Enter the first and last name of the person you are searching for:\n" << endl;

			cout << "First Name: " << endl;
			cin >> firstNameSearch;

			cout << "Last Name: " << endl;
			cin >> lastNameSearch;

			// call 'search()' function on user entry
			// if match found, call 'getCurrentCard()' function, otherwise display 'card not found' and continue
			if (timsRolodex.Rolodex::search(lastNameSearch, firstNameSearch)) 
			{
				cout << "Contact found:\n" << endl;
				timsRolodex.Rolodex::getCurrentCard().Card::show(cout);
			}

		}
		else if (userEntry == "quit")
		{
			break;
		}
		else
		{
			cout << "Invalid entry. Please try again." << endl;
		}

	}
	
	return 0;
}