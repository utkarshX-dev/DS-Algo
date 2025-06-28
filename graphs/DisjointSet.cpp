#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class disjointSet{
private:
    vector<int>rank, parent;
public:
    //constructor
    disjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    //t.c = O(4alpha) or constant & path compression
    int findUltimateParent(int node){
        if(node == parent[node]){
            return node;
        }
        else{
            return parent[node] = findUltimateParent(parent[node]);
        }
    }
    
    //union by rank
    void unionByrank(int u, int v){
        int ult_u_Parent = findUltimateParent(u);
        int ult_v_Parent = findUltimateParent(v);
        if(ult_u_Parent == ult_v_Parent) return;
        if(rank[ult_u_Parent] < rank[ult_v_Parent]){
            parent[ult_u_Parent] = ult_v_Parent;
        }
        else if(rank[ult_v_Parent] < rank[ult_u_Parent]){
            parent[ult_v_Parent] = ult_u_Parent;
            rank[ult_u_Parent]++;
        }
        else{
            parent[ult_u_Parent] = ult_v_Parent;
            rank[ult_v_Parent]++;
        }
    }




};

int main(){
    disjointSet ds(7);
    ds.unionByrank(1, 2);
    ds.unionByrank(2, 3);
    ds.unionByrank(4, 5);
    ds.unionByrank(6, 7);
    ds.unionByrank(5, 6);
    ds.unionByrank(3, 7);
    
    //check if 3 and 7 belong to same component;
    if(ds.findUltimateParent(3) == ds.findUltimateParent(7)){
        cout << "Belong to same component.\n";
    }
    else{
        cout << "Not part of same component.\n";
    }
    //without this line ds.unionByrank(3, 7); they don't belong to same component comment and check
    return 0;
}