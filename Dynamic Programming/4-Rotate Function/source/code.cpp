#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int maxRotateFunction(const vector<int>& nums, int n) {
    //next rot: f(prev)+sum-(n)*last_ele
    //last term signifies removal of contri of last_ele from current as 0*le+its last contri
    if(nums.empty()) return 0;
    int f0 = 0, sum = 0, maxi;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        f0 += i * nums[i];
    }
    int dp[n];
    dp[0] = f0, maxi = dp[0];
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i-1] + sum - n * nums[n - i];
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}

int main() {
    ifstream inputFile("C://Users/Prayani/Desktop/PROJECTS & ASSIGNMENTS/OATCP/Rotate Function/output/Rotate_Function_input_3.txt");
    ofstream outputFile("C://Users/Prayani/Desktop/PROJECTS & ASSIGNMENTS/OATCP/Rotate Function/output/output_3.txt");

    int size;
    inputFile >> size;

    vector<int> nums(size);
    for (int i = 0; i < size; ++i) {
        inputFile >> nums[i];
    }

    int result = maxRotateFunction(nums, size);
    outputFile << result << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
