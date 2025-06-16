#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    private:
      bool dfs(int node, vector<int> adj[], int parent, vector<int>& vis){
          vis[node] = 1;
          for(auto adjacentNode : adj[node]){
            if(!vis[adjacentNode]){
                if(dfs(adjacentNode, adj, node, vis) == true){
                    return true;
                }
            } else if(adjacentNode != parent) return true;
            
          }
          return false;          
      }
    public:
     bool isCycle(int V, vector<int> adj[]){
        vector<int> vis(V,0);

        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, adj, -1, vis)) return true;
            }
        }
        return false;
     }
};

int main(){
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
    bool result = obj.isCycle(V, adj);

    cout << (result ? "Cycle detected" : "No cycle") << endl;
    

    return 0;
}