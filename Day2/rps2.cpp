#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

std::unordered_map <char, int>myWinningTool = {

};

std::unordered_map <char, char>toolToUse = {
    {},{},{}
};

std::unordered_map<char, int>pointsForTool = {
    {'A', 1},{'B',2},{'C',3}
};

std::unordered_map<char, int> resultPerTool = {
    {'X', 0},{'Y',3},{'Z',6}
};


/*
    A:rock,1
    B:paper,2
    C:scissors,3
*/

/*
    X:Lose,
    Y:Tie,
    Z:Win

*/

char tool_to_play(char opponent_tool, int direction)
{
    std::string toolOrder = "ZXYZX";
    int opponentPos = toolOrder.find(opponent_tool, 1);
    int wantedPos = opponentPos + direction;
    return toolOrder[wantedPos];
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

        }
    }
    std::cout << score;
    return 0;
}