class Solution {
public:
    int m,n;
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
    //DFS
    void dfs(vector<vector<int>>& heights,int i, int j , int prev,vector<vector<bool>> &visited){
            if(i<0 || i>=m || j<0 || j>=n || visited[i][j]){
                return;
            }
            if(heights[i][j]<prev) return;
        //From this cell, move to any neighboring cell that’s not visited yet and has a height >= current height. Keep marking all reachable cells
        //If the cell is valid then we mark it as visited, means water can flow to it from the prev cell
            visited[i][j]=true;
        //Now we need to check it's neighbour for the same conditions
            for(auto & dir: directions){
                dfs(heights,i+dir[0],j+dir[1],heights[i][j],visited);
            }
        }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));

        //Edge case when there is nothiign in the matrix
        if(m== 0 || n ==0) return {};



        //run  DFS on each of the ocean
        //First wee need to fill the dfs with pacific left and top
        for(int i =0;i<m;i++) dfs(heights,i,0,INT_MIN,pacific);
        for(int j=0;j<n;j++) dfs(heights,0,j,INT_MIN,pacific);

        //For Atlanctic we ned to start with the right and bottom
        for(int i=0;i<m;i++) dfs(heights,i,n-1,INT_MIN,atlantic);
        for(int j=0;j<n;j++) dfs(heights,m-1,j,INT_MIN,atlantic);



        //At this point we have marked all the pacific going cells and the atlantic going cells, now we just need the ones that are present in both         
        //Check for cells that are valid in both pacific and atlanctic and then add those values to the res
        for(int row =0;row<m;row++){
            for(int col =0;col<n;col++){
                if(pacific[row][col] && atlantic[row][col]){
                    res.push_back({row,col});
                }
            }
        }
        return res;
    }
};




/*
//Explanation:

We are given a grid of heights, where each cell represents an elevation.
Water can only flow from a cell to its neighboring cell if the neighbor’s height is
LESS THAN OR EQUAL to the current cell’s height.

We need to find all coordinates from which water can flow to BOTH:
    - Pacific Ocean (touches the top and left borders)
    - Atlantic Ocean (touches the bottom and right borders)

----------------------------------------------
Core Idea:

Instead of simulating water flowing from every cell *toward* the ocean,
we reverse the thinking:

Instead of starting from each cell and going downhill,
we reverse the direction:

Start from the oceans and go uphill.
Because if the ocean can climb to a cell,
it means water from that cell can flow down to the ocean.


So we do two reverse floods:
Start from Pacific edges → climb uphill → mark all cells reachable.
Start from Atlantic edges → climb uphill → mark all cells reachable.

At the end:
Cells that are reachable by both floods are the ones from which water can reach both oceans.

----------------------------------------------
Approach Summary:

- Use DFS starting from all Pacific border cells (top row + left column)
- Use DFS starting from all Atlantic border cells (bottom row + right column)
- Track reachable cells in two separate `visited` matrices
- Return all coordinates that are reachable by both

----------------------------------------------
 DFS Logic:

DFS(i, j, prevHeight):
    - Stop if:
        ▪ Out of bounds
        ▪ Already visited
        ▪ Current height < prevHeight (water can’t flow upward)
    - Otherwise, mark current cell as visited
    - Recurse in all four directions
----------------------------------------------
Complexity:

Time: O(m * n)
Each cell is visited at most twice (once for each ocean)
Space: O(m * n) for visited matrices and recursion stack
----------------------------------------------
*/

/*
----------------------------------------------
FULL DRY RUN EXAMPLE
heights = [
  [1, 2, 2, 3, 5],
  [3, 2, 3, 4, 4],
  [2, 4, 5, 3, 1],
  [6, 7, 1, 4, 5],
  [5, 1, 1, 2, 4]
]

m = 5, n = 5

----------------------------------------------
STEP 0: Initialize visited matrices

pacific = [
  [F F F F F]
  [F F F F F]
  [F F F F F]
  [F F F F F]
  [F F F F F]
]

atlantic = [
  [F F F F F]
  [F F F F F]
  [F F F F F]
  [F F F F F]
  [F F F F F]
]

----------------------------------------------
STEP 1: Pacific DFS

- Pacific borders: top row (0,*) + left column (*,0)

# DFS from (0,0) height=1:
- Mark pacific[0][0]=T
- Neighbors with height >= 1: (0,1)=2, (1,0)=3
- DFS to (0,1):
  - Mark pacific[0][1]=T
  - Neighbors >=2: (0,2)=2, (1,1)=2
- DFS to (0,2):
  - Mark pacific[0][2]=T
  - Neighbors >=2: (0,3)=3, (1,2)=3
- Continue recursively...
- After top row DFS, top row pacific = [T T T T T]

----------------------------------------------
# DFS from left column:
- Start (1,0)=3:
  - Already marked? No → mark T
  - Neighbors >=3: (2,0)=2 → too small, skip
  - (1,1)=2 → too small, skip
- Start (2,0)=2:
  - mark T
  - Neighbors >=2: (2,1)=4, (3,0)=6
- Start (3,0)=6:
  - mark T
  - Neighbors >=6: (4,0)=5 → too small, skip
  - (3,1)=7 → mark T
- Start (4,0)=5:
  - mark T
  - Neighbors >=5: (4,1)=1 → too small, skip

 Pacific visited after all DFS:
[
[T T T T T]
[T F T T T]
[T T T F F]
[T T F F F]
[T F F F F]
]

----------------------------------------------
STEP 2: Atlantic DFS

- Atlantic borders: bottom row (4,*) + right column (*,4)

# DFS from bottom row:
- Start (4,0)=5:
  - mark atlantic[4][0]=T
  - Neighbors >=5: (3,0)=6 → mark T
- Start (4,1)=1:
  - mark T
  - Neighbors >=1: (3,1)=7 → mark T
- Start (4,2)=1:
  - mark T
  - Neighbors >=1: (3,2)=1 → mark T
- Start (4,3)=2:
  - mark T
  - Neighbors >=2: (3,3)=4 → mark T
- Start (4,4)=4:
  - mark T
  - Neighbors >=4: (3,4)=5 → mark T
----------------------------------------------
# DFS from right column:
- Start (0,4)=5:
  - mark T
  - Neighbors >=5: (1,4)=4 → too small, skip
- Start (1,4)=4:
  - mark T
  - Neighbors >=4: (1,3)=4 → mark T
- Continue recursively to mark all cells reachable

 Atlantic visited after all DFS:
[
[F F F T T]
[F F T T T]
[F T T F F]
[T T F T T]
[T T T T T]
]

----------------------------------------------
STEP 3: Combine Pacific & Atlantic

Intersect cells where pacific[i][j] && atlantic[i][j] == T

Resulting coordinates:
[
[0,4], [1,3], [1,4], [2,2], [3,0], [3,1], [4,0]
]

Explanation:
- Each of these cells can flow water to both Pacific and Atlantic
- Example: (1,3)=4
  - Can flow left/up to Pacific
  - Can flow right/down to Atlantic
----------------------------------------------
 Step 4: Return result

return [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]

*/
