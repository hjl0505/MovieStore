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

//Constructor
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
//Displays movie information with all actors listed
//Only one movie is displayed, even if that movie has multiple actors
void Classic::display() const
{
	// Print movie info and total stock
	cout << setw(7) << getGenre() << setw(7) << getMediaType() << setw(35) << getTitle() << setw(20)
		<< getDirector() << setw(7) << getMonth() << setw(7)<< getYearReleased() << setw(7)  << getTotalStock() << endl;

	// print actor and stock for this movie
	cout << setw(73) << this -> getActor() << " -------------" << setw(3) << this -> getStock() << endl;
	
	// print actor and stock for all other movies with same title
	for (int i = 0; i < sameMoviesList.size(); i++)
	{
		cout << setw(73) << sameMoviesList[i] -> getActor()
			<< " -------------" << setw(3) << sameMoviesList[i] -> getStock() << endl;
	}
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

//Get Total Stock
//Returns number of stock of this movie from all actors
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

//Subtract From Stock
//Returns true if subtracking from the movies stock was successful
//If one actor doesn't have enough stock, the method searches for stock from
//the other actors
bool Classic::subtractFromStock(int count)
{
	if (stock >= count && stock > 0)
    {
        stock-= count;
        return true;
    }
	else if (sameMoviesList.size() > 0) // check same movies stock and borrow 
	{
		setCounted(true);
		for(int i = 0; i < sameMoviesList.size(); i++)
		{
			if (!sameMoviesList[i] -> getCountedStatus() && sameMoviesList[i] -> subtractFromStock(count))
				return true;
			
			// mark the movie as counted
			sameMoviesList[i] -> setCounted(true);
		}
		return false;

	}
    else //this and all the same movies did not have enough stock
        return false;
}

//Add Same Movies
//Adds movies with the same title but different actors to each
//movie nodes' vector called sameMovieList
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
