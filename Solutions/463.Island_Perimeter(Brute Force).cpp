class Solution {
    public:
        int islandPerimeter(vector<vector<int>>& grid) {
            int rows = grid.size();
            int cols = grid[0].size();
            int peri =0;
    
            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
    
                    if(grid[i][j]==0){
                        continue;
                    }
    
                    //If the current grid is not 0 i.e water
                    // We check all the neighbours of the current grid i.e. i+1,i-1,j+1,j-1
                    //if the grid neighbours is out of bound or is a water then we increase the perimeter
                    
                    if(i+1>=rows || grid[i+1][j]==0){
                        peri++;
                    }
                    if(j+1>=cols || grid[i][j+1]==0){
                        peri++;
                    }
                    if(i-1<0 || grid[i-1][j]==0){
                        peri++;
                    }
                    if(j-1<0 || grid[i][j-1]==0){
                        peri++;
                    }
                }
            }
            return peri;
        }
    };