/*
 *
 * 
 * 
 * 
**/

#include "Piece.h"
#include "Location.h"
#include <vector>


//Move m =


// Constructor taking a Location
Piece::Piece(Color color, Location start_position) {
    Piece::color_ = color;
    Piece::location_ = start_position;
    //Piece::moveOffsets = Piece::getOffsets();
};

// Constructor taking location values and storing as a Location
Piece::Piece(Color color, int row, int column) {
    // Constructor
    Piece::color_ = color;
    Piece::location_ = Location{row,column};
    //Piece::moveOffsets = Piece::getOffsets();
};

Location Piece::getLocation() const {
    return location_;
};




void Piece::moveTo(Location destination) {

};










/* Black piece moves black side --> red side (up left or up right)
 * Red piece moves red side --> black side (down left or down right)
*/
std::vector<Location> Man::getOffsets() const {
    if (color_ == Color::black)
        return std::vector<Location>{{1,1}, {-1,1}};
    else
        return std::vector<Location>{{-1,1},{-1,-1}};

};

// Either color king can move both up left/right and down left/right 
std::vector<Location> King::getOffsets() const {
    return std::vector<Location>{{1,1},
                                 {1,-1}, 
                                 {-1,1}, 
                                 {-1,-1} };
};
