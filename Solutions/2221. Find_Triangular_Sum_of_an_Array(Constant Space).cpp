//If we want to solve this  in  O(1) space
// So instead of creating a new array, we just update it in the given nums
//Time Complexity: O(n^2)
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for(int last_idx = n-1;last_idx>=1;last_idx-- ){
            for(int i =0;i<last_idx;i++){
                nums[i]=(nums[i]+nums[i+1])%10;
            }
        }
        return nums[0];
    }
};


/*

Explanation:

Given nums = [1 2 3 4 5]
we when we are doing (nums[i]+nums[i+1])%10 in that case
1+2 = 3
2+3 = 5
3+4 = 7
4+5 = 9

So our i ony goes till 4 i.e. n-2
SO instead of storing these reuslt in a new array, we just update them in the given arrray
Hence our nums become : [3,5,7,9,5]
what we are doing here is nums[i] = (nums[i]+nums[i+1])%10
Now for the next iteration we will start form i -0 and go only till n-2 --> [3,5,7,9]
This way we don't take any older element into our result addition and also maintain the correctness of the code

for(int last_idx = n-1;last_idx>=1;last_idx-- )  // This Keeps track of the last index till which the arr is valid and after each iteration decreses it by 1

for(int i =0;i<last_idx;i++) // This is the loopp that goes from i=0 to n-2,since i<last_idx , so it never  oges till the lst it stop before the last index hence n-2, this way keep updating our array without any extra space and still get the right answer 

*/