//tarjan algorithm to find bridges in a graph
#include <iostream>
using namespace std;
#include <bits/stdc++.h>
class Solution {
private:
    vector<vector<int>> res;
    vector<vector<int>> adj;
    vector<int> visited;
    vector<int> low;
    vector<int> desc;
    int time = 0;

    void dfs(int node, int parent) {
        visited[node] = 1;
        low[node] = desc[node] = time;

        for (int& nbr : adj[node]) {
            if (nbr == parent) {
                continue;
            } else if (visited[nbr]) {
                low[node] = min(low[node], low[nbr]);
            } else {
                time++;
                dfs(nbr, node);
                if (desc[node] < low[nbr]) {
                    res.push_back({node, nbr});
                }
                low[node] = min(low[node], low[nbr]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        visited.resize(n, 0);
        adj.resize(n);
        low.resize(n);
        desc.resize(n);
        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, -1);
        return res;
    }
};