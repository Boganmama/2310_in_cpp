#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Game.h"
#include "Savefile.h"

using namespace std;


int main(int argc, char** argv) 
{
    fstream saved(argv[1], ios_base::in);
    if (!saved) return -1;
    string line;

    // get the first line
    getline(saved, line);
    int varpoo;


   
    // char* pch = strtok_r(line, " ");
    // while(pch != NULL)
    // {
    //     printf("%s\n", pch);
    //     pch = strtok_r(line, " ");
    //     varpoo = stoi(pch);
    //     printf("int: %d\n", varpoo);
    // }
    cout << "line is: " << line << endl;
    unsigned int w, h, n, v, i = 0;
    char temp;
    while ((temp = line[i++])) 
    {
        if ( !(isdigit(temp) || temp == ' ') )
        {
            cout << "failed parse. exiting..." << endl;
            exit(-1);
        }
    }
    // successfully parsed
    saved >> w >> h >> n >> v;
    printf("w: %d, h: %d, n: %d, v: %d\n", w, h, n, v);
    
    
    string barfoo("2A3A5A6C6D");
    string foobar("2B3B4B5B7D7C");
    Savefile::Savefile;
    cout << barfoo << '\n' << foobar << '\n' << 
            Savefile::Savefile.check_valid_hand(barfoo, foobar, 2) << endl;

    // char doublearr[]
    return 0;
}