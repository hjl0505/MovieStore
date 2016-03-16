// Inventory.h--------------------------------------------------------------------
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

#ifndef INVENTORY_H
#define INVENTORY_H

#include "Transaction.h"
#include "../Movie/Movie.h"
#include "../Movie/MovieInventory.h"
#include "../Customer/CustomerInventory.h"

using namespace std;

class Inventory: public Transaction {

public:

	// Constructor and Destructor
	Inventory();
	virtual ~Inventory();
		
	// perform inventory
	virtual bool perform(MovieInventory&, CustomerInventory&); 
};
#endif