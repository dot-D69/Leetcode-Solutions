//Simulation Approach
//Simply do what is asked
//Time Complexity: O(n^2)
// Space Complexity: O(n)
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while(nums.size()>1){
            vector<int> arr;
            for(int i =0;i<nums.size()-1;i++){
                arr.push_back((nums[i]+nums[i+1])%10);
            }
            nums=move(arr);
        }
        return nums[0];
    }
};

//There is not much to explain:
// We simply did what was said
// created a new array arr : to that we added (nums[i]+nums[i+1])%10
// After every update the size of the arr shrink by 1/
// The loop continues till n>1 , and then we just return the element present in the arr with size 1