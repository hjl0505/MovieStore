// Comedy.cpp--------------------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// Sub class of Movie, Comedy
// ----------------------------------------------------------------------------
// Inherits methods from the Movie object
// Contains overriden display method
// ----------------------------------------------------------------------------

#include <stdio.h>
#include "Comedy.h"

//////////////////////////////////////////////////
//////////   Constructors/Destructor   ///////////
//////////////////////////////////////////////////

//Input Constructor
Comedy::Comedy(char genre, char mediaType, string title,
   string director, int stock, int yearReleased)
   : Movie(genre, mediaType, title, director, stock, yearReleased)
{
}

//Destructor
//No dynamic memory allocated
Comedy::~Comedy()
{
}

//////////////////////////////////////////////////
//////////     Operator Overloads   //////////////
//////////////////////////////////////////////////

//Equivalence operator
//Returns true if both movies have the same title and year released
bool Comedy::operator == (const Movie& otherMovie) const// check if movies are equal
{
	if (title == otherMovie.getTitle() && yearReleased == otherMovie.getYearReleased())
		return true;
	else
		return false;
}

//Not Equals operator
//Returns true if both movie have different title or year released
bool Comedy::operator != (const Movie& otherMovie) const // check if movies are not equal
{
  return !(*this == otherMovie);
}

// Greater than operator
// check if this movie is greater than other movie
// by title and then year released
bool Comedy::operator > (const Movie& otherMovie) const
{
	if (title > otherMovie.getTitle())
		return true;
	else if (title == otherMovie.getTitle() && yearReleased > otherMovie.getYearReleased())
		return true;
	else
		return false;
}

// Less than operator
// check if this movie is less than other movie
// by title and then year released
bool Comedy::operator < (const Movie& otherMovie) const
{
	if (title < otherMovie.getTitle())
		return true;
	else if (title == otherMovie.getTitle() && yearReleased < otherMovie.getYearReleased())
		return true;
	else
		return false;
}
