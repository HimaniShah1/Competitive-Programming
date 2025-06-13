#include <iostream>
#include <vector>
using namespace std;

class Solution {
    private:
      void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &ans){
          vis[node] = 1;
          ans.push_back(node);

          for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj, ans);
            }
          }

       }
    public: 
      vector<int> dfsOfGraph(int V, vector<int> adj[]){
        vector<int> vis(V,0);
        vector<int> ans;

        int start = 0;
        dfs(start, vis, adj, ans);
        return ans;
      }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges for dfs: ";
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
    vector<int> result = obj.dfsOfGraph(V, adj);

    cout << "DFS Traversal: ";
    for (auto node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}