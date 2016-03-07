// MovieFactory.h--------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// Factory that creates different genre of movies
// ----------------------------------------------------------------------------
// create funtion holds a switch to instantiate the correct genre of movie
// ----------------------------------------------------------------------------

#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include "Movie.h"
#include "Comedy.h"
#include "Drama.h"
#include "Classic.h"
using namespace std;

class MovieFactory
{

public:
	MovieFactory();
	~MovieFactory();

	// create movie
	Movie* create(char, string, string, string, int, int, int);
};
#endif
