// Drama.cpp--------------------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// Sub class of Movie, Drama
// ----------------------------------------------------------------------------
// Inherits methods from the Movie object
// Contains overriden display method
// ----------------------------------------------------------------------------


#include "Drama.h"

//////////////////////////////////////////////////
//////////   Constructors/Destructor   ///////////
//////////////////////////////////////////////////

//Input consturctor
Drama::Drama(char genre, char mediaType, string title,
   string director, int stock, int yearReleased)
   : Movie(genre, mediaType, title, director, stock, yearReleased)
{

}

//Destructor
//NO dynamic memory allocated
Drama::~Drama()
{

}


//////////////////////////////////////////////////
//////////     Operator Overloads   //////////////
//////////////////////////////////////////////////

//Equivalence operator
//Returns true if both movies directors and titles are the same
bool Drama::operator == (const Movie& otherMovie) const
{
	if (director == otherMovie.getDirector() && title == otherMovie.getTitle())
		return true;
	else
		return false;
}

//Not equal operator
//Returns true if both movies have different directors or titles
bool Drama::operator != (const Movie& otherMovie) const
{
  return !(*this == otherMovie);
}

// Greater than operator
// check if this movie is greater than other movie
// by director and then title
bool Drama::operator > (const Movie& otherMovie) const
{
	if (director > otherMovie.getDirector())
		return true;
	else if (director == otherMovie.getDirector() && title > otherMovie.getTitle())
		return true;
	else
		return false;
}

//Less than operator
// check if this movie is less than other movie
// by director and then title
bool Drama::operator < (const Movie& otherMovie) const
{
	if (director < otherMovie.getDirector())
		return true;
	else if (director == otherMovie.getDirector() && title < otherMovie.getTitle())
		return true;
	else
		return false;
}
