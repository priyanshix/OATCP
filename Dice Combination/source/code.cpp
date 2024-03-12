#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int countWays(int n) {
    if (n < 0)
        return 0;

    vector<int> dp(n + 1, 0);
    dp[0] = 1; // There's 1 way to get a sum of 0

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 6 && i - j >= 0; ++j) {
            dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }

    return dp[n];
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        cout << "Error opening input file." << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cout << "Error opening output file." << endl;
        return 1;
    }

    int totalInputs;
    inputFile >> totalInputs;

    for (int i = 0; i < totalInputs; ++i) {
        int sum;
        inputFile >> sum;
        int ways = countWays(sum);
        outputFile << ways << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
