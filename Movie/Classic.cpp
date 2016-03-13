// Classic.cpp--------------------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// Sub class of Movie, classic
// ----------------------------------------------------------------------------
// Inherits methods from the Movie object
// Contains overriden display method
// ----------------------------------------------------------------------------

#include "Classic.h"
#include <string>

//////////////////////////////////////////////////
//////////   Constructors/Destructor   ///////////
//////////////////////////////////////////////////

//Overload constructor
//Sets the monthReleased and actor based on passed in values
//Uses Movie constructor for most values.
Classic::Classic(char genre, char mediaType, string title, string director,
   int stock, int yearReleased, int monthReleased, string actor)
    : Movie(genre, mediaType, title, director, stock, yearReleased)
{
    actorList = new actorNode;
    actorList -> actor = actor;
    actorList -> stock = stock;
    actorList->next = NULL;
  
    this->monthReleased = monthReleased;
}

//Destructor
//No dynamic memory is allocated
//Nothing to delete
Classic::~Classic()
{

}

//////////////////////////////////////////////////
//////////     Public Methods    /////////////////
//////////////////////////////////////////////////

//Display
//Displays the monthReleased and actor
void Classic::display() const
{
	cout << setw(2) << getGenre() << setw(3) << getMediaType() << setw(30) << getTitle() 
		<< setw(20) << getDirector() << setw(4) << getMonth() << setw(7)<< getYearReleased()<< setw(7) <<getStock() << endl;
		
	//???????????
	//???????????
	//???????????
    cout << "Stock by Actor(s): " << endl;
	displayActors();
	//???????????
	//???????????
	//???????????
}

//Get month
//Returns the monthReleased
int Classic::getMonth() const
{
  return monthReleased;
}

//Get actor
//Returns all the major actors
string Classic::getActor() const
{
    actorNode* temp = actorList;
    string returnString = "";
    while (temp != NULL)
    {
        returnString += temp->actor;
        returnString += " ";
        temp = temp->next;
    }
    return returnString;
}

//Has Actor
//Returns true if the actor is in the movie
bool Classic::hasActor(string actor) const
{
    actorNode* temp = actorList;
    while (temp != NULL)
    {
        if (temp->actor == actor)
        {
            return true;
        }
        else
        {
            temp = temp->next;
        }
    }
    return false;
}

void Classic::addActor(string actor, int stock) 
{
	cout << " ADDING actor " << actor << endl;
	actorNode* temp = new actorNode;
	temp -> actor = actor;
	temp -> stock = stock;
	temp -> next = NULL;
	
	if(actorList == NULL)
	{
		actorList = temp;
	}
	else
	{
		temp -> next = actorList;
		actorList = temp;
	}
}

//////////////////////////////////////////////////
////////////   Private Methods   /////////////////
//////////////////////////////////////////////////

// display actor and the stock of movie with the actor
void Classic::displayActors() const 
{
	actorNode* cur = actorList;
	while (cur != NULL)
	{
		cout << cur -> actor << setw(15) << cur -> stock << endl;
		cur = cur -> next;
	}
}

//////////////////////////////////////////////////
//////////     Operator Overloads   //////////////
//////////////////////////////////////////////////

//Equivalence operator
//Compares if the monthReleased is the same for both movies
//Movies with different actors, but the same monthReleased are
//considered to be equivalent
bool Classic::operator == (const Movie& otherMovie) const
{
	if (monthReleased == otherMovie.getMonth() && 
		yearReleased == otherMovie.getYearReleased() && getActor() == otherMovie.getActor())
		return true;
	else
		return false;
}

//Not equivalent operator
//Returns the negation of the equivalence operator
bool Classic::operator != (const Movie& otherMovie) const
{
  return !(*this == otherMovie);
}


//Greater than operator
//Returns true if this movie was released after the
//right hand side movie
bool Classic::operator > (const Movie& otherMovie) const
{
	if (yearReleased > otherMovie.getYearReleased())
		return true;
	else if (yearReleased == otherMovie.getYearReleased() && monthReleased > otherMovie.getMonth())
		return true; 
	else
		return false;
}

//Less than operator
//Returns true if this movie was released before the
//right hand side movie
bool Classic::operator < (const Movie& otherMovie) const
{
	if (yearReleased < otherMovie.getYearReleased())
		return true;
	else if (yearReleased == otherMovie.getYearReleased() && monthReleased < otherMovie.getMonth())
		return true; 
	else
		return false;
}


/* //Assignment operator
//Copies all values from the source movie to this movie
Classic& Classic::operator = (const Movie& source)
{
	// copy month released
    monthReleased = source.getMonth(); 
	
	// copy list of actors
    actorNode* curOther = source.actorList; 
	removeActorList();
	actorNode* curThis = actorList;
	while(curOther != NULL)
	{
		curThis -> actor = curOther -> actor;
		curThis -> stock = curOther -> stock;
		
		curThis = curThis -> next;
		curOther = curOther -> next;		
	}
	curThis -> next = NULL;
	
    return *this;
} */

void Classic::removeActorList() 
{
	actorNode* cur = actorList;
	actorNode* prev = actorList;
	while(cur != NULL)
	{
		cur = cur -> next;
		delete prev;
		prev = prev -> next;
	}
}

//////////////////////////////////////////////////
//////////////    I/O Stream   ///////////////////
//////////////////////////////////////////////////


//////////////////////////////////////////////////
//////////////   Extra Code   ////////////////////
//////////////////////////////////////////////////
