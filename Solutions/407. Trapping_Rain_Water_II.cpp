class Solution {
public:
    typedef pair<int, pair<int,int>> P;

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
        priority_queue<P,vector<P>,greater<> > pq;
        vector<vector<bool>> visited(m,vector<bool>(n,false)); 

        // First add the boundary cells to the heap
        //Left and right most column
        for(int row = 0;row<m;row++){
            for(int col :{0,n-1}){
                pq.push({heightMap[row][col],{row,col}});
                visited[row][col] = true;
            }
        }

        //Top and bottom most row
        for(int col = 0;col<n;col++){
            for(int row :{0,m-1}){
                pq.push({heightMap[row][col],{row,col}});
                visited[row][col] = true;
            }
        }
         //At this point our heap is filled  with all the boundary cells and they are marked as visited, now we need to pop each of them starting form the minimum and check it's neighbour for a valid pit to store water

        int water =0;
        while(!pq.empty()){
            P cell = pq.top();
            pq.pop();

            int height = cell.first;
            int x = cell.second.first;
            int y = cell.second.second;

            //Find the neighbours of the current cell
            for(vector<int> &d : directions){
                int x1 = x+d[0];
                int y1 = y+d[1];

                if(x1>=0 && x1<m && y1>=0 && y1<n && !visited[x1][y1]){
                    water+= max((height - heightMap[x1][y1]) , 0);
                    pq.push({max(height,heightMap[x1][y1]),{x1,y1}});
                    visited[x1][y1]=true;
                }
            }

        }
        return water;
    }
};


/*
Time Complexity : O(mn * log(mn))
Space Complexity: O(m*n)


Explanation:

Why min-heap here?
We want to process cells starting from the lowest boundary height outward.
This ensures water can only be trapped if surrounded by taller boundaries.
Min-heap helps us always pick the smallest boundary to expand from.


typedef pair<int, pair<int,int>> P;
Creates an alias P for pair<int, pair<int,int>>. So P represents a tuple (height, (row, col)). Using a typedef/alias makes types shorter and clearer where used later



directions lists the 4-neighbor offsets: down, right, up, left. Used to iterate all neighbors of a cell.

##############################################################################################################
What does priority_queue<T, Container, Compare> mean?

The general template is:

template <
  class T,                       // type of elements
  class Container = vector<T>,   // how elements are stored
  class Compare = less<T>        // how to compare elements
> class priority_queue;


So in your case:

T = P → elements are pair<int, pair<int,int>>.

Container = vector<P> → internally, it stores all P in a std::vector.

Compare = greater<P> → ordering is done with std::greater, which makes this a min-heap.

3. How does greater<P> work?

std::pair already defines lexicographic comparison:

First compare .first

If equal, compare .second.first

If still equal, compare .second.second

So in our heap:

The smallest height (.first) always comes out first.

If two cells have the same height, it breaks ties by row and then column.

That’s why when we push:

pq.push({heightMap[row][col], {row,col}});


it knows exactly how to compare things:
→ It looks at the heightMap[row][col] first, then coordinates.

4. Visualization of what’s inside pq

Imagine pushing 3 elements:

pq.push({5,{0,1}});
pq.push({2,{2,3}});
pq.push({4,{1,1}});


Internally, the vector will contain something like:

[(2,(2,3)), (5,(0,1)), (4,(1,1))]


But the heap property ensures the smallest P (by height) is always at the top.

So pq.top() → (2,(2,3))
###################################################################################################################################

visited prevents revisiting cells. Once a cell is pushed into the heap, mark it visited so it is processed once. This avoids loops and double-counting.
Keeps track of which cells we’ve already processed.
Avoids infinite loops and duplicate processing.


water accumulates total trapped water.

 while(!pq.empty()) Loop: pop the boundary cell with the smallest effective height.

height is the effective boundary height (see later why it may be larger than heightMap[x][y]).

(x,y) are its coordinates.


For each neighbor (x1,y1) inside bounds and not visited:

heightMap[x1][y1] is the neighbor's original height.
If height (current boundary) > neighborHeight, then neighbor traps height - neighborHeight water. So we add max(height - heightMap[x1][y1], 0).


Then we push the neighbor into the heap with effective height max(height, neighborHeight).

Why max? If the neighbor was lower, after filling with water to height, its effective boundary height becomes height (water + bar). If the neighbor is taller, its own height becomes part of the new boundary. 
So max(height, neighborHeight) is the new boundary level to use for further expansion.
This will always update the height of the neighbour to the max it can hold upto (like if if height = 10 and neighbour height =7 so the neighbour could hold water  = 3 and thus it's height will effectivel become (7+3) 10)

Mark neighbor visited immediately (so it won't be added multiple times).

After the loop finishes, every cell has been processed and water holds the total trapped volume.


*/


/*


Dry run A — Simple 3×3

5 5 5
5 1 5
5 5 5

Initialization

Push all boundary cells into the min-heap (priority queue).
Mark them visited.
Heap contents (min→max):

pq = [(5,(0,0)), (5,(0,1)), (5,(0,2)),
      (5,(1,0)), (5,(1,2)),
      (5,(2,0)), (5,(2,1)), (5,(2,2))]

Visited grid (V = visited, . = unvisited):

V V V
V . V
V V V

Step 1: Pop the lowest boundary
Pop (5,(0,0)).
Neighbors are already visited → nothing happens.

Heap now:
pq = [all other 5s]

Step 2: Continue popping
Pop (5,(1,0)).
Check neighbor (1,1) → unvisited and has height 1.

Trapped water = max(5 - 1, 0) = 4.

Add 4 to total.

Push (5,(1,1)) into heap.

Mark (1,1) visited.

Now:
water = 4


Heap:
pq = [other 5s..., (5,(1,1))]


Visited grid:

V V V
V V V
V V V

Step 3: Process (1,1)
When (5,(1,1)) is popped, all its neighbors are already visited, so nothing happens.

Final Result
Total water trapped = 4

*/



