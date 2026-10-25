
#ifndef BOARD_H
#define BOARD_H


#include <map>
#include <memory>
#include <optional>
#include "Piece.h"
#include "Location.h"


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

        void setupBoard();

        // getMoves(Piece) const;  TODO

        /* movePiece: Takes Piece to move either directly, or by 
         * using the board map and Location.
        */
        bool movePiece(Location, Location destination);  
        bool movePiece(Piece&, Location destination); 

        bool isEmpty(const Location&) const;
        
        // nullptr if the location doesn't have a piece
        Piece* getPiece(const Location&) const;
    
};






















#endif

