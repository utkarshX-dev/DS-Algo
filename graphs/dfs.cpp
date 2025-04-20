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

    void addEdge(int s, int d) {
        adj[s].push_back(d);
        adj[d].push_back(s);  // Undirected edge
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

    void bfs(int start, vector<bool>& visited) {
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            for (int neighbor : adj[curr]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    void bfsDisconnected() {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                bfs(i, visited);
                cout << endl << endl;
            }
        }
    }

    void dodfs(int start, vector<bool> & visited, vector<vector<int>>& adj){
        if (visited[start])
        {
            return;
        }
        
        cout << start << " ";
        visited[start] = true;
        for(int x : adj[start]){
            dodfs(x, visited, adj);
        }
        
        
    }
    void dfs(int start){
        vector<bool>visited(V, false);
        dodfs(start, visited, adj);
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
    // g.printGraph();
    // g.bfsDisconnected();
    g.dfs(0);




    //  // Component 1
    //  g.addEdge(0, 1);
    //  g.addEdge(1, 2);
    //  // Component 2
    //  g.addEdge(3, 4);
    //  // Component 3
    //  g.addEdge(5, 6);
 


    return 0;
}
