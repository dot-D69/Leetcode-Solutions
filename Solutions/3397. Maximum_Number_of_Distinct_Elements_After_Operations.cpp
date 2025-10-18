class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int prev = INT_MIN;
        int count = 0;

        for(int i =0;i<n;i++){
            if(prev<nums[i]-k){
                prev = nums[i]-k;
                count++;
            }
            else if(prev< nums[i]+k){
                prev = prev+1;
                count++;
            }
        }
        return count;
    }
};

// Time Complexity: O(nlogn)
// Space Complexity: O(1)

