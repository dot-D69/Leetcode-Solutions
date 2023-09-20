class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Ensure k is within the range [0, n)

        if (k > 0) {
            reverse(nums.begin(), nums.end()); // Reverse the entire array
            reverse(nums.begin(), nums.begin() + k); // Reverse the first k elements
            reverse(nums.begin() + k, nums.end()); // Reverse the remaining elements
        }
    }
};