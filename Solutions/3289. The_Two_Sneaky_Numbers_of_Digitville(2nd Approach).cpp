class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(),nums.end());

        for(int i=1;i<nums.size();i++){
            if(nums[i-1]==nums[i]){
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};

//Time Complexity: O(nlogn)
//Space Complexity: O(1)