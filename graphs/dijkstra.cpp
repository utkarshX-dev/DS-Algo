#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
using namespace std;

class Graph
{
    int V;
    vector<vector<pair<int, int>>> adj; // Changed to store (neighbor, weight)

public:
    Graph(int v)
    {
        this->V = v;
        adj.resize(v);
    }

    void addEdge(int s, int d, int w)
    {
        adj[s].push_back({d, w}); 
        adj[d].push_back({s, w}); 
    }

    void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "Vertex " << i << ": ";
            for (auto neighbor : adj[i])
            {
                cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }

   
    void dijkstra()
    {
        int src = 0;
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int src_to_srcDistance = 0;
        pq.push({src_to_srcDistance, src});
        dist[src] = 0;

        while (!pq.empty())
        {
            int currDistance = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (currDistance > dist[u]) continue;
            
            for (auto nbs : adj[u])
            {
                int nbr = nbs.first;
                int weight = nbs.second;
                if (dist[nbr] > currDistance + weight)
                {
                    dist[nbr] = currDistance + weight;
                    pq.push({dist[nbr], nbr});
                }
            }
        }
        cout << "Shortest distances from source 0:\n";
        for (int i = 0; i < V; i++)
        {
            if (dist[i] == INT_MAX)
                cout << "To vertex " << i << " = INF" << endl;
            else
                cout << "To vertex " << i << " = " << dist[i] << endl;
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1, 2); // Edge from 0 to 1 with weight 2
    g.addEdge(0, 2, 4); // Edge from 0 to 2 with weight 4
    g.addEdge(1, 2, 1); // Edge from 1 to 2 with weight 1
    g.addEdge(1, 3, 7); // Edge from 1 to 3 with weight 7
    g.addEdge(2, 4, 3); // Edge from 2 to 4 with weight 3
    g.addEdge(4, 3, 2); // Edge from 4 to 3 with weight 2
    g.addEdge(4, 5, 5); // Edge from 4 to 5 with weight 5
    g.addEdge(3, 5, 1); // Edge from 3 to 5 with weight 1

    cout << "\n\nCalling Dijkstra (though not implemented):\n";
    g.dijkstra();

    return 0;
}
