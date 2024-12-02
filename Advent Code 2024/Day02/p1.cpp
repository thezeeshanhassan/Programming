#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

bool isSafeReport(const vector<int> &report)
{
    bool status{true};
    int difference{};
    bool assending{true};
    if (report[0] > report[1])
    {
        assending = false;
    }
    for (int i{1}; i < report.size(); i += 1)
    {
        difference = abs(report[i] - report[i - 1]);
        if (difference < 1 || difference > 3)
        {
            return false;
        }
    }

    for (int i{1}; i < report.size(); i += 1)
    {
        if (assending == true)
        {
            if (report[i] < report[i - 1])
            {
                status = false;
                break;
            }
        }
        if (assending == false)
        {
            if (report[i] > report[i - 1])
            {
                status = false;
                break;
            }
        }
    }
    return status;
}

int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;
    int safe{};

    while (getline(inputFile, line))
    {

        stringstream ss(line);
        vector<int> report;
        int num;
        while (ss >> num)
        {
            report.push_back(num);
        }

        if (isSafeReport(report))
        {
            safe += 1;
        }

        report.clear();
    }

    inputFile.close();
    cout << "Number of safe reports: " << safe << endl;
    return 0;
}
