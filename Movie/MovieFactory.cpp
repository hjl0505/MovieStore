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

//Default Constructor
MovieFactory::MovieFactory()
{

}

//Destructor
//No dynamic memory allocated
MovieFactory::~MovieFactory()
{

}

//////////////////////////////////////////////////
//////////     Public Methods    /////////////////
//////////////////////////////////////////////////

//Create
//Creates a movie object based on the genre passed in
//Assume all movies are DVDs
Movie* MovieFactory::create(char genre, string title, string director, string actor, int month, int year, int stock)
{
	Movie* newMovie = NULL;
	switch(genre)
	{
		case 'F': // Comedy
			newMovie = new Comedy (genre, 'D', title, director, stock, year);
            return newMovie;
			break;
			
		case 'C': // Classic
			newMovie = new Classic (genre, 'D', title, director, stock, year, month, actor);
            return newMovie;
            break;
			
		case 'D': // Drama
			newMovie = new Drama (genre, 'D', title, director, stock, year);
            return newMovie;
			break;

		default:
			cerr << "ERROR: " << genre << " Genre Not Found. Try Again." << endl;
			return newMovie;
            break;
	}
}