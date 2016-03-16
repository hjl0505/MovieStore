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

//Default Constructor
Movie::Movie()
{
}

//Input Constructor
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

//Destructor
//No dynamic memory allocated
Movie::~Movie()
{

}

//////////////////////////////////////////////////
//////////     Public Methods    /////////////////
//////////////////////////////////////////////////

//Display
//Displays the movie's information on one line
void Movie::display() const
{
	cout << setw(7) << getGenre() << setw(7) << getMediaType() << setw(35) << getTitle()
		<< setw(20) << getDirector() << setw(7)<< getYearReleased() << setw(7) <<getStock() << endl;
}

//Get Movie Info
//Returns a string of "Title by Director"
string Movie::getMovieInfo() const
{
    string s;
    s = title + " by " + director;
    return s;
}

//Get Genre
//Returns the genre of the movie
char Movie::getGenre() const
{
    return genre;
}

//Get Media Type
//Returns the media type of the movie
char Movie::getMediaType() const
{
    return mediaType;
}

//Get Title
//Returns the title
string Movie::getTitle() const
{
    return title;
}

//Get Director
//Returns the director
string Movie::getDirector() const
{
    return director;
}

//Get Stock
//Returns the stock as an int
int Movie::getStock() const
{
    return stock;
}

//Get Year Released
//Returns the year released as an int
int Movie::getYearReleased() const
{
    return yearReleased;
}

//Add To Stock
//Returns true if the passed in value was added to the stock
bool Movie::addToStock(int add)
{
    stock += add;
    return true;
}

//Get Month
//Returns 0
//Only used by Classics
int Movie::getMonth() const
{
	return 0;
}

//Get Actor
//Returns an empty string
//Only used by Classics
string Movie::getActor() const
{
	return "";
}

//Get Counted Status
//Returns true if movie has already been counted
bool Movie::getCountedStatus() const
{
	return counted;
}

//Set Counted
//Sets the movie's counted variable to true
void Movie::setCounted(bool checked)
{
	counted = checked;
}

//Subtract From Stock
//Returns true if the passed in value was subtracted from
//the movie's stock
bool Movie::subtractFromStock(int count)
{
    if (stock >= count && stock > 0)
    {
        stock-= count;
        return true;
    }
    else
        return false;
}

//Add Same Movies
//Only for use by Classics
void Movie::addSameMovies(Movie*& sameMovie)
{
}


//////////////////////////////////////////////////
//////////     Operator Overloads   //////////////
//////////////////////////////////////////////////

// Equivalence operator
// default compare by title and year
bool Movie::operator == (const Movie& otherMovie) const
{
    if (this -> title == otherMovie.title && this -> yearReleased == otherMovie.getYearReleased())
        return true;
    else
        return false;
}

//Not equals operator
//Default compare
//Returns true if the title or year are different
bool Movie::operator != (const Movie& otherMovie) const
{
    return !(*this == otherMovie);
}

// Greater than operator
// default sort by year only
bool Movie::operator > (const Movie& otherMovie) const
{
    return this->yearReleased > otherMovie.yearReleased;
}

// Less than operator
// default sort by year only
bool Movie::operator < (const Movie& otherMovie) const
{
    return this->yearReleased < otherMovie.yearReleased;
}
