class Solution {
public:
    // Depth First Search to explore the entire island starting from (i, j)
    void dfs(vector<vector<char>>& grid, int i, int j, int rows, int cols) {
        // Base case: if the current cell is out of bounds OR is water ('0') OR already visited ('v'), return
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != '1') {
            return;
        }
/*We don’t need to check separately for 'v' (visited) because we already skip any cell where grid[i][j] != '1'.

And since we immediately mark a cell as 'v' (visited) as soon as we visit it, any further DFS call that tries to revisit that cell will see that grid[i][j] != '1' and return immediately.*/

        // Mark the cell as visited so we don't revisit it
        grid[i][j] = 'v';

        // Recursively visit all 4 adjacent cells (up, down, left, right)
        dfs(grid, i + 1, j, rows, cols); // down
        dfs(grid, i - 1, j, rows, cols); // up
        dfs(grid, i, j + 1, rows, cols); // right
        dfs(grid, i, j - 1, rows, cols); // left
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
                // Start a DFS whenever you find a land cell ('1')
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, rows, cols); // Visit the entire island
                    count++; // Increment island count after exploring a full island
                }
            }
        }
        return count;
    }
};


// Time Complexity: O(m * n)
// Space Complexity: O(m * n) in worst case