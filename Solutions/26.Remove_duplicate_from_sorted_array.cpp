class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        int k = 0;
        for(int i=0;i<nums.size();i++){
            if(!s.count(nums[i])){
                s.insert(nums[i]);
                nums[k]=nums[i];
                k++;
            } 
        }
        return k;
    }
};

/*
    1.Suppose we have the input vector nums = [1, 1, 2].

    2.Initially, nums = [1, 1, 2], s = {}, and k = 0.

    Loop starts:

    3.i = 0, nums[0] = 1, s does not contain 1, so we insert 1 into s, update nums[0] = 1, and increment k to 1.
    Now, nums = [1, 1, 2], s = {1}, and k = 1.
    Continuing the loop:

    i = 1, nums[1] = 1, s already contains 1, so we skip this iteration.
    i = 2, nums[2] = 2, s does not contain 2, so we insert 2 into s, update nums[1] = 2, and increment k to 2.
    Now, nums = [1, 1, 2], s = {1, 2}, and k = 2  and the updated array is [1,2].
    Loop ends.

    At this point, the nums array contains the unique elements in the first k positions, and k represents the length of the modified array with duplicates removed. In this example, the modified array is [1, 2], and k is 2, which is the correct output.

    The value of k is not returning the entire array. Instead, it's indicating the index up to which the modified array contains unique elements. The length of the modified array can be determined by the value of k, and the modified array itself is represented by the first k elements of the nums array.
*/