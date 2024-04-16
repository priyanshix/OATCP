#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int N = sizeof(unsigned int) * 8; // Number of bits in unsigned int

vector<vector<unsigned int>> preprocess_grid(vector<vector<int>>& grid, int n) {
    vector<vector<unsigned int>> processed_grid(n, vector<unsigned int>((n / N) + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                processed_grid[i][j / N] |= (1 << (j % N));
            }
        }
    }
    return processed_grid;
}

int count_subgrid(const vector<vector<unsigned int>>& processed_grid, int n) {
    int subgrids = 0;
    for (int a = 0; a < n; a++) {
        for (int b = a + 1; b < n; b++) {
            int count = 0;
            for (int k = 0; k <= n / N; k++) {
                count += __builtin_popcount(processed_grid[a][k] & processed_grid[b][k]);
            }
            subgrids += ((count - 1) * count) / 2;
        }
    }
    return subgrids;
}

int main() {
    ifstream infile("../output/CountingSubgrids_1.txt");
    ofstream outfile("../output/output_1.txt");

    if (!infile) {
        cout << "Error: Unable to open input file." << endl;
        return 1;
    }

    if (!outfile) {
        cout << "Error: Unable to open output file." << endl;
        return 1;
    }

    int n;
    infile >> n;
    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            infile >> grid[i][j];
        }
    }

    vector<vector<unsigned int>> processed_grid = preprocess_grid(grid, n);
    int result = count_subgrid(processed_grid, n);

    outfile << result << endl;

    infile.close();
    outfile.close();

    return 0;
}
