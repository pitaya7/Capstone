
#include "Board.h"
#include "Location.h"
#include "Piece.h"
#include <exception>
#include <memory>
#include <iostream>
#include <ncurses.h>
#include <stdexcept>
#include <optional>
#include <utility>

using namespace std;

//TODO


Board::Board() 
{
    pieces;
    // initialize board with all pieces
    // 3 rows for each side ( 4 pieces each row)
    // alternating columns (8 total cols)
    for (int c = 0; c < 8; c++) 
    {
        for (int r = 0; r < 3; r++) 
        {
            Location loc1, loc2;

            if (c % 2 == 0){ // even columns

            } else { // odd

            }

            // put two new pieces with corresponding locations onto the board
            pieces.insert( 
                make_pair ( loc1, 
                            shared_ptr<Piece>(new Man(black, loc1))
                )
            );
            
            pieces.insert( 
                make_pair ( loc2, 
                            shared_ptr<Piece>(new Man(red, loc2))
                )
            );
        }
    }
};


optional<shared_ptr<Piece>> Board::getPiece(const Location& square) {
    try {
        return pieces.at(square);
    } catch (out_of_range) {
        return nullptr;
    }
};



// assumes move is legal and square is unoccupied
// creates destination square if it doesn't exist
bool Board::movePiece(Location current, Location destination) {
    try {
        // check if row or col are out of bounds
        if (!(current < BOARD_SIZE) || current >= 0) { 
            cout << ""
            return false;
        }
        auto p1 = pieces.at(current);
        auto p2 =
        getPiece(current);


    } catch (out_of_range) {
        cout << "selected location doesn't exist";
        return false;
    }
    
};


//void displayBoard(ostream os, Color side) {

void Board::displayBoard(Color side) {
    cout << " ///////////          \n"
            " //                      \n"
            "                      \n"
            "                      \n"
            "                      \n"
            "                      \n"
            "                      \n"
            "                      \n"
            "                      \n" 
            "";
    for (auto p : pieces) {
        cout << p.second->getSymbol();
    };
    

};

