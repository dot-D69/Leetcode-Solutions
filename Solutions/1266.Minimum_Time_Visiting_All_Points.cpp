class Solution {
    public:
        int minTimeToVisitAllPoints(vector<vector<int>>& points) {
            int time = 0;
            for (int i=0;i<points.size()-1;i++){
                int dx = abs(points[i+1][0]-points[i][0]); // this is how we access x2- x1
                int dy = abs(points[i+1][1]-points[i][1]);  // this is how we access y2- y1
                time+=max(dx,dy);
            }
            return time;
        }
    };
    
    // Time Complexity:
    // O(n) — looping through n - 1 pairs.
    
    // Space Complexity:
    // O(1) — constant extra space used.