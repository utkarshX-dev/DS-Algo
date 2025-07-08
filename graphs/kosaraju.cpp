#include <iostream>
using namespace std;
#include <bits/stdc++.h>
class Solution { 
  private:
    stack<int>st;
    vector<int>visited;
    vector<int>sccVisited;
    void topoSort(int node, vector<vector<int>>& adj){
        visited[node] = 1;
        for(auto& nbs : adj[node]){
            if(!visited[nbs]){
                topoSort(nbs, adj);
            }
        }
        st.push(node);
    }
     void dfs(vector<vector<int>>& revAdj, int node){
        sccVisited[node] = 1;
        for(auto& nbs : revAdj[node]){
            if(!sccVisited[nbs]){
                dfs(revAdj, nbs);
            }
        }
    }
  public:
    int kosaraju(vector<vector<int>> &adj) {
        int V = adj.size();
        visited.resize(V + 1, 0);
        sccVisited.resize(V + 1, 0);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                topoSort(i, adj);
            }
        }
        vector<vector<int>>revAdj(V + 1);
        for(int i = 0; i < V; i++){
            for(auto& nbr : adj[i]){
                revAdj[nbr].push_back(i);
            }
        }
        int cnt = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!sccVisited[node]){
                cnt++;
                dfs(revAdj, node);
            }
        }
        return cnt;
    }
};