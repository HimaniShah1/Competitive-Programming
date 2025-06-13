#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
    private:
      bool detect(int src, vector<int> adj[], vector<int> & vis){
        vis[src] = 1;
        queue<pair<int,int>> q;
        q.push({src,-1});

        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto adjacentNode : adj[node]){
                if(!vis[adjacentNode]){
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                } else if(adjacentNode != parent){
                    return true;
                }
            }
        }
        return false;
      }

      public: 
        bool isCycle(int V, vector<int> adj[]){
            vector<int> vis(V, 0);
            //if components, then need to check for all components but if no cycle in one component then why to check other nodes.
            for(int i=0; i<V; i++){
                if(!vis[i]){
                    if(detect(i, adj, vis)) return true;
                }
            }
            return false;
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
    bool result = obj.isCycle(V, adj);

    cout << (result ? "Cycle detected" : "No cycle") << endl;
    

    return 0;
}