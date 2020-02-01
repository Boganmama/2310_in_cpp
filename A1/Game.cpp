#include "Game.h"


Game(std::string file, char p1type, char p2type)
{
    file_ = file;
    // TODO: need to grab these from file_
    // width_ = width;
    // height_ = height;
    p1type_ = p1type;
    p2type_ = p2type; 
    saved_ = true;
    p1turn = true;
    // TODO: load board state from save file
}

Game(std::string file, unsigned int width, unsigned int height,
        const char p1type, const char p2type)
{
    file_ = file;
    width_ = width;
    height_ = height;
    p1type_ = p1type;
    p2type_ = p2type;
    saved_ = false;
    p1turn = true;
    // TODO:initialise board from the dims
}

unsigned int getWidth();
unsigned int getHeight();
char getp1Type();
char getp2Type();
const char* filePath();
char** getBoard();
bool is_p1_to_play();
Game play_turn(Game);
bool is_game_over();