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
}

Movie::~Movie()
{

}

//////////////////////////////////////////////////
//////////     Public Methods    /////////////////
//////////////////////////////////////////////////

void Movie::display() const
{
    cout << "Title: " << title << endl;
    cout << "Director: " << director << endl;
    cout << "Year Released: " << yearReleased << endl;
    cout << "Genre: " << getGenre() << endl;
    cout << "Media Type: " << mediaType << endl;
    cout << "Stock: " << stock << endl;
}

string Movie::getMovieInfo() const
{
    string s;
    s = title + " " + director + " " + to_string(yearReleased) + " " + genre + " " + mediaType + " " + to_string(stock);
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

bool Movie::addToStock()
{
    stock++;
    return true;
}

bool Movie::subtractFromStock()
{
    if (stock != 0)
    {
        stock--;
        return true;
    }
    else
    {
        return false;
    }
}

//////////////////////////////////////////////////
////////////   Private Methods   /////////////////
//////////////////////////////////////////////////

//////////////////////////////////////////////////
//////////     Operator Overloads   //////////////
//////////////////////////////////////////////////

bool Movie::operator == (const Movie& otherMovie) const
{
    if (this->title == otherMovie.title)
    {
        return true;
    }
    else
    {
        return false;
    }

}


bool Movie::operator != (const Movie& otherMovie) const
{
    return !(*this == otherMovie);

}


bool Movie::operator > (const Movie& otherMovie) const
{
    return this->yearReleased > otherMovie.yearReleased;
}

bool Movie::operator < (const Movie& otherMovie) const
{
    return this->yearReleased < otherMovie.yearReleased;
}

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
