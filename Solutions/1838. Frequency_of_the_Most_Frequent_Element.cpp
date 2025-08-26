class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int l =0;
        long curr_sum =0;
        int res =0;
        sort(nums.begin(), nums.end());

        for(int r =0; r<n;r++){
            long target = nums[r];
            curr_sum+= nums[r];
            long window_sum = (r-l+1)*target;
            long steps = window_sum-curr_sum;
            
            if(steps>k){
                curr_sum -= nums[l];
                l++;
            }
            res = max(res, r-l+1);
        }

        return res;
    }
};


/*
1. Sort the array
sort(nums.begin(), nums.end());

We sort because it makes the problem simpler.

Once sorted, if we try to make numbers equal in a window [l..r], we only ever need to raise smaller numbers up to nums[r].

Without sorting, we’d have to think about both raising and lowering, which complicates things.


2. Initialize
int l = 0;          // left pointer of window
long curr_sum = 0;  // sum of elements inside current window
int res = 0;        // best answer so far

We will keep a sliding window [l..r].
curr_sum keeps track of the sum of all numbers currently inside that window.
res is the maximum window length (frequency) we’ve seen.



3. Expand window with r
for (int r = 0; r < n; r++) {
    curr_sum += nums[r];
    long target = nums[r];


At each step, we extend the window by including nums[r].
Because the array is sorted, nums[r] is the largest number in the current window.
That means if we want to make all numbers in [l..r] equal, they must all become nums[r].



4. Compute cost (steps)
long window_sum = (r - l + 1) * target;
long steps = window_sum - curr_sum;

Here’s the key logic:

window_sum = (window size) * target
→ This is the sum we would have if every element in [l..r] were equal to target.

curr_sum = actual sum of elements in window.

steps = window_sum - curr_sum
→ This is how much we need to add across the window to “upgrade” all numbers to target.

So steps tells us:
 the number of increments required to make all numbers in the window equal to nums[r].



5. Shrink window if cost too high
if (steps > k) {
    curr_sum -= nums[l];
    l++;
}


If steps > k, it means the cost of equalizing this window is more than the allowed increments.
So we shrink the window by moving l forward (exclude the leftmost number).
At the same time, we adjust curr_sum because we removed nums[l].
This ensures our window always represents the largest possible valid segment ending at r.


6. Update result
res = max(res, r - l + 1);

If the current window [l..r] is valid (cost ≤ k after adjustments), its size (r-l+1) is a possible frequency.
We store the maximum seen so far in res.



7. Final result
return res;


After processing all r, res contains the maximum possible frequency.


DRY RUN:
Let’s take:

nums = [1, 2, 4], k = 5

Step 1: Sort

Already sorted → [1, 2, 4]

Step 2: Start sliding

Initialize:
l = 0, curr_sum = 0, res = 0

 r = 0 → nums[0] = 1

Add to curr_sum → curr_sum = 1

Window size = 1

target = 1

window_sum = 1*1 = 1

steps = 1 - 1 = 0 (need 0 extra food)

steps <= k ->yes → res = max(0,1) = 1

 r = 1 → nums[1] = 2

Add to curr_sum → curr_sum = 1+2 = 3

Window size = 2

target = 2

window_sum = 2*2 = 4

steps = 4 - 3 = 1

steps <= k-> yes → res = max(1,2) = 2

r = 2 → nums[2] = 4

Add to curr_sum → curr_sum = 3+4 = 7

Window size = 3

target = 4

window_sum = 3*4 = 12

steps = 12 - 7 = 5

steps <= k yes → res = max(2,3) = 3

Final Answer → res = 3

We can make all 3 plates equal by:

[1, 2, 4] → [4, 4, 4] using k = 5

*/

