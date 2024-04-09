#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <istream>

using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patches = 0, i = 0, sz = nums.size();
        long count = 1;
        while (count <= n) {
            if (i < sz && nums[i] <= count)
                count += nums[i++];
            else {
                count *= 2;
                patches++;
            }
        }
        return patches;
    }
};

int main() {
    ifstream infile("../output/Patching_Array_input_2.txt");
    ofstream outfile("../output/output_2.txt");

    if (!infile.is_open()) {
        cout << "Failed to open input file." << endl;
        return 1;
    }
    if (!outfile.is_open()) {
        cout << "Failed to open output file." << endl;
        return 1;
    }

    vector<int> nums;
    int n, num;
    string line;
    getline(infile, line);
    istringstream iss(line);
    while (iss >> num) {
        nums.push_back(num);
    }
    infile >> n;

    infile.close();

    Solution sol;

    int result = sol.minPatches(nums, n);

    outfile << result << endl;

    outfile.close();

    return 0;
}
