// MovieInventory.cpp---------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// Holds inventory of the movies.
// ----------------------------------------------------------------------------
// This class keeps track of all the movies the store owns
// in an array of binary search trees.
// ----------------------------------------------------------------------------

#include "MovieInventory.h"

//////////////////////////////////////////////////
//////////   Constructors/Destructor   ///////////
//////////////////////////////////////////////////
MovieInventory::MovieInventory()
{
    BST comedy, classic, drama;
    movieType.push_back(comedy);
    movieType.push_back(classic);
    movieType.push_back(drama);
}

MovieInventory::~MovieInventory()
{

}

//////////////////////////////////////////////////
//////////     Public Methods    /////////////////
//////////////////////////////////////////////////

Movie* MovieInventory::getMovie (Movie* moviePtr)
{
    Movie *foundPtr;
    switch (moviePtr->getGenre())
    {
        case 'F':
            movieType[0].getMovie(*moviePtr, foundPtr);
            return foundPtr;
            break;
            
        case 'C':
            movieType[1].getMovie(*moviePtr, foundPtr);
            return foundPtr;
            break;
        
        case 'D':
            movieType[2].getMovie(*moviePtr, foundPtr);
            return foundPtr;
            break;
            
        default:
            foundPtr = NULL;
            break;
    }
    return foundPtr;
}

bool MovieInventory::movieExist (Movie* moviePtr)
{
    if (getMovie(moviePtr) != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MovieInventory::printInventory()
{
    for (int i = 0; i < movieType.size(); i++)
    {
        cout << movieType[i] << endl;
    }
}

bool MovieInventory::addMovie (Movie* moviePtr)
{

}

bool MovieInventory::removeMovie (Movie* moviePtr)
{

}

bool MovieInventory::borrowMovie (Movie* moviePtr)
{

}

bool MovieInventory::returnMovie (Movie* moviePtr)
{

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
