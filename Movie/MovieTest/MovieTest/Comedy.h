// Comedy.h--------------------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// Sub class of Movie, Comedy
// ----------------------------------------------------------------------------
// Inherits methods from the Movie object
// Contains overriden display method
// ----------------------------------------------------------------------------

#ifndef COMEDY_H
#define COMEDY_H

#include "Movie.h"
using namespace std;

class Comedy : public Movie
{

public:
	Comedy();
    Comedy(char genre, char mediaType, string title, string director,
		 int stock, int yearRelease);
	~Comedy();
};
#endif
