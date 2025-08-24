class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int top = INT_MAX;
        int left =  INT_MAX;
        int bottom = INT_MIN;
        int right = INT_MIN;

        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    top = min(top,i);
                    left = min(left,j);
                    bottom = max(bottom,i);
                    right = max(right,j);
                }
            }
        }

      return (bottom -top +1) * (right - left + 1);
    }
};

/*

The Goal

We want the smallest rectangle that covers all the 1s in the grid, and then return its area.

*** Key Idea:

Any rectangle is defined by 4 boundaries:

top = first row where a 1 appears (smallest row index).

bottom = last row where a 1 appears (largest row index).

left = first column where a 1 appears (smallest col index).

right = last column where a 1 appears (largest col index).

So if we keep track of how far up, down, left, right the 1s extend, we can build the exact rectangle.



*** Why initialize with INT_MAX / INT_MIN? ***

Before scanning, we don’t know where the first 1 is.

To make sure the first 1 always updates the values correctly:

top and left start at INT_MAX → because we want the minimum row/col.

bottom and right start at INT_MIN → because we want the maximum row/col.

This guarantees the first 1 we see will reset them properly.



####  Process (Step-by-step Flow) ####

Read grid size m (rows), n (cols).

Start with extreme values (top=INT_MAX, etc.).

Loop over each cell (i, j).

If cell == 1:

Update top → take smaller row.

Update bottom → take larger row.

Update left → take smaller column.

Update right → take larger column.

After loop, we have the smallest rectangle containing all 1s.

Compute:

height = bottom - top + 1

width = right - left + 1

area = height × width

Return area.




Dry Run (Code Flow)
Example Grid
0 1 0
1 0 1


Initialization:

top = INT_MAX, bottom = INT_MIN
left = INT_MAX, right = INT_MIN


Scan row 0, col 0:

grid[0][0] = 0 → nothing happens.

Scan row 0, col 1:

grid[0][1] = 1

Update bounds:

top = min(INT_MAX, 0) = 0

bottom = max(INT_MIN, 0) = 0

left = min(INT_MAX, 1) = 1

right = max(INT_MIN, 1) = 1

Now: top=0, bottom=0, left=1, right=1


Scan row 0, col 2:

grid[0][2] = 0 → nothing happens.

Scan row 1, col 0:

grid[1][0] = 1

Update bounds:

top = min(0, 1) = 0

bottom = max(0, 1) = 1

left = min(1, 0) = 0

right = max(1, 0) = 1

Now: top=0, bottom=1, left=0, right=1


Scan row 1, col 1:

grid[1][1] = 0 → nothing happens.

Scan row 1, col 2:

grid[1][2] = 1

Update bounds:

top = min(0, 1) = 0

bottom = max(1, 1) = 1

left = min(0, 2) = 0

right = max(1, 2) = 2

Now: top=0, bottom=1, left=0, right=2


After full scan:

top = 0, bottom = 1, left = 0, right = 2


Compute:

height = 1 - 0 + 1 = 2

width = 2 - 0 + 1 = 3

area = 2 × 3 = 6

Return 6.

Quick Memory Hook

Think of top/left as walls moving inward (so we start with INT_MAX).
Think of bottom/right as walls moving outward (so we start with INT_MIN).
Each 1 pushes the rectangle edges until they snugly fit around all 1s.


*/