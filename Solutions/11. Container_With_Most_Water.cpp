class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i =0;
        int j = n-1;
        int maxArea=0;
        while(i<j){
            int length = min(height[i],height[j]);
            int breadth = j-i;
            int area = length * breadth;
            maxArea = max(area,maxArea);
            (height[i]<height[j])?i++:j--;
        }
        return maxArea;
    }
};

/*Complexities:

Time: O(n) — single pass, each pointer moves at most n times.
Space: O(1) — just variables.
*/

/*
Two Pointer Solution

We only need a single pass solution:

place one pointer at the starting and one at the end
i = 0, j = n-1

We need the maxArea of water that can be stored
The water occupies the area same as that of a rectangle
Area of Rectadngle = Length * Breadth

So for our length we take the min of heigh[i] and height[j]
Because if one tower length is 8 and other tower length is 7 , So the max height of the water that can be stored in bettwen these towers is 7, if the water height exceeded over 7 so the water will overflow and not be stored

for the breadth : we need to find the distance between the both towers which nothing  but diffrence of (j - i)
if 8 is at index 2 and tower 7 is at index 9  : So the distance between them is 9 -2 {We always do j-i because j is aleways greater than i , (it's j the index that is greater not the height at index j )}

Now we hae our length and breadth we just need to find the area = length * breadth
We update the maxArea as max of area and maxArea

aftert this we will


*/