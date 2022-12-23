#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int main(){
    std::ifstream input("testInput.txt");
    std::string outline;
    std::vector <int> totals;

    while(std::getline(input, outline)){
        if(outline.size() == 0){
            totals.emplace_back(0);
        }else {
            totals.back() += std::stoi(outline);
        }

    }
    for(int i: totals){
        std::cout << i << "/n";
    }
    
    return 0;
}