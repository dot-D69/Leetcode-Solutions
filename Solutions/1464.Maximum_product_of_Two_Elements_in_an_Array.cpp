class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1=INT_MIN;
        int max2=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=max1){
                max2=max1;
                max1=nums[i];
            }
            else if(nums[i]>max2 && nums[i]!=max1){
                max2=nums[i];
            }
        }
        int p= (max1-1)*(max2-1);
        return p;
    }
};

/*

Initialize two variables, max1 and max2, to store the two largest distinct elements from the input array nums. Set them both to INT_MIN initially.

Loop through the elements of the nums array using the index i, ranging from 0 to nums.size() - 1 (inclusive).

For each element nums[i]:

Check if it is greater than or equal to the current maximum value max1.
If yes, update max2 with the current value of max1.
Then, update max1 with the value of nums[i].
If nums[i] is not greater than max1 but greater than max2, update max2 with the value of nums[i].
After looping through all elements of nums, you will have the two largest distinct elements stored in max1 and max2.

Calculate the product of (max1 - 1) * (max2 - 1) and return it as the result.

*/