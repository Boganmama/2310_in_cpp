/**
 * Simple Game class to represent the game of bark
 * @author
 *  Joshua Tambunan <joshptambunan@gmail.com>
 */
#pragma once

#include <iostream>
#include <string>

class Game 
{
    public:
        unsigned int getWidth();
        unsigned int getHeight();
        char getp1Type();
        char getp2Type();
        const char* filePath();
        char** getBoard();
        bool is_p1_to_play();
        Game play_turn(Game game);
        bool is_game_over(Game game);


    private:
        char p1type_, p2type_;      // player types ('h' = hooman, 'a' = AI)
        unsigned int width_, height_;   // board dimensions
        std::string file_;   // relative path to deck/save file
        bool saved_;    // whether or not invoked w/save
        char** board_;  // the current state of the board, as 2D arr
        bool p1turn_; // boolean of whose turn it is next to play
};