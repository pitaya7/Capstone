
#include "Board.h"
#include "Location.h"

#include "Piece.h"
#include <memory>
#include <iostream>
#include <ncurses.h>
#include <ncurses.h>

using namespace std;

//TODO




Board::Board() 
{
    // initialize board with all pieces
    // 3 rows for each side ( 4 pieces each row)
    // alternating columns (8 total cols)
    for (int c = 0; c < 8; c++) 
    {
    
        //loc_b0, loc_b1, loc_b2, loc_r0, loc_r1, loc_r2;        
        Location locs[6];
        if (c % 2 == 0){ // even columns
            

            // first and third row of black pieces
            locs[0] = {.row=(0), .column=c }; 
            locs[2] = {.row=(2), .column=c };

            // red pieces in middle row on even columns
            locs[4] = {.row=(6), .column=c };

            // insert new pieces to board
//TODO: fix all of this
            pieces[locs[0]] = new Man(black, locs[0]);
            pieces[locs[2]] = new Man(black, locs[2]);
            cout << pieces[locs[0]].value()->getSymbol() << endl;
            pieces[locs[4]] = new Man(red, locs[4]);
            //pieces.insert( make_pair (loc_r1, new Man(red, loc_r1)));

        } else { // odd columns

            // one row of black pieces in middle row on odd columns
            locs[1] = {.row=(1), .column=c };

            // two rows of red
            locs[3] = {.row=(5), .column=c };
            locs[5] = {.row=(7), .column=c };


            //pieces.insert( make_pair (loc_b1, new Man(black, loc_b1)));
            pieces[locs[1]] = new Man(black, locs[1]);

            pieces[locs[3]] = new Man(red, locs[3]);
            pieces[locs[5]] = new Man(red, locs[5]);

        }
        for (auto l : locs){
            cout << "("<< l.row << ", "<< l.column << ") " << pieces[l].value()->getSymbol() << endl;
        }
    }
};

Board::~Board() {
    for (auto& item : pieces.getAll()) {

    }
}

Piece* Board::getPiece(const Location& square) {
    return pieces.get(square);
};



// assumes move is legal and square is unoccupied
// creates destination square if it doesn't exist
bool Board::movePiece(Location current, Location destination) {

};

