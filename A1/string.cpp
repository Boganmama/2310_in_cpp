#include <iostream>
#include <string>

int main(int argc, char** argv) 
{

    std::string orig;
    orig = argv[1];
    std::string cpy = orig;
    std::cout << "orig: " << orig << std::endl;
    std::cout << "cpy: " << cpy << std::endl;

    // let's change
    std::cout << "changing" << std::endl;
    orig[2] = 'x';
    std::cout << "orig: " << orig << std::endl;
    std::cout << "cpy: " << cpy << std::endl;
    return 0;
}