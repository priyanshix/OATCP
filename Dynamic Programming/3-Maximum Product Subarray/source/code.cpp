#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    if (n == 0)
        return 0;
    
    int minProduct = nums[0]; // Initialize minProduct with the first element
    int maxProduct = nums[0];
    int ans = nums[0];

    for(int i = 1; i < n; i++) {
        if(nums[i] < 0) {
            swap(maxProduct, minProduct);
        }
        maxProduct = max(maxProduct * nums[i], nums[i]);
        minProduct = min(minProduct * nums[i], nums[i]);
        ans = max(ans, maxProduct);
    }
    return ans;
}

int main() {
    ifstream inputFile("C://Users/Prayani/Desktop/PROJECTS & ASSIGNMENTS/OATCP/Maximum Product Subarray/output/Max_Prod_SubArray_input_3.txt");
    ofstream outputFile("C://Users/Prayani/Desktop/PROJECTS & ASSIGNMENTS/OATCP/Maximum Product Subarray/output/output_3.txt");

    if (!inputFile.is_open()) {
        cout << "Unable to open input file!" << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cout << "Unable to open output file!" << endl;
        return 1;
    }

    int n;
    inputFile >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        inputFile >> nums[i];
    }

    int result = maxProduct(nums);

    outputFile << result << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
