#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <optional>

std::unordered_map <char, char>toolToUse = {
    {'X',-1},{'Y',0},{'Z',1}
};

std::unordered_map<char, int>pointsForTool = {
    {'A', 1},{'B',2},{'C',3}
};

std::unordered_map<char, int> pointsPerResult = {
    {'X', 0},{'Y',3},{'Z',6}
};

std::optional<int> toolToPlay(char opponentTool, int direction)
{
    std::string toolOrder = "CABCA";
    int opponentPos = toolOrder.find(opponentTool, 1);
    if(opponentPos == std::string::npos){
        std::cout << "invalid input" << "\n";
        return std::nullopt;
    }
    int wantedPos = opponentPos + direction;
    return toolOrder[wantedPos];
}

std::optional<int> chooseDirection(char expectedOutcome){
    std::unordered_map<char , char>::iterator iterator = toolToUse.find(expectedOutcome);
    if( iterator == toolToUse.end()){
        std::cout << " invalid input" << "\n";
        return std::nullopt;
    }
    return iterator -> second ;
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
            std::optional<int> dirVal = chooseDirection(result);
            if(!dirVal.has_value()){
                continue;
            }
            std::optional<char> myTool = toolToPlay(compTool, dirVal.value());
            if(!myTool.has_value()){
                continue;
            }
            
            score += pointsForTool.at(myTool.value()) + pointsPerResult.at(result);
        }
    }
    std::cout << score;
    return 0;
}