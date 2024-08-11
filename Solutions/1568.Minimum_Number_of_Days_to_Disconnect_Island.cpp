class Solution {
public:
    int m,n;

    void dfs(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>& vis){ //Dfs to traverse through the cell to find put visited cells  
        if(i<0 || i>=m || j<0 || j>=n || vis[i][j] || grid[i][j]==0){ // checks the bound and visited cells and cell that are water
            return;   // if it's out of bound or already visited or is water then simply return no need to traverse
        }
         vis[i][j]=1; // mark visited;

         dfs(grid,i+1,j,vis);
         dfs(grid,i-1,j,vis);
         dfs(grid,i,j+1,vis);
         dfs(grid,i,j-1,vis);
    }

    int numofIslands(vector<vector<int>>& grid){
        int island =0;
        vector<vector<bool>> vis (m,vector<bool>(n)); // make an vis array to mark the cells that have been visited;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] ==1 && !vis[i][j]){ // we only want those cells that are island and are not visited before as we can change island to water to make it disconnected
                    dfs(grid,i,j,vis);
                    island++;
                }
            }
        }
        return island;
    }
    int minDays(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();

        int island =numofIslands(grid);

        if(island > 1 || island == 0){
            return 0;
        }
        else{ // we have only 1 island , so we need to disconnect
        // check if we can disconnect the grid in 1 day
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==1){
                        grid[i][j]=0;
                        island =numofIslands(grid);
                        if(island>1 || island==0){
                            return 1;
                        }
                        grid[i][j] =1;
                    }
                }
            }
        }
        return 2;
    }
};
