//graph must be directed
//if graph is undirected convert it into directed 4---5 to 4-->5  4<--5
//for negative edges graphs
//dijkastra's stuck in loop for negative weights
//for detecting negative cycles
// do relax edges v - 1 times we can do more then v - 1 times but those extra iterations are of no use.
// detecting negative cycle = if still updations in distance after v - 1 times definitely exists a negative cycle(sum of all wt < 0)

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int>distance(V, 1e8);
        distance[src] = 0;
        for(int i = 1; i <= V; i++){
            int updations = 0;
            for(auto& edge : edges){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                if(distance[u] != 1e8 && distance[u] + wt < distance[v]){
                distance[v] = distance[u] + wt;
                updations++;
                //update only if get u is reachable and got a better answer for v
                }
                if(i == V && updations >= 1) return {-1};
            }
        }
        return distance;
    }
};

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> bellmanFord(vector<vector<int>>& edges, int V, int src){
    vector<int>distance(V, INT_MAX);
    distance[src] = 0;
    for(int i = 1; i <= V - 1; i++){
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if(distance[u] != INT_MAX && distance[u] + wt < distance[v]){
                distance[v] = distance[u] + wt;
                //update only if get u is reachable and got a better answer for v
            }
        }
    }
    return distance;
}

bool detectNegativeCycle(vector<vector<int>>edges, int V, int src){
    vector<int>distance(V, INT_MAX);
    distance[src] = 0;
    for(int i = 1; i <= V; i++){
        int updations = 0;
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if(distance[u] != INT_MAX && distance[u] + wt < distance[v]){
                distance[v] = distance[u] + wt;
                updations++;
            }
            if(i == V && updations >= 1) return true; //negative cycle present
        }
    }
    return false;
}
int main(){
    return 0;
}