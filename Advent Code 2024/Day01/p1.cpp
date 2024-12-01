#include <iostream>
#include <fstream>
#include <vector>
#include<algorithm>

using namespace std;

int main() {
    string filename = "input.txt"; 

    ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    vector<int> leftArray, rightArray;

    int left, right;

    while (inputFile >> left >> right) {
        leftArray.push_back(left);
        rightArray.push_back(right);
    }

    inputFile.close();

    sort(leftArray.begin(), leftArray.end());
    sort(rightArray.begin(), rightArray.end());
    long diff{};
    for(int i{}; i < leftArray.size(); i += 1) {
        int difference = abs(leftArray[i] - rightArray[i]);
        diff += difference;
        difference = 0;
    }
    cout<<diff<<endl;

    return 0;
}
