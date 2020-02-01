#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <fstream>
#include "Game.h"

using namespace std;

/*------------ private declarations ------------*/
// checks arguments TODO: returns a game struct
int arg_check(int, char**);
// prints an exit status and then exits 
void print_exit_status(int); 
// helper to check if a single word is a non-negative integer
bool is_all_digits(const string&);

/*------------ function definitions ------------*/

/**
 * Main function
 * 
 * Returns 0 upon successful execution
 */
int main(int argc, char** argv) 
{
    // process input
    arg_check(argc, argv);
    Game thisGame;
    // load the input into argcheck and then the game struct

    // Game playing
    while(1) 
    {
        // play turn 
        thisGame = Game::play_turn(thisGame);
        //  check win condition:    if (win)
        if (is_game_over(thisGame)) 
        {
            // TODO: finish game and exit loop
        }
    }
    return 0;
}


/**
 * Helper function to check command line arguments
 * 
 * To start a new game: 
 *      bark deckfile width height p1type p2type
 * To load a saved game:
 *      bark savefile p1type p2type
 * 
 * TODO: should return a data structure called game, which is preconfigured
 */
int arg_check(int argc, char** argv) 
{
    ifstream deckFile;     
    if (!(argc == 4 || argc == 6)) 
    {
        print_exit_status(1); // and exits
    } 
    else if (argc == 4) 
    {
        // initialise the game from save file
        ifstream saveFile(argv[1], ios_base::in);
        if (!saveFile) print_exit_status(4); 
        Savefile contents = parse_save_file(saveFile);
    } 
    else // argc == 6
    {
        // run the checks on sizing
        unsigned int width, height;

        // check that digits are good
        if (!( is_all_digits(argv[2]) && is_all_digits(argv[3]) ))
        {
            print_exit_status(2);
        } else {
            try
            {
                width = stoi(argv[2]);
                height = stoi(argv[3]);
            }
            catch (const std::invalid_argument& e) 
            {
                print_exit_status(2);
            }
            catch (const std::out_of_range& e) 
            {
                print_exit_status(2);
            }
        }

        string p1(argv[4]);
        string p2(argv[5]);

        if (!((p1.compare("h") == 0 || p1.compare("a") == 0)
                && (p2.compare("h") == 0 || p2.compare("a") == 0))
                || width < 4 || width > 99 || height < 4 || height > 99)
        {
            print_exit_status(2);
        }
    }
}

/**
 * Assumes that there are no trailing whiwtespaces.
 * Processes a word (string) to check if all characters in the
 * string are digits
 */
bool is_all_digits(const string& word)
{
    return !word.empty() && 
            find_if(word.begin(), 
                    word.end(), 
                    [](unsigned char c) {return !isdigit(c); }) == word.end();
}


/**
 * Prints the appropriate exit status to the command line, and then exits
 * 
 */
void print_exit_status(int code) 
{
    string message("");

    switch (code)
    {
    case 0:
        break;  
    case 1:
        message.assign("Usage: bark savefile p1type p2type\n" \
                "bark deck width height p1type p2type");
        break;
    case 2:
        message.assign("Incorrect arg types");
        break;
    case 3:
        message.assign("Unable to parse deckfile");
        break;
    case 4:
        message.assign("Unable to parse savefile");
        break;
    case 5:
        message.assign("Short deck");
        break;
    case 6:
        message.assign("Board full");
        break;
    case 7:
        message.assign("End of input");
        break;  
    default:
        // broke unintendedly
        exit(-1);
    }

    cerr << message << endl;
    // succesful exit
    exit(code);
}

/**
 * TODO: check that we can pass an input stream
 *       create a savefile data struct
 *       
 * ret: returns a custom data struct 'Savefile' which
 *      contains data of the valid save file;
 *      else, returns nullptr
 */
Savefile parse_save_file(ifstream contents)
{
    // exit if null
    if (!contents) return nullptr;
    string line;
    
    // process the first line
    getline(contents, line);
    unsigned width, height, cards, turn, i = 0;
    char temp;
    while ( temp = line[i++] )
    {
        if ( !(isdigit(temp) || temp == ' ' ) )
        {
            print_exit_status(4);
        }
    }
    // succesfully parsed the first line
    contents >> width >> height >> cards >> turn;

    // process the second line
    getline(contents, line);
    ifstream deck(line, ios_base::in);
    string deckFull = parse_deck_file(ifstream deck);
    if (!deck || deckFull.equals(nullptr)) return nullptr;
    
    // hand contents
    getline(contents, line);
    string p1hand = line;   // strcopy?
    getline(contents, line);
    string p2hand = line;   // strcopy?

    string board("");
    while (getline(contents, line))
    {
        board.append(line);
    }

    // TODO: save it all in a savefile struct
}