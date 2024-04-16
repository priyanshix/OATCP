#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int totalHammingDistance(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    for(int j=0;j<32;j++){
        int one = 0, z = 0;
        for(int i=0;i<n;i++){
            int bit = (nums[i] >> j) & 1;
            if(bit == 1) one++;
            else z++;
        }
        ans += one * z;
    }   
    return ans;
}

int main() {
    ifstream inputFile("../output/HammingDistance_2.txt");
    ofstream outputFile("../output/output_2.txt");

    if (!inputFile.is_open()) {
        cout << "Error opening input file." << endl;
        return 1;
    }
    if (!outputFile.is_open()) {
        cout << "Error opening output file." << endl;
        return 1;
    }

    vector<int> nums;
    int num;
    while (inputFile >> num) {
        nums.push_back(num);
    }

    int result = totalHammingDistance(nums);

    outputFile << result << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
