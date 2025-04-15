class Solution {
    public:
    
        void dfs(vector<vector<int>>& grid,int i,int j,int rows,int cols,int& peri){// we pass peri by refrence so that it get incremented in every call , if we just pass by then after every recursive call thw value of peri is reset
    
            if(i<0 || i>=rows || j<0 || j>=cols || grid[i][j]==0){ // if we hit water or any boundaries it means we have found our perimeter so we just increase it
                peri++;
                return;
            }
    
            if(grid[i][j]==-1){ // check if the node is visited
                return;
            }
    
            grid[i][j]=-1; // mark as visited
    
            //We make recursive calls to check  out all the neighbours of the current cell
            dfs(grid,i+1,j,rows,cols,peri);
            dfs(grid,i-1,j,rows,cols,peri);
            dfs(grid,i,j+1,rows,cols,peri);
            dfs(grid,i,j-1,rows,cols,peri);
    
    
    
        }
    
        int islandPerimeter(vector<vector<int>>& grid) {
            int rows = grid.size();
            int cols = grid[0].size();
            int peri =0;
    
            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    if(grid[i][j]==1){
                        dfs(grid, i,j,rows,cols,peri);
                        return peri;
                    }
                }
            }
            return -1;
        }
    };