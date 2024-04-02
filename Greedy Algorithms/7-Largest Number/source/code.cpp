#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

static bool compareStrings(string str1, string str2) {
    return str1 + str2 > str2 + str1;
}

string findLargestNumber(vector<int>& numbers) {
    vector<string> convertedNumbers;
    for (int num : numbers){
        convertedNumbers.push_back(to_string(num));
    }
    sort(convertedNumbers.begin(), convertedNumbers.end(), compareStrings);
    string result;
    for (auto numStr : convertedNumbers){
        result += numStr;
    }
    return (result[0] == '0') ? "0" : result;
}

int main() {
    ifstream inputFile("../output/Largest_Number_2.txt");
    ofstream outputFile("../output/output_2.txt");

    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open output file." << endl;
        return 1;
    }

    vector<int> numbers;
    int num;
    while (inputFile >> num) {
        numbers.push_back(num);
    }

    string largestNum = findLargestNumber(numbers);

    outputFile << largestNum << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}