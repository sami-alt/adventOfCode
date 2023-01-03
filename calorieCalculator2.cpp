#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>

int main(){
    std::fstream input("input.txt");
    std::string outline;
    std::vector <int> totals = {0};

    while(std::getline(input, outline)){
        if(outline.size() == 0){
            totals.emplace_back(0);
        }else {
            totals.back() += std::stoi(outline);
        }

    }
    
    std::sort(totals.begin(), totals.end(), std::greater<int>());

    int endResult = totals[0]+totals[1]+totals[2]; 
    std::cout << endResult << '\n';
    /*
    for(auto i: totals){
        std::cout << i << '\n';
    }
   */
    
    return 0;
}