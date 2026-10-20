

#ifndef PLAYER_H
#define PLAYER_H


#include <string>
#include <vector>
#include "Board.h"
#include "Piece.h"



class Player {
    protected:
        Color color_;

    public:
        Player(Color color);
        virtual ~Player() = default;

        Color getColor() const;
        std::string name() const { return color_ == Color::black ? "Black" : "Red"; }

        /* Prompts UserPlayer for input, or starts AIPlayer's algorithm
         * only allows legal moves (gotten from board)
        **/

        virtual Move chooseMove(const Board& board, const std::vector<Move>& legalMoves) = 0;
};

class UserPlayer : public Player {
    public:
        using Player::Player;
        Move chooseMove(const Board& board, const std::vector<Move>& legalMoves) override;
};



/* Non-user opponent. 
 * Lower difficulty (selected by user) chooses worse moves.
 * TODO: implement coh
*/
class AIPlayer : public Player {
    private:
        int difficulty_;

    public:
        AIPlayer(Color color, int difficulty) : Player(color), difficulty_(difficulty) {}
        Move chooseMove(const Board& board, const std::vector<Move>& legalMoves) override;
};












#endif