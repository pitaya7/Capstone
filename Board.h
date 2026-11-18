
#ifndef BOARD_H
#define BOARD_H


#include <memory>
#include <optional>
#include "Piece.h"
#include "Location.h"
#include "BoardHashMap.h"

// height and witdth (number of squares) of board
static const int BOARD_SIZE = 8;


/*  Initial Checkers board:
*
*    0 1 2 3 4 5 6 7 
*  +-----------------+
* 7|   r   r   r   r |
* 6| r   r   r   r   | 
* 5|   r   r   r   r |
* 4|                 |     b = black men
* 3|                 |     r = red men
* 2| b   b   b   b   |     B = black king (not shown)
* 1|   b   b   b   b |     R = red king (not shown)
* 0| b   b   b   b   |     
*  +-----------------+
*
* Bottom left is (0,0)
*
*
*/

struct Move
{
    Location start;
    Location end;
};


class Board 
{            
private:
    BoardHashMap pieces; 

public:
    Board();
    ~Board();
    
    void displayBoard(Color side);
    
    // getMoves(Piece) const;  TODO
    
    /* movePiece: Takes Piece to move either directly, or by 
    * using the board map and Location.
    */
    
    bool movePiece(Location, Location destination);  
    //bool movePiece(Piece&, Location destination); 
    
    auto getPieces() const {
        return pieces.getAll();
    };
    
    // nullptr if the location doesn't have a piece
    Piece* getPiece(const Location&);
    
};






















#endif

