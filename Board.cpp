
#include "Board.h"
#include "Piece.h"
#include <memory>


//TODO


Board::Board() {

};

std::shared_ptr<Piece> Board::getPiece(const Location& square) const {
    return pieces.at(square);
};




bool Board::movePiece(Location current, Location destination) {

};
