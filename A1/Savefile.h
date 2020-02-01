/**
 * Savefile class to represent the file format of a save file
 * @author
 *  Joshua Tambunan <joshptambunan@gmail.com>
 */
#pragma once

#include <iostream>
#include <string>
#include <fstream>

class Savefile
{
public:
    bool check_valid_hand(std::string, std::string, unsigned int);

private:
    unsigned int width_;
    unsigned int height_;
    unsigned int nCardsDrawn_;
    unsigned int vTurnNow;
    std::string deckFile_;
    std::string p1Hand_;
    std::string p2Hand_;
};