/*

DRY RUN 

heightMap =
[
  [1, 4, 3, 1, 3, 2],
  [3, 2, 1, 3, 2, 4],
  [2, 3, 3, 2, 3, 1]
]
 m = 3 (rows), n = 6 (columns)

Step 1: Initialize
Directions = [(1,0), (0,1), (-1,0), (0,-1)] (Down, Right, Up, Left)
Priority Queue (min-heap) = pq
Visited = 3x6 all false initially
Water = 0

Step 2: Add all boundary cells
We push all border cells with their heights into pq.
P = pair<height, pair<x,y>>

Boundary push sequence:

Left & right columns:
Row 0 → (0,0)=1, (0,5)=2
Row 1 → (1,0)=3, (1,5)=4
Row 2 → (2,0)=2, (2,5)=1

Top & bottom rows:
Col 0 → (0,0)=1, (2,0)=2 (already in)
Col 1 → (0,1)=4, (2,1)=3
Col 2 → (0,2)=3, (2,2)=3
Col 3 → (0,3)=1, (2,3)=2
Col 4 → (0,4)=3, (2,4)=3
Col 5 → (0,5)=2, (2,5)=1 (already in)

Priority Queue (min-heap) after initialization:
(sorted by height)


pq = [
  (1,(0,0)), (1,(0,3)), (1,(2,5)),
  (2,(0,5)), (2,(2,0)), (2,(2,3)),
  (3,(0,2)), (3,(2,2)), (3,(2,4)), (3,(1,0)),
  (3,(2,1)), (4,(0,1)), (4,(1,5))
]

Visited marked for all boundary cells.



Step 3: Process PQ step by step

Iteration 1:
Pop (1,(0,0)) → min height cell.
Neighbors:
(1,0)=3 already visited
(0,1)=4 already visited
(x=-1 invalid)
(y=-1 invalid)

No trapped water. 


Iteration 2:
Pop (1,(0,3)).
Neighbors:
(1,3)=3 not visited → trapped water = max(1-3,0)=0
Push (3,(1,3)), visited[1][3]=true
Others are boundary/visited.


Iteration 3:
Pop (1,(2,5)).
Neighbors:
(1,5)=4 visited
(2,4)=3 visited
(x=3 invalid)
(y=6 invalid)

No water.


Iteration 4:
Pop (2,(0,5)).
Neighbors:
(1,5)=4 visited
(0,4)=3 visited
(x=-1 invalid)
(y=6 invalid)

No water.


Iteration 5:
Pop (2,(2,0)).
Neighbors:
(1,0)=3 visited
(2,1)=3 visited
(3,0 invalid)
(2,-1 invalid)

No water.


Iteration 6:
Pop (2,(2,3)).
Neighbors:
(1,3)=3 visited
(2,4)=3 visited
(3,3 invalid)
(2,2)=3 visited

No water.


Iteration 7:
Pop (3,(0,2)).
Neighbors:
(1,2)=1 not visited → trapped = max(3-1,0)=2 ✅
Push (3,(1,2)) (height raised to 3 because water fills)
Water=2
(0,3)=1 visited
(-1,2 invalid)
(0,1)=4 visited


Iteration 8:
Pop (3,(2,2)).
Neighbors:
(1,2) now visite
(2,3)=2 visited
(2,1)=3 visited
(3,2 invalid)

No water.


Iteration 9:
Pop (3,(2,4)).
Neighbors:
(1,4)=2 not visited → trapped = max(3-2,0)=1 ✅
Push (3,(1,4))
Water=3
(2,5)=1 visited
(2,3)=2 visited
(3,4 invalid)


Iteration 10:
Pop (3,(1,0)).
Neighbors:
(0,0)=1 visited
(1,1)=2 not visited → trapped = max(3-2,0)=1 ✅
Push (3,(1,1))
Water=4
(2,0)=2 visited
(1,-1 invalid)


Iteration 11:
Pop (3,(2,1)).
Neighbors:
(1,1)=2 visited already
(2,2)=3 visited
(2,0)=2 visited
(3,1 invalid)

No water.


Iteration 12:
Pop (3,(1,3)).
Neighbors:
(0,3)=1 visited
(1,4)=2 visited
(2,3)=2 visited
(1,2)=1 visited

No water.


Iteration 13:
Pop (3,(1,2)).
Neighbors:
Surrounded, all visited.
No new water.


Iteration 14:
Pop (3,(1,4)).
Neighbors:
All visited.


Iteration 15:
Pop (3,(1,1)).
Neighbors:
(1,2)=1 visited
(1,0)=3 visited
(1,3)=3 visited
(2,1)=3 visited

No water.


Iteration 16:
Pop (4,(0,1)).
Neighbors already visited.


Iteration 17:
Pop (4,(1,5)).
Neighbors already visited.


Final Result:
Water collected = 4 units ✅


Visual Recap (Water Fill Steps):

(1,2)=1 filled → trapped 2 units (raised to 3)
(1,4)=2 filled → rapped 1 unit (raised to 3)
(1,1)=2 filled → trapped 1 unit (raised to 3)


Water collected inside valley:
[ , , , , , ]
[ , +1, +2, , +1, ]
[ , , , , , ]
Total = 4 units


*/