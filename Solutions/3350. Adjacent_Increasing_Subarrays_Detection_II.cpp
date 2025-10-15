class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int L1 = 1;
        int L2 = 0;

        int res = 0;

        for(int i =1;i<n;i++){
            if(nums[i]>nums[i-1]){
                L1++;
            }else{
                L2 = L1;
                L1 = 1;
            }

            res = max(res,L1/2);
            res = max(res,min(L1,L2));
        }
        return res;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1)