#ifndef BOARD_HASH_MAP_H
#define BOARD_HASH_MAP_H

#include "Location.h"
#include "Piece.h"
#include <vector>


struct Square {
	Location location;
    Piece* piece;
};


// The keys are Location structs
// Each bucket has a pointer to a Piece (Man or King)
class BoardHashMap 
{
private:
	/* There are 8x4=32 total dark table
	Although there are max 24 pieces I am basing it on the range
	of Locations so they are easy to locate.
	*/
	static const int BOARD_SIZE = 32;
	int num_pcs = 0;
	
	Piece* table[BOARD_SIZE];
	

	int Hash(const Location& loc) const {
	/* Index should be unique for every location.
	*  cols 0,2,4,6 ==> 0,1,2,3
	*  cols 1,3,5,7 ==> 0,1,2,3
	*  first row (=0) ==> 0—3
	*  second row (=1)==> 4—7
	*  ...and so on	
	* example: (row, col) = (3, 2) ==> index = 14
	*/
		return loc.row * 4 + loc.column / 2;
	};
	
public:
	BoardHashMap() {
		for (int i = 0; i < BOARD_SIZE; i++) {
			table[i] = nullptr;
		}
	};

	~BoardHashMap() {
		for (int i = 0; i < BOARD_SIZE; i++) {
			delete table[i];
		}
    };
	

	Piece* get(const Location& loc) const {
		if (!isValid(loc)) 
			return nullptr;
		else
        	return table[Hash(loc)];
    }
	
	bool put(Location loc, Piece* piece) {
		if (!isValid(loc)) 
			return false;
		else {
	        int i = Hash(loc);  // index
        	if (table[i] == nullptr && piece != nullptr)
				num_pcs++;
        	if (table[i] != nullptr && piece == nullptr)
				num_pcs--;
        	table[i] = piece;
        	return true;
		}
    }
	
	static bool isValid(const Location& loc) {
	// check if within board range (0—8) and is a dark square
        return  loc.row >= 0 && loc.row < 8 &&
                loc.column >= 0 && loc.column < 8 &&
        		(loc.row + loc.column) % 2 == 0;
    }

	Piece* remove(const Location& loc) {
		//TODO
	}

	std::vector<Square> getAll() const {
		std::vector<Square> all_squares;
		//TODO
		return all_squares;
	}

	bool contains(const Location& loc) const {
		// get() checks if loc's valid
        return get(loc) != nullptr;
    }

	int size() const {
		return num_pcs;
	}

	
	
};











#endif