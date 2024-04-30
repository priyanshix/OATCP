#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

unordered_set<string> generateShortForms(const string& word) {
    unordered_set<string> shortForms;
    queue<string> q;
    unordered_set<string> visited;

    //BFS
    q.push(word);
    visited.insert(word);

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        shortForms.insert(current);

        for (int i = 0; i < current.size(); ++i) {
            string next = current.substr(0, i) + current.substr(i + 1);
            if (!visited.count(next)) {
                q.push(next);
                visited.insert(next);
            }
        }
    }

    return shortForms;
}

int main() {
    ifstream inputFile("../output/BriefWords_2.txt");
    ofstream outputFile("../output/output_2.txt");

    if (!inputFile.is_open()) {
        cout << "Error opening input file." << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cout << "Error opening output file." << endl;
        return 1;
    }

    int t;
    inputFile >> t;

    for (int i = 0; i < t; ++i) {
        string word;
        inputFile >> word;
        
        unordered_set<string> shortForms = generateShortForms(word);

        outputFile << "Short forms of " << word << " are: ";
        for (const string& sf : shortForms) {
            outputFile << sf << " ";
        }
        outputFile << endl;
    }

    // Close files
    inputFile.close();
    outputFile.close();

    return 0;
}
