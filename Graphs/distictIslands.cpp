#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
    private:
        void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, vector<pair<int,int>>& vec,
        int row0, int col0){ //row0 = base coordinate row for that island, similarly for col0
            vis[row][col] = 1;
            vec.push_back({row-row0, col-col0});
            int n = grid.size();
            int m = grid[0].size();

            int delrow[] = {-1, 0, 1, 0}; //delta change in the row, to find the neighbours 
            int delcol[] = {0, 1, 0, -1};

            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    dfs(nrow,ncol, vis, grid, vec, row0, col0);
                }
            }

        }
    public:
        int countDistinctIslands (vector<vector<int>>& grid){
            int n = grid.size();
            int m = grid[0].size();
            vector<vector<int>> vis(n, vector<int>(m,0));
            set<vector < pair< int,int>>> st; //to store the unique value of the island only

            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(!vis[i][j] && grid[i][j] == 1){
                        vector<pair<int,int>> vec; //to store the value which will be pushed in the set like {(0,0), (0,1), (1,0)} coordinated of an island
                        dfs(i, j, vis, grid, vec, i, j);
                        st.insert(vec);
                    }
                }
            }
            return st.size();
        }
};

int main(){
    vector<vector<int>> grid;
    cout<<"Enter n & m"<<endl;
    int n, m;
    cin>>n>>m;

    grid.resize(n, vector<int>(m));
    cout << "Enter the grid elements (0 or 1):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    int result = obj.countDistinctIslands(grid);
    cout<<"Number of distinct islands: "<< result << endl;

    return 0;
}