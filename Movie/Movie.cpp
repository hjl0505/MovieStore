// Movie.h--------------------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// Super class of Movie
// ----------------------------------------------------------------------------
// Stores data for each movie in the store
// It tracks the current amount of in stock movies for
// each movie, the media type, director, year released, title, and movie code.
// It has functions to add and remove from the movie stock compare movies,
// ----------------------------------------------------------------------------

#include <stdio.h>
#include "Movie.h"

//////////////////////////////////////////////////
//////////   Constructors/Destructor   ///////////
//////////////////////////////////////////////////
Movie::Movie()
{

}

Movie::~Movie()
{

}

//////////////////////////////////////////////////
//////////     Public Methods    /////////////////
//////////////////////////////////////////////////

string Movie::display()
{

}

char Movie::getGenre()
{

}

char Movie::getMediaType()
{

}

string Movie::getTitle()
{

}

string Movie::getDirector()
{

}

int Movie::getStock()
{

}

int Movie::getYearReleased()
{

}

bool Movie::addToStock()
{

}

bool Movie::subtractFromStock()
{

}

//////////////////////////////////////////////////
////////////   Private Methods   /////////////////
//////////////////////////////////////////////////

//////////////////////////////////////////////////
//////////     Operator Overloads   //////////////
//////////////////////////////////////////////////

bool Movie::operator== (const Movie& otherMovie) const
{

}


bool Movie::operator!= (const Movie& otherMovie) const
{

}


bool Movie::operator> (const Movie& otherMovie)
{

}

bool Movie::operator< (const Movie& otherMovie)
{

}

Movie& Movie::operator=(const Movie& otherMovie)
{

}


//////////////////////////////////////////////////
//////////////    I/O Stream   ///////////////////
//////////////////////////////////////////////////


//////////////////////////////////////////////////
//////////////   Extra Code   ////////////////////
//////////////////////////////////////////////////
