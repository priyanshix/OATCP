#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int maxIceCream(vector<int>& costs, int coins) {
    if (coins <= 0) return 0;
    sort(costs.begin(),costs.end());
    for(int i=0;i<costs.size();i++){
        coins -= costs[i];
        if(coins<0) return i;
    }
    return costs.size();
}

int main() {
    ifstream inputFile("../output/Maximum_Ice_Bars_3.txt");
    ofstream outputFile("../output/output_3.txt");

    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open output file." << endl;
        return 1;
    }

    int n, coins;
    inputFile >> n;

    vector<int> costs(n);
    for (int i = 0; i < n; ++i) {
        inputFile >> costs[i];
    }
    inputFile >> coins;
    int result = maxIceCream(costs, coins);

    outputFile << result << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
