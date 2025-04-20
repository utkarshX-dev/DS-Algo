#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public: 
    Graph(int v) {
        this->V = v;
        adj.resize(v);
    }

    // Undirected edge: add both ways
    void addEdge(int s, int d) {
        adj[s].push_back(d);
        adj[d].push_back(s);
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": ";
            for (int neighbor : adj[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    void bfs(int start){
        vector<bool>visited(V, false);
        queue<int>q;
        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            cout << curr << " ";
            for (int x : adj[curr])
            {
                if (!visited[x])
                {
                    q.push(x);
                    visited[x] = true;
                }
                
            }
        }
        
    }
};

int main() {
    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    g.printGraph();
    cout << "bfs : " << endl;
    g.bfs(0);      

    return 0;
}
