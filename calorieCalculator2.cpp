#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>

int main(){
    std::fstream input("testInput.txt");
    std::string outline;
    std::vector <int> totals(0,1);

    while(std::getline(input, outline)){
        if(outline.size() == 0){
            totals.emplace_back(0);
        }else {
            totals.back() += std::stoi(outline);
        }

    }
    for(auto i: totals){
        std::cout << i << "/n";
    }
   
    
    return 0;
}