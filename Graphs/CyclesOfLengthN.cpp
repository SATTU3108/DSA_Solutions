#include <bits/stdc++.h>
using namespace std;

// Recursive DFS to find cycles of a specific length
void dfs(const vector<vector<bool>> &graph, vector<bool> &visited, int current, int start, int remainingLength, int &count) {
    visited[current]=true;
    // If remainingLength is 0, check if there’s an edge back to the start
    if (remainingLength==0) {
        if (graph[current][start]) count++;
        visited[current]=false;
        return;
    }
    // Explore all adjacent unvisited nodes
    for (int neighbor=0;neighbor<graph.size();neighbor++) {
        if (!visited[neighbor] && graph[current][neighbor]) {
            dfs(graph,visited,neighbor,start,remainingLength-1,count);
        }
    }
    visited[current] = false; // Backtrack
}

// Main function to count cycles of given length in an undirected graph
int countCycles(const vector<vector<bool>> &graph, int cycleLength) {
    int V=graph.size(); // Number of vertices
    vector<bool> visited(V, false);
    int count=0;
    // Try starting DFS from each node up to V - (cycleLength - 1)
    for (int i=0;i<=V-cycleLength;i++) {
        dfs(graph,visited,i,i,cycleLength-1,count);
        visited[i]=true; // Don't start from this node again to avoid duplicates
    }
    return count/2; // Each cycle is counted twice (from both directions)
}