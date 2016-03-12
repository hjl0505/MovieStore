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

Drama::Drama()
{

}

Drama::Drama(char genre, char mediaType, string title,
   string director, int stock, int yearReleased)
   : Movie(genre, mediaType, title, director, stock, yearReleased)
{

}

Drama::~Drama()
{

}


//////////////////////////////////////////////////
//////////     Public Methods    /////////////////
//////////////////////////////////////////////////

//////////////////////////////////////////////////
////////////   Private Methods   /////////////////
//////////////////////////////////////////////////

//////////////////////////////////////////////////
//////////     Operator Overloads   //////////////
//////////////////////////////////////////////////
bool Drama::operator == (const Movie& otherMovie) const// check if movies are equal
{
  if (title == otherMovie.getTitle() && director == otherMovie.getDirector())
   {
    return true;
  }
  else
  {
    return false;
  }
}
/* 
bool Drama::operator != (const Movie& otherMovie) const// check if movies are not equal
{
  return !(this == otherMovie);
} */

bool Drama::operator > (const Movie& otherMovie) const// check if this movie is greater than rhs movie
{
/*   if (this.yearReleased > otherMovie.yearReleased)
  {
    return true;
  }
  else
  {
    return false;
  } */
}

bool Drama::operator < (const Movie& otherMovie) const// check if this movie is less than rhs movie
{
/*   return !(this > otherMovie); */
}



//////////////////////////////////////////////////
//////////////    I/O Stream   ///////////////////
//////////////////////////////////////////////////


//////////////////////////////////////////////////
//////////////   Extra Code   ////////////////////
//////////////////////////////////////////////////
