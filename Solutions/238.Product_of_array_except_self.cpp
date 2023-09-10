class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size(),1); // intialize all the values of answer with 1
        
        int prefix = 1;
        for(int i =0;i<nums.size();i++){
            answer[i] = prefix;
            prefix*=nums[i]; 
        }

        int postfix =1;
        for(int i = nums.size()-1;i>=0;i--){
            answer[i]*=postfix;
            postfix*=nums[i];
        }

        return answer;
        
    }
};

/*
EXPLANATION:
1. We will first traverse the array from left to right and store the prefix product of each element in the answer array.
2. Then we will traverse the array from right to left and store the postfix product of each element in the answer array.
3. Then we will return the answer array.

Dry run:
nums = [1,2,3,4]
answer = [1,1,1,1]

prefix = 1
answer[0] = 1
prefix = 1*1 = 1
answer[1] = 1
prefix = 1*2 = 2
answer[2] = 2
prefix = 2*3 = 6
answer[3] = 6

postfix = 1
answer[3] = 6*1 = 6
postfix = 1*4 = 4
answer[2] = 2*4 = 8
postfix = 4*3 = 12
answer[1] = 1*12 = 12
postfix = 12*2 = 24
answer[0] = 1*24 = 24

answer = [24,12,8,6]

// Time Complexity: O(N)
*/