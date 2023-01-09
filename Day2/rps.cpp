#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::fstream input("testInput.txt");
    std::string outline;
    int score {0};

    char one   {'X'};
    char two   {'Y'};
    char three {'Z'};


    if (input.is_open())
    {
        while (std::getline(input, outline))
        {
            
            



        }
    }
    std::cout << score;
    return 0;
}