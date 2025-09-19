class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int indx= -1;
        for(int i = n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                indx = i-1;
                break;
            }
        }
        
        if(indx!=-1){
            int swap_idx =indx;
            for(int j =n-1;j>=indx+1;j--){
                if(nums[j]>nums[indx]){
                    swap_idx=j;
                    break;
                }
            }
        swap(nums[indx],nums[swap_idx]);
        }


        reverse(nums.begin()+indx+1,nums.end());
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)

Code Breakdown:

Step 1: Initialization
    int n = nums.size(); 
    int indx = -1;
    n: Stores the size of the array nums.
    indx: A variable to track where the array starts decreasing. Initially set to -1 (indicating no decreasing point found yet).


Step 2: Find the first decreasing element (from the right)
    for(int i = n-1; i > 0; i--){
        if(nums[i] > nums[i-1]){
            indx = i-1;
               break;
        }
    }
Starting from the last element, we look for where the array starts decreasing.
Why decreasing? Because that's where we can "adjust" the array to get the next permutation.
If nums[i] > nums[i-1], it means nums[i-1] is the pivot that needs to be swapped.
indx is updated to store the position of this pivot.

Example Walkthrough for [1, 3, 5, 4, 2]:
Start at the end: Compare 2 and 4.
2 < 4, so continue.
Compare 4 and 5.
4 < 5, so continue.
Compare 5 and 3.
5 > 3: Found the decreasing point! indx = 2 (position of 3).
Edge Case:
If no decreasing point is found (array is already in descending order), indx remains -1.
Example: [3, 2, 1] → No decreasing point → Reverse the array to [1, 2, 3].

Step 3: Find the smallest number larger than the pivot
if(indx != -1){
    int swap_idx = indx;
    for(int j = n-1; j >= indx+1; j--){
        if(nums[j] > nums[indx]){
            swap_idx = j;
            break;
        }
    }
    swap(nums[indx], nums[swap_idx]);
}

Goal: Find the smallest number larger than nums[indx] (pivot) among elements to its right.
How? 
Ans: Start from the last element and move left.
    If nums[j] > nums[indx], we update swap_idx to j and break.

Why swap? 
Ans:To ensure the next permutation is just slightly larger than the current one.

Example Walkthrough for [1, 3, 5, 4, 2]:
Pivot: nums[indx] = 3.
Start from the end: Compare 2 and 3.
2 < 3, so continue.
Compare 4 and 3.
4 > 3: Found it! swap_idx = 3 (position of 4).
Swap pivot (3) with 4:
Array becomes [1, 4, 5, 3, 2].


Step 4: Reverse the elements to the right of indx
    reverse(nums.begin() + indx + 1, nums.end());

After swapping, the elements to the right of indx are still in descending order.
Why reverse?
Ans: To make them the smallest possible order (ascending).

Example Walkthrough for [1, 4, 5, 3, 2]:
Reverse elements to the right of indx = 2:
Reverse [5, 3, 2] → [2, 3, 5].
Final array: [1, 4, 2, 3, 5].

##################################################################################
Full Dry Run (Example: [1, 3, 5, 4, 2])
Initialization:
n = 5, indx = -1.

Find first decreasing element:

Starting from the end:
Compare 2 < 4: Continue.
Compare 4 < 5: Continue.
Compare 5 > 3: Found decreasing point at indx = 2.
Find smallest number larger than pivot (3):

Start from the end:
Compare 2 < 3: Continue.
Compare 4 > 3: Found it! swap_idx = 3.
Swap nums[indx] and nums[swap_idx]:
Swap 3 and 4: Array becomes [1, 4, 5, 3, 2].
Reverse elements right of indx:

Reverse [5, 3, 2]: Array becomes [1, 4, 2, 3, 5].
Result: [1, 4, 2, 3, 5] is the next permutation.


EDGE CASE DRY RUN:

When indx = -1
This situation occurs when the array is already sorted in descending order. In this case, there is no "next lexicographical permutation." Therefore, the array is rearranged into its lowest possible order, which is an ascending order.

The reversal achieves this transformation.

Code Relevant to This Case
if(indx == -1) {
    reverse(nums.begin(), nums.end());
}

What does this do?
The reverse() function flips the array in-place from the first element (nums.begin()) to the last (nums.end()), making the smallest permutation.

Dry Run Example: [3, 2, 1]

Step-by-Step Execution
Initial Array: [3, 2, 1]

Start by checking for a decreasing point from the right:
Compare 1 < 2: Continue.
Compare 2 < 3: Continue.
No increasing point is found → indx = -1.

Reversal Logic:
Call reverse(nums.begin(), nums.end());.
This swaps elements iteratively:
Swap the first (3) and last (1):
Array becomes [1, 2, 3].
Final Array: [1, 2, 3]

The array is now sorted in ascending order, which is the smallest permutation.

*/

/*
Key Takeaways:
Identify pivot: Look for the first decreasing point from the right.
Swap intelligently: Swap the pivot with the smallest larger number to its right.
Reverse the suffix: Ensure the suffix is in ascending order for the smallest permutation.


*/