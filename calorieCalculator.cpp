#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ifstream input ("input.txt");
    string myInput;
    string outline;
    int max{};
    int total{};
    if (input.is_open())
    {
        while (input.good())
        {
            getline(input, outline);
        }if(outline.size() == 0){
            max = std::max(max, total);
            total = 0;
        } else {
            total += std::stoi(outline);
        }
    }
    max = std::max(max, total);
    cout << max;
    return max;
}