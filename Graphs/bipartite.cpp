#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
    // colors a component
private:
    bool check(int start, int V, vector<int> adj[], int color[])
    {
        color[start] = 0;
        queue<int> q;
        q.push(start);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : adj[node])
            {
                // if the adjacent node is yet not colored, we will give the opposite color of the node
                if (color[it] == -1)
                {
                    color[it] = !color[node];
                    q.push(it);
                }
                // if the adjacent node has the same color, someone did color it on some other path
                else if (color[it] == color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        int color[V];
        for (int i = 0; i < V; i++)
            color[i] = -1;

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (check(i, V, adj, color) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    Solution obj;

    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<int> adj[V];

    cout << "Enter " << E << " edges (0-based index):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Since the graph is undirected
    }

    if (obj.isBipartite(V, adj))
        cout << "The graph is Bipartite.\n";
    else
        cout << "The graph is NOT Bipartite.\n";

    return 0;

}