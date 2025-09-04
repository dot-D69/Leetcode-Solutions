class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Kadane's Algorithm:
        int n = nums.size();

        int maxSubSum =nums[0];
        int curr_sum = 0;

        for(int i=0;i<n;i++){
            curr_sum =max(nums[i], curr_sum+nums[i]);
            maxSubSum = max(maxSubSum, curr_sum);
            
        }
        return maxSubSum;
    }
};

/*

Kadane's Algorithm:

The Kadane algo works like this:

We first just assume that the max subarray sum is equal to   the first element it self

Then we traverse the the array and at eaxh step of the traversal we ask two questions
 i.) is the current sum + current element is greater or the current element is greater?
     Meaning which will proivde the maximum subarray if we add the current element to the our subarray 
     Or if we start a new subarray from this element 

 ii.) We just need to update the maximum subarray with the max of (current sum and maximum subarray sum)
     If we started a new subarray or added a new element to our subarray and the sum increses so it means that subaaray
     has the max sum so we update it



For example let's see the algo in function

nums = [-2,1,-3,4,-1,2,1,-5,4]
maxsum = nums[0] = -2;
curr_sum =0

i=0
    we  ask the same question should we take the next ele or start a new subarray from ele
  nums[i] = -2 , curr_sum+nums[i] =-2 (so update curr_sum =-2)  subarray = [-2]
  maxsum = -2; (since 0 > -2)

i=1:
  Then we again ask the same question should we take the next ele or start a new subarray from element
   nums[i]=1 , curr_sum+nums[i] = -1 (So we update the curr_sum = -1)    subarray  =[1]  (we start the subarray from the new element as it guarantees a better sum than [-2,1] )
   maxsum = -1;

i=2:
    we again ask the same question should we take the next ele or start a new subarray from element
    nums[i] = -3, curr_sum+nums[i] = -1+(-3) = -4 . (so curr_sum = -3) subarray =[-3] (we start the subarray from the new element as it guarantees a better sum than [-2,1,-3])
    maxsum = -1;

i=3:
    we again ask the same question should we take the next ele or start a new subarray from element
    nums[i]= 4, curr_sum+nums[i]=-1 , (so we curr_sum = 4)  subarray =[4] (we start the subarray from the new element as it guarantees a better sum than [-3])
    maxsum = 4;

i=4:
    we again ask the same question should we take the next ele or start a new subarray from element
    nums[i] = -1 , curr_sum+nums[i] = 4 + (-1) = 3 . (so curr_sum = 3) subarray =[4,-1] (we continue the subarray as it guarantees a better sum than starting new from -1)
    maxsum = 4; 

i=5:
    we again ask the same question should we take the next ele or start a new subarray from element
    nums[i] = 2 , curr_sum+nums[i] = 3 + 2 = 5 . (so curr_sum = 5) subarray =[4,-1,2] (we continue the subarray as it guarantees a better sum than starting new from 2)
    maxsum = 5; 

i=6:
    we again ask the same question should we take the next ele or start a new subarray from element
    nums[i] = 1 , curr_sum+nums[i] = 5 + 1 = 6 . (so curr_sum = 6) subarray =[4,-1,2,1] (we continue the subarray as it guarantees a better sum than starting new from 1)
    maxsum = 6; 

i=7:
    we again ask the same question should we take the next ele or start a new subarray from element
    nums[i] = -5 , curr_sum+nums[i] = 6 + (-5) = 1 . (so curr_sum = 1) subarray =[4,-1,2,1,-5] (we continue the subarray as it guarantees a better sum than starting new from -5)
    maxsum = 6; 

i=8:
    we again ask the same question should we take the next ele or start a new subarray from element
    nums[i] = 4 , curr_sum+nums[i] = 1 + 4 = 5 . (so curr_sum = 5) subarray =[4,-1,2,1,-5,4] (we continue the subarray as it guarantees a better sum than starting new from 4)
    maxsum = 6; 


******************************************************************************************************************************
How to Remember Kadane’s in Exam/Interview:

Just recall:
“Do I extend, or do I restart?” → That’s Kadane’s at heart.

Visualize curr_sum like carrying a bag of sum. If it drags you down (becomes worse than starting new), drop the bag and restart.
*/
// The above solution is kadane
// Time Complexity: O(n)
// Space Complexity: O(1)
