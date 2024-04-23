#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
#include <chrono>
using namespace std;
using namespace std::chrono;

bool bfs(vector<vector<int>>& arr, int src, int dest, vector<int>& parent) {
    int n = arr.size();
    vector<int> visited(n, 0);
    visited[src] = 1;
    parent[src] = -1;
    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0 && arr[front][i] != 0) {
                if (i == dest) {
                    parent[i] = front;
                    return true;
                }
                q.push(i);
                parent[i] = front;
                visited[i] = 1;
            }
        }
    }
    return false;
}
auto start = high_resolution_clock::now(); // Start the timer
int findMaxFlow(int N, int src, int dest, vector<vector<int>> Edges, double& timeTaken) {
    //Ford Fulkerson Algorithm
    vector<vector<int>> rgraph(N, vector<int>(N, 0));
    int M = Edges.size(); // Number of edges
    for (int i = 0; i < M; i++) {
        int u = Edges[i][0];
        int v = Edges[i][1];
        int w = Edges[i][2];
        rgraph[u - 1][v - 1] += w;
        rgraph[v - 1][u - 1] += w;
    }
    vector<int> parent(N, 0);
    int maxflow = 0;

    while (bfs(rgraph, src-1, dest - 1, parent)) {
        int BNC = INT_MAX;
        for (int i = N - 1; i != 0; i = parent[i]) {
            int u = parent[i];
            BNC = min(BNC, rgraph[u][i]);
        }
        for (int i = N - 1; i != 0; i = parent[i]) {
            int u = parent[i];
            rgraph[u][i] -= BNC;
            rgraph[i][u] += BNC;
        }
        maxflow += BNC;
    }

    auto stop = high_resolution_clock::now(); // Stop the timer

    timeTaken = duration_cast<milliseconds>(stop - start).count();

    return maxflow;
}

int main() {
    ifstream inputFile("../output/input.txt");
    ofstream outputFile("../output/output.txt");

    int N; // Number of vertices
    inputFile >> N;

    int src, dest;
    inputFile >> src >> dest;

    vector<vector<int>> Edges; // Vector to store edges

    // Reading edges until the end of the file
    int u, v, w;
    while (inputFile >> u >> v >> w) {
        Edges.push_back({u, v, w});
    }

    double timeTaken;
    int maxFlow = findMaxFlow(N, src, dest, Edges, timeTaken);
    outputFile << "Max Flow: " << maxFlow << endl;
    outputFile << "Time Taken (milliseconds): " << timeTaken << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
