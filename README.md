# rolodex
Rolodex project for my UML C++ class

Assignment instructions below

I'm getting the C26444 warning for the return lines in the 'bool operator=='

The code works if instructions are followed below, but doing my own experimenting I've run into some runtime errors with functions
that work on their own, but if executed in a specific order I run into issues.  For example I tried "add" then "view" and "view"
crashed the program.


*******************************************************************************************************************************************

Project - Rolodex

Necessary skills: STL container classes, iterators, algorithms, and stream I/O

Description

This goal of this project is to build an information manager similar to a rolodex (see http://en.wikipedia.org/wiki/Rolodex). 
A physical rolodex is made up of cards arranged in alphabetical order by [Last Name, First Name]. Each card contains some information, 
usually name, address, phone number and type of business (why the person is in the rolodex). The physical mechanism of using a rolodex 
is turning the group of cards and flipping through them. When the last card is read, the rolodex is then at the start of the list since 
a rolodex is built on a circular track.

Design Notes

For this project you'll implement a Card class (in Card.h and Card.cpp), a Rolodex class (in Rolodex.h and Rolodex.cpp), and a main() 
function (in main.cpp). The code in main() reads interactive commands that perform actions on its Rolodex object (like add a card,  search 
for a card,  list the rolodex cards, etc).

The Card class is used to represent a single Rolodex card. This class has std::string data members for First name, Last name, Occupation, 
Address (entire address can be in one string), and Phone number.  It has get/set  member functions to allow getting and setting of the 
member data values (e.g. first name), and a show(ostream& os) function that knows how to display the card on the supplied ostream parameter.  
This class does not know about Rolodex functionality, it just encapsulates a single card's information.

The Rolodex class manages a collection of Card objects. It must have a data member that is an STL container class to hold the set of rolodex 
Card objects (i.e. not a C/C++ array, but an STL container like list, vector, multiset, etc), and an associated STL iterator object to 
reference the 'current' Card. The STL container used must be able to handle the case of duplicate names (e.g.  two of Jim Smith, etc).  The 
Rolodex member functions just manage the STL collection of Cards, and may have parameters or return values that are a Card object. The 
Rolodex class does not have code to read data for new cards, or printing Cards. Data input is done by code in main() and Card objects are 
passed into and out of the Rolodex object. Displaying cards is done by the Rolodex code calling the Card's show() member function, passing 
an ostream for it to display on. Some of your Rolodex member functions might include the following :

    add(Card& card) takes a Card object as a parameter (by ref is more efficient), adds it to the STL container member (in the appropriate 
    spot  so the cards are kept in alphabetical order by [last name, first name]), and sets it as the 'current card' in the Rolodex by 
    setting the member STL iterator to point at the Card just added..
    
    remove() removes the current card from the Rolodex's STL container, returns it, and makes the following card the 'current' card. If the 
    last card in the STL container is removed, the 'current' card should be set to the first card in the container (i.e. wraps around).
    
    getCurrentCard() returns the current Card (actually, a copy of it).
    
    flip() updates the current card position to the next Card in the Rolodex's STL container, and returns that Card. If at the last card in 
    the container, it wraps around to the first card.
    
    search(const std::string& lastname, const std::string& firstname)  finds the requested card and sets it as the current card and returns 
    true indicating the search found a card.  If no exact matching card is found, the current card position remains unchanged and false is 
    returned.
    
    show(ostream& os) takes an ostream as a parameter. It iterates through all the cards in the STL container from beginning to end, 
    invoking each card's show() method, and passing the ostream parameter. The Rolodex show() doesn't do any actual output - it just 
    iterates through the collection and requests each card to display its contents by calling its show() member function. The current card 
    remains unchanged.

The main() function defines and loads the Rolodex object with the starting data (by adding a series of Cards to it), and then accepts 
interactive requests that act on the Rolodex. For each interactive command, main() invokes one or more member functions on the Rolodex 
object. For example, you might implement the interactive commands as follows:

    list - displays the entire rolodex. It calls the Rolodex's show(...) function to display the all the rolodex cards..
    
    view -  displays the card at the current position in the rolodex. It calls the Rolodex's getCurrentCard() function, then calls show(...) 
    on the returned Card.
    
    flip - updates the current roledex position to the next card, and displays it. Flipping past the last card wraps around to the first 
    card. It calls the Rolodex's flip() function to get the next Card, then calls show(...) on the returned Card.
    
    add - adds a new card to the rolodex. Prompts for each field value, reads them, and creates a new Card object with the information, 
    then calls Rolodex's add(...) function to add the new Card to the rolodex (which puts it in the correct position in its STL container).
    
    remove - removes the card at the current position. It first calls the Rolodex's getCurrentCard() function , calls show(...) on the 
    returned card to display it as part of the confirmation prompt, and if 'yes' is entered to remove it, it calls Rolodex's remove() 
    function to remove the Card from the rolodex.
    
    search - finds and displays a card.. This command prompts for the last name and first name to search for, then calls the Rolodex's 
    search(..) function. If a matching card is found, it then calls the Rolodex's getCurrentCard() function to get it, and then calls 
    show() to display it.  If no matching card is found, it displays "card not found".
    
    quit - exits the program.

Note that some of the command processing code in main() requires several steps (like the add, remove, and search commands) and may invoke 
several member functions on the Rolodex to complete a command. This keeps the Rolodex implementation *minimal*, and the Rolodex class 
doesn't do any of the prompting, input, output, etc. The Rolodex class has basic functionality to manage the collection of Rolodex cards 
(which is a better design).  The Rolodex class just maintains the collection of cards (in order), and provides functionality to add, remove, 
search for and get cards, list the collection of cards, maintains a 'current' card position, and can move the position to the next card. 
Specific output formatting, data entry, etc., is outside of the Rolodex class. When starting a class design, keep it as small as possible - 
it's always easier to add a new member function when there's a proven need, vs. trying to remove functions after the class is in use..

The Rolodex class must be able to handle the cases of adding or removing a card to the beginning or end of the collection, and 'wrapping 
around' from the end to the beginning of the collection when moving forward from the last card to the first card.

The Standard Library std::string class should be used for the character information (no char* or char arrays).

Test Data

Use the following information to provide the initial information to demonstrate the functionality of your rolodex program. You can hardcode 
these entries into your rolodex initialization in main() to simulate reading the information from a file, or optionally read them from a 
file. The address can be a single string value (no need to split into street, city, state, zip).

First:        Last:       Occupation:             Address:                                  Phone:
Tony    	    Hansen      Writer                  12 E. St. NY, NY 33333        	          555-9999
Jon         	Smyth     	Computer Hardware       CMU Computer Services Pittsburgh, PA      555-1324
Alonza        Heard       Mechanic                123 Anyplace Ave Malden, MA               555-5678
Jen 	        Reyes       Graphic artist          325 Oak Rd Wilmington, MA                 555-4950
Alan          Lupine      Vet                     1 Bigelow Ave. Lawrence, MA               555-7654
Jewel         Proverb     Landscaper              34 Washington St. Waltham, MA             555-3333
Paul          Revere      Radical Revolutionary   45 Commonwealth Ave. Boston, MA           555-1776
Adolf         Coors       Beer Manufacturer       Boston MA                                 555-2337
Seymour       Papert      Lego Professor          MIT                                       555-1111
Fred          Milton      Sales                   12 Freedom Way Nashua, NH                 555-9981

Test Steps

Test your program with the following sequence of actions:

    list the rolodex
    search for Alonza Heard
    view the current card (should be Alonza Heard)
    flip to the next card (should be  Alan Lupine)
    search for Jon Smyth
    view the current card (should be Jon Smyth)
    remove Jon Smyth
    view the current card (should be Adolf Coors, ie. wrapped from the end to the beginning)
    add Matthew Williams, Teacher, 69 Main St, Acton, MA,  555-9330
    view the current card (should be Matthew Williams)
    flip to the next card (should be Adolf Coors)
    remove Adolf Coors
    view the current card (should be Tony Hanson)
    add Jim Butler, Contractor, 33 Cedar Lane, Concord, MA, 555-8535
    view the current card (should be Jim Butler)
    search forJewel Proverb
    view the current card (should be Jewel Proverb)
    remove Jewel Proverb
    view the current card (should be Paul Revere)
    add another Jim Butler, Consultant, 22 Minuteman St, Lexington, MA.  555-4422
    add Dan Butler, Chauffeur, 68 Willow St, Westford, MA, 555-8493 (should sort before the Jim Butler cards)
    list the rolodex

Since there is a lot of runtime output for this project, you may need to increase the buffer size of your Command Prompt window in order 
to retain all of it.  Do the following:

    Click on the  C:\  icon on the top left of the window's title bar
    Click on 'Properties' in the pop up menu
    Click on the 'Layout' tab.
    For the Height setting in 'Screen Buffer Size', choose a large value (like 1000)
    Click on the 'Options' tab.
    Select and check the "QuickEdit mode" in Edit Options (allows selecting text in the window and hit Enter to copy to clipboard)
    Click Ok.
    Select "Modify shortcut that started this window", and click Ok.

You can optionally use a file of 'interactive' commands to perform the specified test steps,  so that you don't need to repeatedly enter 
the same data from the keyboard as you test your program.. Either way, main() is driven by a set of entered commands, and does not have the 
above test steps hardcoded.

 
