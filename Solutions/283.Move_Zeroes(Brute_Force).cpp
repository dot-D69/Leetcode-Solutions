// Brute Force
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        for(int i =0;i<n;i++){
            if(nums[i]!=0){
                temp.push_back(nums[i]);
            }
        }
        int zeroes= temp.size();
        for(int i =0;i<zeroes;i++){
            nums[i]=temp[i];
        }

        for(int i = zeroes;i<n;i++){
            nums[i]=0;
        }
        
    }
};