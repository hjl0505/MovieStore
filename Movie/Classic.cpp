// Classic.cpp--------------------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// Sub class of Movie, Classic
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
  monthReleased = 0;
  actor = "";
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
//Displays Movie::display() and
//Displays the monthReleased and actor
void Classic::display() const
{
    cout << "Title: " << title << endl;
    cout << "Director: " << director << endl;
    cout << "Year Released: " << yearReleased << endl;
    cout << "Genre: " << getGenre() << endl;
    cout << "Media Type: " << mediaType << endl;
    cout << "Stock: " << stock << endl;

    cout << "Month Released: " << monthReleased << endl;
    cout << "Actor: " << actor << endl;
}

//Get Movie Info
//Returns a string of the movie's data variables
string Classic::getMovieInfo() const
{
    string s;
    //s = title + " " + director + " " + to_string(yearReleased) + " " + genre + " " + mediaType + " " + to_string(stock) + " " + to_string(monthReleased) + " " + actor;
    return s;

}

//Get Month
//Returns an int of the monthReleased
int Classic::getMonth() const
{
  return monthReleased;
}

//Get actor
//Returns a string of the actors associated with the Classic movie
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
  if (monthReleased == otherMovie.getMonth() && yearReleased == otherMovie.getYearReleased())
  {
    return true;
  }
  else
  {
    return false;
  }
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
    monthReleased = source.getMonth();
    actor = source.getActor();
    return *this;
}


//////////////////////////////////////////////////
//////////////    I/O Stream   ///////////////////
//////////////////////////////////////////////////


//////////////////////////////////////////////////
//////////////   Extra Code   ////////////////////
//////////////////////////////////////////////////
