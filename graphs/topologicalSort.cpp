#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj;

public:
    Graph(int v)
    {
        this->V = v;
        adj.resize(v);
    }

    void addEdge(int s, int d)
    {
        adj[s].push_back(d);
        // adj[d].push_back(s); // Undirected edge
    }

    void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "Vertex " << i << ": ";
            for (int neighbor : adj[i])
            {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    void bfs(int start, vector<bool> &visited)
    {
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            for (int neighbor : adj[curr])
            {
                if (!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    void bfsDisconnected()
    {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                bfs(i, visited);
                cout << endl
                     << endl;
            }
        }
    }

    void dodfs(int start, vector<bool> &visited, vector<vector<int>> &adj)
    {
        if (visited[start])
        {
            return;
        }

        cout << start << " ";
        visited[start] = true;
        for (int x : adj[start])
        {
            dodfs(x, visited, adj);
        }
    }
    void dfs(int start)
    {
        vector<bool> visited(V, false);
        dodfs(start, visited, adj);
    }

    void topologicalSort(int curr, stack<int> &st, vector<bool> &visited)
    {
        visited[curr] = true;
        for (auto nbs : adj[curr])
        {
            if (!visited[nbs])
            {
                topologicalSort(nbs, st, visited);
            }
        }

        st.push(curr);
    }

    void topoUtility()
    {
        stack<int> st;
        vector<bool> visited(V, false);
        
        for (int i = 0; i < V; i++){
            topologicalSort(i, st, visited);
        }

        cout << "Topological Order : ";
        while (!st.empty()){
            cout << st.top() << " ";
            st.pop();
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(5, 0);
    g.addEdge(5, 2);

    g.topoUtility();
    return 0;
}
