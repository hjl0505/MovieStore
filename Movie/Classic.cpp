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

//Default constructor
Classic::Classic()
{
  actorList = NULL;
  monthReleased = 0;
}

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
    cout << "Title: " << title << endl;
    cout << "Director: " << director << endl;
    cout << "Year Released: " << yearReleased << endl;
    cout << "Genre: " << getGenre() << endl;
    cout << "Media Type: " << mediaType << endl;
    cout << "Total Stock: " << stock << endl;

    cout << "Month Released: " << monthReleased << endl;
    cout << "Actor(s): " << endl;
	displayActors();
}

void Classic::displayActors() const 
{
	actorNode* cur = actorList;
	while (cur != NULL)
	{
		cout << cur -> actor << " Stock: " << cur -> stock << endl;
		cur = cur -> next;
	}
	
}

string Classic::getMovieInfo() const
{
    string s;
    s = title + " " + director;
    return s;
    
}

//Get month
//Returns the monthReleased
int Classic::getMonth() const
{
  return monthReleased;
}

//Get actor
//Returns the actor
string Classic::getActor() const
{
  return "";
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

//////////////////////////////////////////////////
//////////     Operator Overloads   //////////////
//////////////////////////////////////////////////

//Equivalence operator
//Compares if the monthReleased is the same for both movies
//Movies with different actors, but the same monthReleased are
//considered to be equivalent
bool Classic::operator == (const Movie& otherMovie) const
{
  if (monthReleased == otherMovie.getMonth() && yearReleased == otherMovie.getYearReleased() && actorExists(otherMovie.getActor()))
  {
    return true;
  }
  else
  {
    return false;
  }
}


bool Classic::actorExists(string actorName) const
{
	actorNode* cur = actorList;
	cout << "Actor exists called, actor name: " << actorName << endl;
	while(cur != NULL)
	{
		if (cur -> actor == actorName)
			return true;
		cur = cur -> next;
	}
	return false;
}


//Not equivalent operator
//Returns the negation of the equivalence operator
bool Classic::operator != (const Classic& otherMovie) const
{
  return !(*this == otherMovie);
}


//Greater than operator
//Returns true if this movie was released after the
//right hand side movie
bool Classic::operator > (const Classic& otherMovie) const
{
  return this->monthReleased > otherMovie.getMonth();
}

//Less than operator
//Returns true if this movie was released before the
//right hand side movie
bool Classic::operator < (const Classic& otherMovie) const
{
  return this->monthReleased < otherMovie.getMonth();
}


//Assignment operator
//Copies all values from the source movie to this movie
Classic& Classic::operator = (const Classic& source)
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
}

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
