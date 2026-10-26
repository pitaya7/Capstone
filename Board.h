
#ifndef BOARD_H
#define BOARD_H


#include <map>
#include <memory>
#include <optional>
#include "Piece.h"
#include "Location.h"

// height and witdth (number of squares) of board
static const int BOARD_SIZE = 8;


struct Move
{
    Location start;
    Location end;
};


class Board 
{            
    private:
        std::map<Location, std::shared_ptr<Piece>> pieces;
    
    public:
        Board();
        ~Board() = default; 

        void displayBoard(Color side);

        // getMoves(Piece) const;  TODO

        /* movePiece: Takes Piece to move either directly, or by 
         * using the board map and Location.
        */
        bool movePiece(Location, Location destination);  
        //bool movePiece(Piece&, Location destination); 

        
        // nullptr if the location doesn't have a piece
        std::optional<std::shared_ptr<Piece>> getPiece(const Location&);
    
};






















#endif

