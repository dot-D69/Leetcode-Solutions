class Solution {
    public:
    
        int bfs(vector<vector<int>>& grid,int i,int j,int row,int col,int& peri){
    
            vector<vector<int>> Directions{{1,0},{-1,0},{0,1},{0,-1}};
    
            queue <pair<int,int>> que;
    
            que.push({i,j});
            grid[i][j]=-1;
    
            while(!que.empty()){
                auto it =que.front();
                que.pop();
    
                
    
                for(auto &a: Directions){
                    int i1=it.first+a[0];
                    int j1=it.second+a[1];
                
                    if(i1<0 || i1>=row || j1<0 || j1>=col || grid[i1][j1]==0){ // if we hit water or any boundaries it means we have found our perimeter so we just increase it
                        peri++;
                    }
                    else if(grid[i1][j1]==-1){ // check if the node is visited
                        continue;
                    }
                    else {
                        que.push({i1,j1});
                        grid[i1][j1] =-1;
                    }
                }
            }
            return peri;
        }
    
        int islandPerimeter(vector<vector<int>>& grid) {
            int row = grid.size();
            int col = grid[0].size();
            int peri =0;
    
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    if(grid[i][j]==1){
                       return bfs(grid, i,j,row,col,peri); 
                    }
                }
            }
            return -1;
        }
    };