class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expected_sum= n*(n+1)/2;
        int result = accumulate(nums.begin(), nums.end(), 0);
        return expected_sum-result;
    }
};

//It is the optimized solution as it gives the correct answer everytime and does not use up any extra space unlike set.

// Time Complexity: O(n)
// Space Complexity: O(1)