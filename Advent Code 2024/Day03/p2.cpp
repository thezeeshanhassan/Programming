#include <iostream>
#include <fstream>
#include <vector>
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

    // Define regex patterns for valid instructions
    regex mulPattern(R"(mul\((\d+),(\d+)\))");
    regex doPattern(R"(do\(\))");
    regex dontPattern(R"(don't\(\))");
    string line;

    vector<int> arr;
    bool mulEnabled = true; // Multiplications are enabled by default

    while (getline(inputFile, line))
    {
        smatch match;
        // Process the line sequentially
        while (!line.empty())
        {
            if (regex_search(line, match, mulPattern))
            {
                if (mulEnabled) // Only process mul instructions if enabled
                {
                    int x = stoi(match[1]);
                    int y = stoi(match[2]);
                    arr.push_back(x * y);
                    cout << "Processed mul(" << x << "," << y << ") = " << x * y << endl;
                }
                else
                {
                    cout << "Skipped mul(" << match[1] << "," << match[2] << ") due to don't()" << endl;
                }
                line = match.suffix().str();
            }
            else if (regex_search(line, match, doPattern))
            {
                mulEnabled = true;
                cout << "Encountered do(): Multiplications enabled" << endl;
                line = match.suffix().str();
            }
            else if (regex_search(line, match, dontPattern))
            {
                mulEnabled = false;
                cout << "Encountered don't(): Multiplications disabled" << endl;
                line = match.suffix().str();
            }
            else
            {
                break; // No more matches in the line
            }
        }
    }

    inputFile.close();

    // Calculate the sum of the enabled multiplications
    long totalSum = 0;
    cout << "\nEnabled Multiplication Results:" << endl;
    for (int result : arr)
    {
        cout << result << " ";
        totalSum += result;
    }
    cout << "\nTotal Sum: " << totalSum << endl;

    return 0;
}
