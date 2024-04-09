#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string res="";
        
        for(auto c : num) {
            while(res.length() && res.back() > c && k) {
                res.pop_back();
                k--;
            }
            
            if(res.length() || c != '0')
                res.push_back(c);
        }
        
        while(res.length() && k) {
            k--;
            res.pop_back();
        }
        
        return res.empty() ? "0" : res;
    }
};

int main() {
    ifstream inputFile("../output/Minimum_Integer_input_2.txt");
    ofstream outputFile("../output/output_2.txt");

    if (!inputFile.is_open()) {
        cout << "Error: Unable to open input file." << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cout << "Error: Unable to open output file." << endl;
        return 1;
    }

    string num;
    int k;

    inputFile >> num >> k;

    Solution solution;
    string result = solution.removeKdigits(num, k);

    outputFile << result << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
