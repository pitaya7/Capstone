/*
 * File:    Piece.h 
 * Course:  CSC 1061
 * 
 * Declaration for Piece virtual class, and subclasses Man and King.
**/

#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "Location.h"


enum Color {
    red,
    black
};

// directions, as location offsets of +/- 1 row and column
namespace dir {  
    inline constexpr Location up_left {1,-1};
    inline constexpr Location up_right {1,1};
    inline constexpr Location down_left {-1,-1};
    inline constexpr Location down_right {-1,1};
};

class Piece 
{
    protected:
        Color color_;
        Location location_;
        std::vector<Location> moveOffsets;
        int captured();

    public:
        Piece(Color, Location);
        Piece(Color, int, int);

        virtual ~Piece() = default;

        // move this piece to this Location.
        void moveTo(Location);

        Location moveBy(Location);

        Color getColor() const;

        virtual std::vector<Location> getOffsets() const = 0;

        // Symbol to be shown on board display (b/r for Man, B/R for King)
        virtual char getSymbol() const = 0;

        Location getLocation() const;

};





/* A "man" is a normal checkers piece.
 * All of the pieces are men by default.
 *
 * These pieces can only move away from their starting side.
 * If the color is black, the piece moves up the board (+),
 *   and if red, the piece moves down the board (-).
*/

class Man : public Piece 
{
    using Piece::Piece;
    
    char getSymbol() const override {
        return (color_ == Color::red) ? 'r' : 'b';
    }

    std::vector<Location> getOffsets() const override;
};




/* A man is promoted upon reaching the other side, and is replaced 
 *   by a king. Kings can move both forward and backwards. 
*/
class King : public Piece 
{
    using Piece::Piece;

    char getSymbol() const override {
        return (color_ == Color::red) ? 'R' : 'B';
    }

    std::vector<Location> getOffsets() const override;

};







#endif