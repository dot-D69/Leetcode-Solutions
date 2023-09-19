// optimal
class Solution {
public:
    bool check(vector<int>& nums) {
        int count =0;
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                count++;
            }
        }
        if(nums[n-1]>nums[0])  count++;

        if(count<=1){
            return true;
        }
        return false;
    }
};

// there is a pattern in this question that being 
// there is only one such time or encounter when the previous elemeent is greater than the next element

// For eg: 1 2 3 4 5 (in this case every nums[i-1]<num[i] exceprt when 5 is compared to 1 in that case the previous element is greater is than next  this is a special case so we have such case by creating a diffrent conditional that is if(nums[n-1]>nums[0])  count++; )

// Eg: 3 4 5 1 2 (in this case there is only one such time when the precious element is greater than the next element and that is when 5 compared to 1 , even in the special case i.e nums[i-1] = 2 is less than nums[0]= 3 )

// So the pattern is that any array having the previous element gretaer than then next only for once is sorted and rotated

// For eg in this case 2 1 3 4   num[0]=2 > nums[1] = 1 so count =1 but also in the special case      nums[n-1] =  4 is also greater than the nums[0]=1 which akes the count = 2 so the array is not sorted and rotated

//There is also onee corner case when all elements are equal that [1,1,1] so in this case the count will remain zero and that is the why we are using the condition (count<=1)
