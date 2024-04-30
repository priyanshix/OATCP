#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;
void euler(unordered_map<int, stack<int>>& adj, vector<vector<int>>& ans, int curr) {
    auto& stk = adj[curr];
    while (!stk.empty()) {
        int nei = stk.top();
        stk.pop();
        euler(adj, ans, nei);
        ans.push_back({curr, nei});
    }
}
vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
    int m = pairs.size();
    // Eulerian Path
    unordered_map<int, stack<int>> adj;
    unordered_map<int, int> in;
    unordered_map<int, int> out;
    adj.reserve(m);
    in.reserve(m);
    out.reserve(m);
    for (int i = 0; i < m; i++) {
        int u = pairs[i][0], v = pairs[i][1];
        in[v]++;
        out[u]++;
        adj[u].push(v);
    }
    int start = -1;
    for (auto& p : adj) {
        int i = p.first;
        if (out[i] - in[i] == 1) start = i;
    }
    if (start == -1) {
        // Eulerian Circuit -> start at any node
        start = adj.begin()->first;
    }
    vector<vector<int>> ans;
    euler(adj, ans, start);
    reverse(ans.begin(), ans.end());
    return ans;
}
int main() {
    ifstream infile("../output/ValidPairs_2.txt");
    ofstream outfile("../output/output_2.txt");

    int n;
    infile >> n;
    vector<vector<int>> pairs(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        infile >> pairs[i][0];
        infile >> pairs[i][1];
    }

    vector<vector<int>> result = validArrangement(pairs);

    if (result.size() != n) {
        outfile << "No valid arrangement possible" << endl;
    } else {
        for (const auto& pair : result) {
            outfile << pair[0] << " " << pair[1] << endl;
        }
    }

    infile.close();
    outfile.close();

    return 0;
}