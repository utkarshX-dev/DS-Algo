#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int v;
    vector<vector<pair<int,int>>> adj;  

public:
   
    Graph(int v) {
        this->v = v;
        adj.resize(v);  
    }


    void addEdge(int s, int d, int w) {
        adj[s].push_back({d, w});
    }

    void printGraph() {
        for (int i = 0; i < v; i++) {
            cout << "Vertex " << i << " : " << endl;
            for (auto d : adj[i]) {
                cout << d.first << " ";  
                cout << d.second << " ";  
                cout << endl;
            }
        }
    }
};

int main() {
    Graph g(4);  

    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 10);
    g.addEdge(1, 3, 0);
    g.addEdge(2, 0, 2);
    g.addEdge(2, 1, 10);
    g.addEdge(2, 3, -1);
    g.addEdge(3, 1, 0);
    g.addEdge(3, 2, -1);

    g.printGraph();  
    return 0;
}
