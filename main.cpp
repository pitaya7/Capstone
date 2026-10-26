/*
 * 
 * 
 * 
 * 
 * 
 * 
 * 
*/

#include <iostream>
#include <optional>
#include "Board.h"
#include "Player.h"
#include "Piece.h"
#include "Location.h"
#include <ncurses.h>
#include <form.h>
#include <ostream>

using namespace std;


int main()
{
 
    Board* board = new Board;
    Location loc{.row=4,.column=5};
    cout << loc.column <<endl;
    board->displayBoard(red);



    /* initscr();
    //TODO 
    FORM *test_form;
    FIELD *test_fields[3];
    test_fields[0] = new_field(1, 10, 0, 0, 0, 0);
    test_fields[1] = new_field(1, 10, 1, 0, 0, 0);
    test_fields[2] = NULL;
     test_form = new_form(test_fields);
    
    // display menu, prompt

    // init board, players, pieces

    // loop: play current player's turn, currentturn++
    // end if game won or stalemate (or user input is "quit")
    endwin(); */

};
