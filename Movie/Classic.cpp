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
	this -> actor = actor;
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
//Displays the monthReleased 
void Classic::display() const
{
	cout << setw(2) << getGenre() << setw(3) << getMediaType() << setw(30) << getTitle() << setw(20) 
		<< getDirector() << setw(4) << getMonth() << setw(7)<< getYearReleased() << setw(7)  << getTotalStock() << endl;
}

//Get month
//Returns the monthReleased
int Classic::getMonth() const
{
  return monthReleased;
}

//Get actor
//Returns the major actor
string Classic::getActor() const
{
	return actor;
}

int Classic::getTotalStock() const
{
	int totalStock = getStock();
	for (int i = 0; i < sameMoviesList.size(); i++)
	{
		if(!sameMoviesList[i] -> getCountedStatus()) // if the movie was not already counted for inventory
		{
			totalStock += sameMoviesList[i] -> getStock();
			sameMoviesList[i] -> setCounted(true);
		}
	}
	return totalStock;
}

bool Classic::subtractFromStock(int count) 
{
	if (stock >= count)
    {
        stock-= count;
        return true;
    }
	else if (sameMoviesList.size() > 0) // check same movies stock and subtract
	{
		for(int i = 0; i < sameMoviesList.size(); i++)
			return sameMoviesList[i] -> subtractFromStock(count);

	}
    else //this and all the same movies did not have enough stock
        return false;
}

void Classic::addSameMovies(Movie*& sameMovie)
{
	sameMoviesList.push_back(sameMovie); // add to this list
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
	else if (yearReleased == otherMovie.getYearReleased())
	{
		if (monthReleased > otherMovie.getMonth())
			return true;
		else if (monthReleased == otherMovie.getMonth() && actor > otherMovie.getActor())
			return true;
	}
	return false;
}

//Less than operator
//Returns true if this movie was released before the
//right hand side movie
bool Classic::operator < (const Movie& otherMovie) const
{
	if (yearReleased < otherMovie.getYearReleased())
		return true;
	else if (yearReleased == otherMovie.getYearReleased())
	{
		if (monthReleased < otherMovie.getMonth())
			return true;
		else if (monthReleased == otherMovie.getMonth() && actor < otherMovie.getActor())
			return true;
	}
	return false;
}