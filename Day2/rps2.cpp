#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

std::unordered_map <char, char>toolToUse = {
    {'X',-1},{'Y',0},{'Z',1}
};

std::unordered_map<char, int>pointsForTool = {
    {'A', 1},{'B',2},{'C',3}
};

std::unordered_map<char, int> pointsPerResult = {
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

char toolToPlay(char opponentTool, int direction)
{
    std::string toolOrder = "CABCA";
    int opponentPos = toolOrder.find(opponentTool, 1);
    int wantedPos = opponentPos + direction;
    return toolOrder[wantedPos];
}

int chooseDirection(char expectedOutcome){
    int direction = toolToUse.at(expectedOutcome);
    return direction;
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
            if(outline.size()<3){
            std::cout << "missing input" << "\n";
            continue;
        }
            char result = outline[2];
            char compTool = outline[0];

            char myTool = toolToPlay(compTool, chooseDirection(result));

            score += pointsForTool.at(myTool) + pointsPerResult.at(result);
        }
    }
    std::cout << score;
    return 0;
}