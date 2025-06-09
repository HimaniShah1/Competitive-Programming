//Storing graph using adjacency matrix
/** 
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cout << "Enter number of nodes and edges: ";
    cin>>n>>m;
    //Graph stored
    vector<vector<int> > adj(n + 1, vector<int>(n + 1, 0)); //initialize with 0

    cout << "Enter edges (u v):" << endl;

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1; //mark the nodes between edges as 1, both ways
        adj[v][u] = 1; // Comment this line if the graph is directed
    }

    // Print adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
*/

//Storing graph using list
/** 
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cout << "Enter number of nodes and edges: ";
    cin>>n>>m;
    //Graph stored
    vector<int> adj[n+1]; //initialize with 0

    cout << "Enter edges (u v):" << endl;

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
         adj[u].push_back(v);//push back neighbours
         adj[v].push_back(u);//cmment this if it is directed meaning there is only edge between u and v
    }

     // Print adjacency list
    cout << "\nAdjacency List:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
    
    return 0;
}
*/

//Weighted graph
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    // Adjacency list: adj[node] = vector of (neighbor, weight)
    vector<vector<pair<int, int> > > adj(n + 1);

    cout << "Enter edges (u v w):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w); // Comment this line if the graph is directed
    }

    // Print adjacency list
    cout << "\nWeighted Adjacency List:\n";
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (auto &edge : adj[i]) {
            cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        cout << endl;
    }

    return 0;
}

