#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    public: 
    vector<int> bfsOfGraph(int V, vector<int> adj[]){
        vector<int> vis(V, 0);
        queue<int> q;
        vector<int> bfs;

         vis[0] = 1;
         q.push(0);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<int> adj[V];

    cout << "Enter " << E << " edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Comment this line if the graph is directed
    }

    Solution obj;
    vector<int> result = obj.bfsOfGraph(V, adj);

    cout << "BFS Traversal: ";
    for (auto node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}