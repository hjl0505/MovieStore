// Inventory.cpp--------------------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// Inventory Transaction
// ----------------------------------------------------------------------------
// Sub class of Inventory
// prints the inventory of the movies by genre then categories of
// Director, title year rleleased, and actor and release date for classics
// ----------------------------------------------------------------------------

#include "Inventory.h"

//////////////////////////////////////////////////
//////////   Constructors/Destructor   ///////////
//////////////////////////////////////////////////

Inventory::Inventory()
{

}

Inventory::~Inventory()
{

}

//////////////////////////////////////////////////
//////////     Public Methods    /////////////////
//////////////////////////////////////////////////

bool Inventory::perform(MovieInventory& movies, CustomerInventory& customers)
{
	movies.printInventory();
	return true;
}