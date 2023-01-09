#include <iostream>
#include <string>
#include <fstream>

int pointsForTool(char tool) {
    switch (tool) {
        case 'X': return 1;
        case 'Y': return 2;
        case 'Z': return 3;
    }
};

char myWinningTool(char tool){
    switch (tool){
    case 'A': return 'Y';
    case 'B': return 'Z';
    case 'C': return 'X';
    }
}
char myLoosingTool(char tool){
    switch (tool){
    case 'A': return 'Z';
    case 'B': return 'X';
    case 'C': return 'Y';
    }
}

int checkWTL(char computer,char me){
    if (myWinningTool(computer) == me) {
        return 6;
    }
    if (myLoosingTool(computer) == me) {
        return 0;
    }
    return 3;
}

int main()
{
    std::fstream input("input.txt");
    std::string outline;
    int score {0};

    if (input.is_open())
    {
        while (std::getline(input, outline))
        {
            char myTool = outline[2];
            char compTool = outline[0];
            score += pointsForTool(myTool) + checkWTL(compTool, myTool);
            
        }
    }
    std::cout << score;
    return 0;
}