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
        // adj[d].push_back({s, w});
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

    void bellmanFord()
{
    int src = 0;
    vector<int> distance(V, INT_MAX);
    distance[src] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        bool updated = false;
        for (int u = 0; u < V; u++)
        {
            for (auto edge : adj[u])
            {
                int v = edge.first;
                int weight = edge.second;
                if (distance[u] != INT_MAX && distance[v] > distance[u] + weight)
                {
                    distance[v] = distance[u] + weight;
                    updated = true;
                }
            }
        }
        if (!updated) break;
    }

    
    for (int u = 0; u < V; u++)
    {
        for (auto edge : adj[u])
        {
            int v = edge.first;
            int weight = edge.second;
            if (distance[u] != INT_MAX && distance[v] > distance[u] + weight)
            {
                cout << "Graph contains a negative weight cycle.\n";
                return;
            }
        }
    }

    cout << "Shortest distances from source 0 using Bellman-Ford:\n";
    for (int i = 0; i < V; i++)
    {
        if (distance[i] == INT_MAX)
            cout << "To vertex " << i << " = INF\n";
        else
            cout << "To vertex " << i << " = " << distance[i] << endl;
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

            if (currDistance > dist[u])
                continue;

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

    Graph g(3);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 3);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 0, -2);
    g.bellmanFord();

    return 0;
}
