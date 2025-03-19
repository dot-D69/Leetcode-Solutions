class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int res = nums.size();
            for(int i=0;i<nums.size();i++){
                res= res^(i^nums[i]);
            }
            return res;
        }
    };
    
    //This is the most optimized code as the last code using sum formula may cause overflow for large n, as it is summing the elements;
    
    
    // This gives the best performance as for nay number of n, it will not give any overflow or any performance issue:
    
    
    // Time Complexity: O(n)
    // Space Complexity: O(1)