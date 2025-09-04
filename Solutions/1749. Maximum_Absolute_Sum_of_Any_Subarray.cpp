class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        //Kadane's Algo to find MaxSubarraysum
        int maxSubSum =nums[0];
        int curr_sum = 0;
        for(int i=0;i<n;i++){
            curr_sum =max(nums[i], curr_sum+nums[i]);
            maxSubSum = max(maxSubSum, curr_sum);   
        }

        //Kadane's Algo to find MaxSubarraysum
        int minSubSum =nums[0];
        curr_sum = 0;
        for(int i=0;i<n;i++){
            curr_sum =min(nums[i], curr_sum+nums[i]);
            minSubSum = min(minSubSum, curr_sum);   
        }

        return max(maxSubSum, abs(minSubSum));
    }
};

/*
 *****************************************************************
            Intuition — Why Max and Min Kadane?

Step 1: Recall Kadane’s Algorithm

Normal Kadane finds the maximum subarray sum by always asking:
“Should I continue the subarray or restart at this element?”
That gives us the maximum positive gain possible.


Step 2: What about negative sums?

Absolute value cares about both sides.
Imagine nums = [2,-5,1,-4,3,-2].

The maximum subarray sum is only 3, but look at the subarray [-5,1,-4]. Its sum = -8, absolute value = 8.
Clearly the most negative subarray can also give the answer.
So we need another Kadane but instead of maximizing, we minimize.
At each step, instead of choosing the larger (max), we choose the smaller (min).
This gives us the minimum subarray sum (the most negative sum possible).



Step 3: Combine

Let maxSubSum = maximum subarray sum
Let minSubSum = minimum subarray sum
Then the final result must be:
max(maxSubSum, abs(minSubSum))

Because one of them will represent the subarray with the largest absolute sum.


$$$$$$ Memory Trick $$$$$$$

Normal Kadane → find max gain (profits).
Inverse Kadane (min) → find max loss (deepest pit).
The nswer is whichever has the greater depth when viewed in absolute terms.

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
[IMPORTANT NOTE] : 

So the intuition is:
We don’t know whether the maximum absolute sum comes from a very positive subarray or a very negative subarray.
Kadane (max) gives us the first case.
Kadane (min) gives us the second case.
Taking max(maxSubSum, abs(minSubSum)) ensures we cover both.

*/

// ------------------------------------------------------------------------------------------------------------

/*
Kadane's Algorithm (Extended for Absolute Sum):

The question here is to find the maximum absolute sum of any subarray.

We already know how Kadane’s algorithm works for maximum subarray sum:
   → At each step we decide whether to continue the current subarray (curr_sum + nums[i]) 
     or start a new subarray from nums[i].

But here we need the maximum absolute sum. 
So we need to check **both sides**:
   1. The maximum subarray sum (like normal Kadane).
   2. The minimum subarray sum (this will give the largest negative sum, and its absolute value could be the answer).

Finally, the result = max(maxSubSum, abs(minSubSum)).


For example let's see the algo in function

nums = [1,-3,2,3,-4]

First we calculate the maximum subarray sum:

maxSubSum = nums[0] = 1
curr_sum = 0

i=0
    nums[i] = 1, curr_sum+nums[i] = 0+1 = 1
    so curr_sum = 1, subarray = [1]
    maxSubSum = 1

i=1
    nums[i] = -3, curr_sum+nums[i] = 1 + (-3) = -2
    compare -3 and -2 → better to start new from -3
    so curr_sum = -3, subarray = [-3]
    maxSubSum = 1 (unchanged)

i=2
    nums[i] = 2, curr_sum+nums[i] = -3+2 = -1
    compare 2 and -1 → better to start new from 2
    so curr_sum = 2, subarray = [2]
    maxSubSum = 2

i=3
    nums[i] = 3, curr_sum+nums[i] = 2+3 = 5
    compare 3 and 5 → better to continue
    so curr_sum = 5, subarray = [2,3]
    maxSubSum = 5

i=4
    nums[i] = -4, curr_sum+nums[i] = 5+(-4) = 1
    compare -4 and 1 → better to continue
    so curr_sum = 1, subarray = [2,3,-4]
    maxSubSum = 5

So maximum subarray sum = 5



Now we calculate the minimum subarray sum:

minSubSum = nums[0] = 1
curr_sum = 0

i=0
    nums[i] = 1, curr_sum+nums[i] = 0+1 = 1
    so curr_sum = 1, subarray = [1]
    minSubSum = 1

i=1
    nums[i] = -3, curr_sum+nums[i] = 1+(-3) = -2
    compare -3 and -2 → better to continue with -2
    so curr_sum = -2, subarray = [1,-3]
    minSubSum = -2

i=2
    nums[i] = 2, curr_sum+nums[i] = -2+2 = 0
    compare 2 and 0 → better to take 0
    so curr_sum = 0, subarray = [1,-3,2]
    minSubSum = -2

i=3
    nums[i] = 3, curr_sum+nums[i] = 0+3 = 3
    compare 3 and 3 → same, so curr_sum = 3
    subarray = [3]
    minSubSum = -2

i=4
    nums[i] = -4, curr_sum+nums[i] = 3+(-4) = -1
    compare -4 and -1 → better to take -4
    so curr_sum = -4, subarray = [-4]
    minSubSum = -4

So minimum subarray sum = -4


Now final step:
maxAbsoluteSum = max(maxSubSum, abs(minSubSum))
                = max(5, |-4|)
                = max(5,4)
                = 5


*/