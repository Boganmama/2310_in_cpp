#include "Savefile.h"


Savefile(std::ifstream fileContents)
{
    // TODO: need to grab these from file
}

Savefile(std::string filename)
{
    
}

/**
 * Constructor that uses explicit args to build the savefile
 * data struct
 * 
 */
Savefile(unsigned int width, unsigned int height,
        unsigned int nCardsDrawn, unsigned in vTurnnow,
        std::string deckFile, std::stsring p1Hand, std::string p2Hand)
{
    width_ = width;
    height_ = height;
    nCardsDrawn_ = nCardsDrawn;
    vTurnNow_ = vTurnNow;
    
    // read file
    std::ifstream deck("deckFile");
    if (!deck) return nullptr;
    deckFile_ = deckFile;
    close(deck);

    if (!check_valid_hand(p1Hand_, p2Hand_, vTurnNow_)) return nullptr;
    p1Hand_ = p1Hand;
    p2Hand_ = p2Hand;
}

bool check_valid_hand(std::string p1Hand, std::string p2Hand, 
                        unsigned int vTurnNow)
{
    // check hands have numbers and suits
    if (p1Hand.length() % 2 != 0 || p2Hand.length() % 2 != 0) 
    {
        return false;
    }

    // check p1 hand
    for (int i = 0; i < p1Hand.length(); i += 2)
    {
        if (!isdigit(p1Hand[i]) || !(p1Hand[i+1] >= 'A' && p1Hand[i+1] <= 'Z'))
        {
            return false;
        }
    }

    // check p2 hand
    for (int i = 0; i < p2Hand.length(); i += 2)
    {
        if (!isdigit(p2Hand[i]) || !(p2Hand[i+1] >= 'A' && p2Hand[i+1] <= 'Z'))
        {
            return false;
        }
    }

    if ( (vTurnNow == 1 && p1Hand.length() - 2 != p2Hand.length) ||
            vTurnNow == 2 && p2Hand.length() - 2 != p1Hand.length )
    {
        return false;
    }

    // checks are good
    return true;
}