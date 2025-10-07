class Solution {
public:
    int n;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool visited[50][50]; // ✅ Fixed-size array (faster)
    
    bool isPossibleToReach(vector<vector<int>>& grid,int i,int j,int mid){
        if(i<0 || i>=n || j<0 ||j>=n || visited[i][j] || mid<grid[i][j] ) return false;
        visited[i][j] = true;
        if(i == n-1 && j== n-1 ) return true;

        for(auto &d : directions){
            int i_ = i+d[0];
            int j_ = j+d[1];
            if(isPossibleToReach(grid,i_,j_,mid)){
                return true;
            }
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int l = grid[0][0];
        int r = n*n-1;
        int res=0;

        while(l<=r){
            int mid= l+(r-l)/2;
            memset(visited, 0, sizeof(visited)); //

            if(isPossibleToReach(grid,0,0,mid)){
                res=mid;
                r=mid-1;
            } else {
                l=mid+1;
            }
        }
        return res;
    }
};


/*
EXPLANATION:

1. VARIABLES AND STRUCTURE:

- int n:
    Stores the grid size for convenience.

- vector<vector<int>> directions:
    A list of the 4 possible moves from any cell: down, up, right, left.
    Used in DFS traversal.

- bool visited[50][50]:
    Fixed-size boolean array to track which cells have been visited
    during DFS. Using a static array and resetting with memset is
    much faster than creating a new vector each iteration.

---------------------------------------------------------------
2. FUNCTION: isPossibleToReach(grid, i, j, mid)

Purpose:
    Determines if it is possible to reach the bottom-right cell
    from cell (i,j) assuming the water level is 'mid'.

Logic:
    a) Base conditions:
        - If (i,j) is out of bounds → return false
        - If (i,j) already visited → return false (avoids cycles)
        - If grid[i][j] > mid → water hasn't risen enough → return false

    b) Mark current cell as visited:
        visited[i][j] = true

    c) If current cell is the destination (n-1,n-1) → return true

    d) Recursively explore all 4 neighboring cells:
        - If any recursive call returns true → current path works → return true

    e) If no neighbors lead to destination → return false

---------------------------------------------------------------
3. FUNCTION: swimInWater(grid)

Purpose:
    Uses binary search to find the minimum water level (time) that allows
    reaching the destination.

Logic:
    a) Initialize binary search bounds:
        - l = grid[0][0]: the water must at least reach the starting cell
        - r = n*n-1: maximum possible value in the grid (as per constraints)

    b) Initialize result variable: res = 0

    c) Binary search loop: while(l <= r)
        i) Compute mid = l + (r-l)/2
        ii) Reset visited array for this iteration using:
            memset(visited, 0, sizeof(visited));
            - Efficiently sets all visited[i][j] = false
            - Avoids heap allocation and slow vector<bool> operations
        iii) Call DFS: isPossibleToReach(grid, 0, 0, mid)
            - If true → destination reachable at water level 'mid'
                → update res = mid
                → try to find smaller water level → r = mid-1
            - Else → water level too low → l = mid+1

    d) After binary search ends, return res:
        - Minimum time/water level that allows reaching destination

---------------------------------------------------------------
4. WHY IT WORKS:

- Binary search reduces the number of water levels we need to check from
  0..n*n-1 to log(n*n) iterations.
- DFS efficiently explores all reachable cells for each candidate water level.
- visited array ensures no cell is visited twice in a single DFS call.
- memset ensures resetting visited array is fast and does not incur
  extra memory allocation overhead.
- The combination guarantees O(n^2 * log(n^2)) complexity,
  which is acceptable for n <= 50.

*/

/*
DRY RUN

grid = [
 [0, 2, 1],
 [1, 3, 2],
 [4, 5, 3]
]

l = grid[0][0] = 0
r = n*n-1 = 8
mid = l + (r-l)/2 = 0 + (8-0)/2 = 4

Binary Search Iteration 1: mid = 4
visited reset:
[ F F F ]
[ F F F ]
[ F F F ]

DFS path:

(0,0) → grid[0][0]=0 ≤4 → visited[0][0]=T
  ↓
(1,0) → grid[1][0]=1 ≤4 → visited[1][0]=T
  ↓
(2,0) → grid[2][0]=4 ≤4 → visited[2][0]=T (dead end, no valid neighbor)
Backtrack to (1,0):
  → Right (1,1)=3 ≤4 → visited[1][1]=T
      → Down (2,1)=5 >4 → cannot step
      → Right (1,2)=2 ≤4 → visited[1][2]=T
          → Down (2,2)=3 ≤4 → destination reached ✅

Result: DFS returns true → res=4, r=3

visited state after success:
[ T T T ]
[ T T T ]
[ T F T ]

-----------------------------------------------
Binary Search Iteration 2: mid = 3
visited reset:
[ F F F ]
[ F F F ]
[ F F F ]

DFS path:

(0,0) → 0 ≤3 → T
  ↓
(1,0) → 1 ≤3 → T
  ↓
(2,0) → 4 >3 → cannot step
Backtrack (1,0):
  → Right (1,1)=3 ≤3 → T
      → Down (2,1)=5>3 → cannot step
      → Right (1,2)=2 ≤3 → T
          → Down (2,2)=3 ≤3 → destination ✅

Result: DFS returns true → res=3, r=2

visited state after success:
[ T T T ]
[ T T T ]
[ F F T ]

-----------------------------------------------
Binary Search Iteration 3: mid = 2
visited reset:
[ F F F ]
[ F F F ]
[ F F F ]

DFS path:

(0,0) → 0 ≤2 → T
  ↓
(1,0) → 1 ≤2 → T
  ↓
(2,0) → 4>2 → cannot step
Backtrack (1,0):
  → Right (1,1)=3>2 → cannot step
Backtrack (0,0):
  → Right (0,1)=2 ≤2 → T
      → Right (0,2)=1 ≤2 → T
          → Down (1,2)=2 ≤2 → T
              → Down (2,2)=3>2 → cannot step

DFS returns false → destination not reachable → l = mid+1 = 3

-----------------------------------------------
Binary Search Ends:
l=3, r=2 → exit
Minimum time to reach bottom-right = 3 ✅




*/