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
/*
virtual bool operator == (const Movie& otherMovie) // check if movies are equal
{
  if (tite == otherMovie.title && director == otherMovie.director)
   {
    return true;
  }
  else
  {
    return false;
  }
}

virtual bool operator != (const Movie& otherMovie) // check if movies are not equal
{
  return !(this == otherMovie);

}

virtual bool operator > (const Movie& otherMovie) // check if this movie is greater than rhs movie
{
  if (this.yearReleased > otherMovie.yearReleased)
  {
    return true;
  }
  else
  {
    return false;
  }
}

virtual bool operator < (const Movie& otherMovie) // check if this movie is less than rhs movie
{
  return !(this > otherMovie);
}

virtual Movie &operator=(const Movie& otherMovie) // assignment operator
{
  this->genre = otherMovie.getGenre;
  this->mediaType = otherMovie.getMediaType;
  this->title = otherMovie.getTitle;
  this->director = otherMovie.getDirector;
  this->stock = otherMovie.getStock;
  this->yearReleased = otherMovie.getYearReleased;
}
 */

//////////////////////////////////////////////////
//////////////    I/O Stream   ///////////////////
//////////////////////////////////////////////////


//////////////////////////////////////////////////
//////////////   Extra Code   ////////////////////
//////////////////////////////////////////////////
