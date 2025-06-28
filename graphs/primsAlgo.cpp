#include <bits/stdc++.h>
#include <iostream>
// User function Template for C++
//need parent array if want to create mst
class Solution {
  public:
    int primsAlgo(int V, vector<vector<int>> &edges) {
       vector<vector<pair<int, int>>>adj(V);
       for(auto &e : edges){    
           int  u = e[0];
           int  v = e[1];
           int  w = e[2];
           adj[u].push_back({v, w});
           adj[v].push_back({u, w});
        }
       
       
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int ,int>>> pq;
        vector<int>visited(V, 0);
        pq.push({0, 0});
       //wt node parent
        int sum = 0;
        while(!pq.empty()){
           //get node parent and wt
            auto curr = pq.top();
            pq.pop();
            int wt = curr.first;
            int node = curr.second;
            if(visited[node]) continue;
            visited[node] = 1;
            
            sum += wt;
            for(auto &nbs : adj[node]){
                int nbr = nbs.first;
                int nbrWt = nbs.second;
                if(!visited[nbr]);
                pq.push({nbrWt, nbr});
                }
            }
            return sum;
       }
};
using namespace std;
int main(){
    
    return 0;
}