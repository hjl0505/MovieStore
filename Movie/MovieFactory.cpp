// MovieFactory.cpp--------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// Factory that creates different genre of movies
// ----------------------------------------------------------------------------
// create funtion holds a switch to instantiate the correct genre of movie
// ----------------------------------------------------------------------------

#include "MovieFactory.h"

//////////////////////////////////////////////////
//////////   Constructors/Destructor   ///////////
//////////////////////////////////////////////////
MovieFactory::MovieFactory()
{

}

MovieFactory::~MovieFactory()
{

}

//////////////////////////////////////////////////
//////////     Public Methods    /////////////////
//////////////////////////////////////////////////
Movie* MovieFactory::create(char genre, string title, string director, string actor, int month, int year, int stock)
{
	Movie* newMovie = NULL;
	switch(genre)
	{
		case 'C':
			newMovie = new Classic (genre, 'D', title, director, stock, year, month, actor);
            return newMovie;
            break;
		case 'D':
			newMovie = new Drama (genre, 'D', title, director, stock, year);
            return newMovie;
			break;
		case 'F':
			newMovie = new Comedy (genre, 'D', title, director, stock, year);
            return newMovie;
			break;
		default:
			return newMovie;
            break;
	}
}
//////////////////////////////////////////////////
////////////   Private Methods   /////////////////
//////////////////////////////////////////////////

//////////////////////////////////////////////////
//////////     Operator Overloads   //////////////
//////////////////////////////////////////////////


//////////////////////////////////////////////////
//////////////    I/O Stream   ///////////////////
//////////////////////////////////////////////////


//////////////////////////////////////////////////
//////////////   Extra Code   ////////////////////
//////////////////////////////////////////////////
