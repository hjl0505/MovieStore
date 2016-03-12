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

//Default constructor
Comedy::Comedy()
{

}

Comedy::Comedy(char genre, char mediaType, string title,
   string director, int stock, int yearReleased)
   : Movie(genre, mediaType, title, director, stock, yearReleased)
{

}

Comedy::~Comedy()
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

bool Comedy::operator == (const Movie& otherMovie) const// check if movies are equal
{
  if (title == otherMovie.getTitle() && yearReleased == otherMovie.getYearReleased())
   {
    return true;
  }
  else
  {
    return false;
  }
}


/* bool Comedy::operator != (const Movie& otherMovie) const // check if movies are not equal
{
  return !(this == otherMovie);
} */

bool Comedy::operator > (const Movie& otherMovie) const // check if this movie is greater than rhs movie
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

bool Comedy::operator < (const Movie& otherMovie) const// check if this movie is less than rhs movie
{
/*   return !(this > otherMovie); */
}

//////////////////////////////////////////////////
//////////////    I/O Stream   ///////////////////
//////////////////////////////////////////////////


//////////////////////////////////////////////////
//////////////   Extra Code   ////////////////////
//////////////////////////////////////////////////
