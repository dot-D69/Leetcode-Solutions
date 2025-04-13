class Solution {
    public:
    
        void bfs(vector<vector<char>>& grid,int i,int j,int rows,int cols){
            vector<vector<int>> directions {{1,0},{-1,0},{0,1},{0,-1}};
    
            queue<pair<int,int>> que;
            que.push({i,j});
            grid[i][j]='v'; // mark the current grid as visited.
    
            while(!que.empty()){
                auto it = que.front();
                que.pop();
                
                // As we access the pairs from the que, so auto it will store them as pairs
                // To access pairs we use .first and .second
                // now in the queue we have the grid from where we start the bfs i.e the i and j
                // And we will also store the other neighbours of the current grid that are 1
                //it.first = i 
                //it.second = j
    
                for(auto a : directions){ //  we add the directions to i1 and j1 to simulate the directions that i,j have :
                //Like if i want i+1, j so we add i,j + 1,0 = i+1 ,j
                //Similarly if we do i,j + -1,0 = i-1,j
                //so that is why we initialize the directions vector in the starting for this 
                    int i1=it.first+a[0];
                    int j1=it.second+ a[1];
    
                    if(i1<0 || i1>=rows || j1<0 || j1>=cols || grid[i1][j1]!='1'){
                        continue; //  we check if we have reached a water , so we move on to the next neighbour and skip this one
                    }
                    else{
                        que.push({i1,j1}); //  if the current grid is not visited or a water we add it to queue
                        grid[i1][j1]='v'; // and mark it as visited
                    }
                }
            }
        }
    
    
        int numIslands(vector<vector<char>>& grid) {
            // Edge case: empty grid or grid has no columns
            if (grid.empty() || grid[0].empty()) {
                return 0;
            }
    
            int count = 0;                      // To store number of islands
            int rows = grid.size();            // Number of rows
            int cols = grid[0].size();         // Number of columns
    
            // Traverse every cell in the grid
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    
                    if (grid[i][j] == '1') {
                        bfs(grid, i, j, rows, cols); // Visit the entire island
                        count++; // Increment island count after exploring a full island
                    }
                }
            }
            return count;
        }
    };
    
    
    // Time Complexity: O(m * n)
    // Space Complexity: O(min(m, n)) — BFS queue can grow up to one entire row or column in the worst case.