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

#include "Classic.h"

//////////////////////////////////////////////////
//////////   Constructors/Destructor   ///////////
//////////////////////////////////////////////////

//Default constructor
Classic::Classic()
{
  monthReleased = 0;
  actor = "";
}

//Overload constructor
//Sets the monthReleased and actor based on passed in values
Classic::Classic(char genre, char mediaType, string title, string director,
   int stock, int yearReleased, int monthReleased, string actor)
    : Movie(genre, mediaType, title, director, stock, yearReleased)
{
  this.monthReleased = monthReleased;
  this.actor = actor;
}

//Destructor
//No dynamic memory is allocated
//Nothing to delete
Classic::~Classic()
{

}

//////////////////////////////////////////////////
//////////     Public Methods    /////////////////
//////////////////////////////////////////////////

<<<<<<< HEAD
//Display
//Displays the monthReleased and actor
virtual string Classic::display()
=======
string Classic::display()
>>>>>>> master
{
  cout << "Month Released: " << monthReleased;
  cout << "Actor: " << actor << endl;
}

<<<<<<< HEAD
//Get month
//Returns the monthReleased
=======
>>>>>>> master
int Classic::getMonth()
{
  return monthReleased;
}

//Get actor
//Returns the actor
string Classic::getActor()
{
  return actor;
}


//////////////////////////////////////////////////
////////////   Private Methods   /////////////////
//////////////////////////////////////////////////

//////////////////////////////////////////////////
//////////     Operator Overloads   //////////////
//////////////////////////////////////////////////
<<<<<<< HEAD
=======
bool Classic::operator == (const Movie& otherMovie)
{
>>>>>>> master

//Equivalence operator
//Compares if the monthReleased is the same for both movies
//Movies with different actors, but the same monthReleased are
//considered to be equivalent
virtual bool Classic::operator == (const Movie& rhs)
{
  if (monthReleased == rhs.monthReleased)
  {
    return true;
  }
  else
  {
    return false;
  }
}
 

<<<<<<< HEAD
//Not equivalent operator
//Returns the negation of the equivalence operator
virtual bool Classic::operator != (const Movie& rhs)
=======
bool Classic::operator != (const Movie& otherMovie)
>>>>>>> master
{
  return !(this == rhs);
}

<<<<<<< HEAD
//Greater than operator
//Returns true if this movie was released after the
//right hand side movie
virtual bool Classic::operator > (const Movie& rhs)
=======

bool Classic::operator > (const Movie& otherMovie)
>>>>>>> master
{
  return this.getMonth > rhs.getMonth;
}

<<<<<<< HEAD
//Less than operator
//Returns true if this movie was released before the
//right hand side movie
virtual bool Classic::operator < (const Movie& rhs)
=======

bool Classic::operator < (const Movie& otherMovie)
>>>>>>> master
{
  return this.getMonth < rhs.getMonth;
}

<<<<<<< HEAD
//Assignment operator
//Copies all values from the source movie to this movie
virtual const Classic::Movie &operator=(const Movie& source)
=======

Movie& Classic::operator=(const Movie& otherMovie)
>>>>>>> master
{
  monthReleased = source.getMonth;
  actor = source.getActor;
}


//////////////////////////////////////////////////
//////////////    I/O Stream   ///////////////////
//////////////////////////////////////////////////


//////////////////////////////////////////////////
//////////////   Extra Code   ////////////////////
//////////////////////////////////////////////////
