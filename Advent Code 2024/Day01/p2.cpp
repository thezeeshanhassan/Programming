#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    string filename = "input.txt";

    ifstream inputFile(filename);
    if (!inputFile)
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    vector<int> leftArray, rightArray;

    int left, right;

    while (inputFile >> left >> right)
    {
        leftArray.push_back(left);
        rightArray.push_back(right);
    }

    inputFile.close();

    map<int, int> map;
    for(int i{}; i < leftArray.size(); i += 1) {
        map[leftArray[i]] = 0;
    }
    long sum{};
    for (int i{}; i < rightArray.size(); i += 1)
    {
        map[rightArray[i]] += 1;
    }

    for(int i{} ; i < leftArray.size(); i += 1) {
        int frequency{map[leftArray[i]]};
        sum += frequency * leftArray[i];
    }
    cout<<sum;

    return 0;
}