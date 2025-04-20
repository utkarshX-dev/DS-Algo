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

    // Undirected edge: both directions
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

    void bfs(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
    bool dfsCycle(int parent, int node, vector<bool>& visited) {
        visited[node] = true;
        for (int nbs : adj[node]) {
            if (nbs != parent && visited[nbs]) {
                return true;
            }
            else if (nbs != parent && !visited[nbs]) {
                if (dfsCycle(node, nbs, visited)) {
                    return true;  
                }
            }
        }
        return false;
    }
    
    bool hasCycle(){
        vector<bool>Visited(V, false);
        for (int i = 0; i < V; i++){        
            if (dfsCycle(-1, i, Visited))
            {
                return true;
            }
            
        }
        return false;
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

    cout << "BFS starting from node 0: ";
    g.bfs(0);

    if (g.hasCycle()) {
        cout << "Graph contains a cycle!" << endl;
    } else {
        cout << "No cycle found in the graph." << endl;
    }

    return 0;
}
