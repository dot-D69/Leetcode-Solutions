// Brute Force
//Gives TLE since O(n^3)
//We just simply use the formula for a valid triangle i.e: a+b >c && b+c>a && c+a>b
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int count =0;
        for(int i=0;i<=n-3;i++){
            for(int j=i+1;j<=n-2;j++){
                for(int k =j+1;k<=n-1;k++){
                    if(nums[i]+nums[j]>nums[k] && nums[i]+nums[k]>nums[j] && nums[k]+nums[j]>nums[i]){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};