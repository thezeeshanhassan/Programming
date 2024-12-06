#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <regex>
using namespace std;

int main()
{
    // Open the input file
    ifstream inputFile("input.txt");
    if (!inputFile)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // Define regex pattern for valid mul(X,Y) instructions
    regex pattern(R"(mul\((\d+),(\d+)\))");
    string line;

    vector<int> arr;

    while (getline(inputFile, line))
    {
        smatch match;
        while (regex_search(line, match, pattern))
        {
            int x = stoi(match[1]);
            int y = stoi(match[2]);
            cout << match[0] << endl;
            arr.push_back(x * y);
            line = match.suffix().str();
        }
    }

    inputFile.close();


    long totalSum = 0;
    cout << "Multiplication Results:" << endl;
    for (int result : arr)
    {
        totalSum += result;
    }
    cout << totalSum; 
    cout << endl;

    return 0;
}
