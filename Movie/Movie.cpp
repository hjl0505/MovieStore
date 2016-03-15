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

Movie::Movie(char genre, char mediaType, string title, string director, int stock, int yearReleased)
{
    this->genre = genre;
    this->mediaType = mediaType;
    this->title = title;
    this->director = director;
    this->stock = stock;
    this->yearReleased = yearReleased;
	
	this->counted = false;
}

Movie::~Movie()
{

}

//////////////////////////////////////////////////
//////////     Public Methods    /////////////////
//////////////////////////////////////////////////

void Movie::display() const
{
	cout << "Movie Display" << endl;
	cout << setw(2) << getGenre() << setw(3) << getMediaType() << setw(30) << getTitle() 
		<< setw(20) << getDirector() << setw(7)<< getYearReleased() << setw(7) <<getStock() << endl;
}

string Movie::getMovieInfo() const
{
    string s;
    s = title + " by " + director;
    return s;
}

char Movie::getGenre() const
{
    return genre;
}

char Movie::getMediaType() const
{
    return mediaType;
}

string Movie::getTitle() const
{
    return title;
}

string Movie::getDirector() const
{
    return director;
}

int Movie::getStock() const
{
    return stock;
}

int Movie::getYearReleased() const
{
    return yearReleased;
}

bool Movie::addToStock(int add)
{
    stock += add;
    return true;
}

int Movie::getMonth() const
{
	return 0;
}

string Movie::getActor() const
{
	return "";
}

bool Movie::getCountedStatus() const
{
	return counted;
}

void Movie::setCounted(bool checked)
{
	counted = checked;
}

bool Movie::subtractFromStock(int count)
{
    if (stock >= count)
    {
        stock-= count;
        return true;
    }
    else
        return false;
}

void Movie::addSameMovies(Movie*& sameMovie)
{
}


//////////////////////////////////////////////////
//////////     Operator Overloads   //////////////
//////////////////////////////////////////////////

// default compare by title and year
bool Movie::operator == (const Movie& otherMovie) const
{
    if (this -> title == otherMovie.title && this -> yearReleased == otherMovie.getYearReleased())
        return true;
    else 
        return false;
}


bool Movie::operator != (const Movie& otherMovie) const
{
    return !(*this == otherMovie);
}

// default sort by year only
bool Movie::operator > (const Movie& otherMovie) const
{
    return this->yearReleased > otherMovie.yearReleased;
}

// default sort by year only
bool Movie::operator < (const Movie& otherMovie) const
{
    return this->yearReleased < otherMovie.yearReleased;
}

//?????
//?????
//?????
//?????
Movie& Movie::operator = (const Movie& otherMovie)
{
    this->genre = otherMovie.getGenre();
    this->mediaType = otherMovie.getMediaType();
    this->title = otherMovie.getTitle();
    this->director = otherMovie.getDirector();
    this->stock = otherMovie.getStock();
    this->yearReleased = otherMovie.getYearReleased();
    return *this;
}


//////////////////////////////////////////////////
//////////////    I/O Stream   ///////////////////
//////////////////////////////////////////////////


//////////////////////////////////////////////////
//////////////   Extra Code   ////////////////////
//////////////////////////////////////////////////
