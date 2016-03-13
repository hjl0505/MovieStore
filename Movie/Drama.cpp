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

Drama::Drama(char genre, char mediaType, string title,
   string director, int stock, int yearReleased)
   : Movie(genre, mediaType, title, director, stock, yearReleased)
{

}

Drama::~Drama()
{

}


//////////////////////////////////////////////////
//////////     Operator Overloads   //////////////
//////////////////////////////////////////////////
bool Drama::operator == (const Movie& otherMovie) const// check if movies are equal
{
	if (director == otherMovie.getDirector() && title == otherMovie.getTitle())
		return true;
	else
		return false;
}


bool Drama::operator != (const Movie& otherMovie) const // check if movies are not equal
{
  return !(*this == otherMovie);
} 

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
