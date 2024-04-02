#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

const int N = 200;

int a[N], b[N], dp[N][N];

int main()
{
    ifstream input_file("C://Users/Prayani/Desktop/PROJECTS & ASSIGNMENTS/OATCP/Bersu Ball/output/BersuBall_input_3.txt");
    ofstream output_file("C://Users/Prayani/Desktop/PROJECTS & ASSIGNMENTS/OATCP/Bersu Ball/output/output_3.txt");

    int n;
    input_file >> n;
    for (int i = 0; i < n; i++)
        input_file >> a[i];
    
    int m;
    input_file >> m;
    for (int i = 0; i < m; i++)
        input_file >> b[i];
    
    sort(a, a + n);
    sort(b, b + m);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (i - 1 >= 0 && j - 1 >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            if (abs(a[i] - b[j]) <= 1)
                dp[i][j]++;
            if (i - 1 >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (j - 1 >= 0)
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
        }
    
    output_file << dp[n - 1][m - 1];

    input_file.close();
    output_file.close();
    
    return 0;
}
