class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        for(int i =0;i<=n;i++){
            sum+=i;
        }
        int result = accumulate(nums.begin(), nums.end(), 0);
        return sum-result;
    }
};