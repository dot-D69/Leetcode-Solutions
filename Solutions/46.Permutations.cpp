class Solution {
public:
    void Permutation(int index,vector<int>& nums, vector<vector<int>>& result){
        if(index==nums.size()){
            result.push_back(nums);
        }

        for(int i = index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            Permutation(index+1,nums,result);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        Permutation(0,nums,result);
        return result;
        
    }
};


/*
Explanation:
    1. We are using backtracking here.
    2. We are swapping the elements of the array and then calling the function recursively.
    3. After the recursive call we are swapping the elements again to get the original array.

    I will explain the code with an example:
    nums = [1,2,3]
    index = 0
    i = 0
    swap(nums[0],nums[0]) // nums = [1,2,3]
    1st call. Permutation(1,nums,result)
        index = 1
        i = 1
        swap(nums[1],nums[1]) // nums = [1,2,3] swapping 2 with 2
        2nd call. Permutation(2,nums,result)
            index = 2
            i = 2
            swap(nums[2],nums[2]) // nums = [1,2,3] swapping 3 with 3
            3rd call. Permutation(3,nums,result)
                index = 3 // index == nums.size() result = [[1,2,3]] and return to 2nd call
            swap(nums[2],nums[2]) // nums = [1,2,3] swapping 3 with 3 again to get the original array and return to 1st call
    swap(nums[1],nums[2]) // nums = [1,3,2] swapping 2 with 3 
    4th call Permutation(2,nums,result)
        index = 2
        i = 2
        swap(nums[2],nums[2]) // nums = [1,3,2] swapping 2 with 2
        5th call Permutation(3,nums,result)
            index = 3 // index == nums.size() result = [[1,2,3],[1,3,2]] and return to 4th call
        swap(nums[2],nums[2]) // nums = [1,3,2] 
        swap(nums[1],nums[2]) // nums = [1,2,3] swapping 3 with 2 to get the original array and return to 1st call
    swap(nums[0],nums[1]) // nums = [2,1,3] swapping 1 with 2
    6th call Permutation(1,nums,result)
        index = 1
        i = 1
        swap(nums[1],nums[1]) // nums = [2,1,3] swapping 1 with 1
        7th call Permutation(2,nums,result)
            index = 2
            i = 2
            swap(nums[2],nums[2]) // nums = [2,1,3] swapping 3 with 3
            8th call Permutation(3,nums,result)
                index = 3 // index == nums.size() result = [[1,2,3],[1,3,2],[2,1,3]] a
            swap(nums[2],nums[2]) // nums = [2,1,3] swapping 3 with 3 again to get the original array and return to 7th call
        swap(nums[1],nums[2]) // nums = [2,3,1] swapping 1 with 3
        9th call Permutation(2,nums,result)
            index = 2
            i = 2
            swap(nums[2],nums[2]) // nums = [2,3,1] swapping 1 with 1
            10th call Permutation(3,nums,result)
                index = 3 // index == nums.size() result = [[1,2,3],[1,3,2],[2,1,3],[2,3,1]] 
            swap(nums[2],nums[2]) // nums = [2,3,1] swapping 1 with 1 again to get the original array and return to 9th call which returns to 6th call
        swap(nums[1],nums[2]) // nums = [2,1,3] swapping 3 with 1 to get the original array and return to 1st call
    swap(nums[0],nums[2]) // nums = [3,1,2] swapping 2 with 3
    11th call Permutation(1,nums,result)
        index = 1
        i = 1
        swap(nums[1],nums[1]) // nums = [3,1,2] swapping 1 with 1
        12th call Permutation(2,nums,result)
            index = 2
            i = 2
            swap(nums[2],nums[2]) // nums = [3,1,2] swapping 2 with 2
            13th call Permutation(3,nums,result)
                index = 3 // index == nums.size() result = [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2]] 
            swap(nums[2],nums[2]) // nums = [3,1,2] swapping 2 with 2 again to get the original array and return to 12th call
        swap(nums[1],nums[2]) // nums = [3,2,1] swapping 1 with 2
        14th call Permutation(2,nums,result)
            index = 2
            i = 2
            swap(nums[2],nums[2]) // nums = [3,2,1] swapping 1 with 1
            15th call Permutation(3,nums,result)
                index = 3 // index == nums.size() result = [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]] 
            swap(nums[2],nums[2]) // nums = [3,2,1] swapping 1 with 1 again to get the original array and return to 14th call which returns to 11th call
        swap(nums[1],nums[2]) // nums = [3,1,2] swapping 2 with 1 to get the original array and return to 1st call
    swap(nums[0],nums[1]) // nums = [1,3,2] swapping 3 with 1 to get the original array and return to main function
    result = [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

    Time Complexity: O(n*n!)
    Space Complexity: O(n*n!)


    The recursion tree for the above example is:
             (1,2,3)
                /   \-----------\
            (1,2,3)             (2,1,3)         ----- similarily for all other cases                                         
            /   \               /  \                                            
        (1,2,3) (1,3,2)    (2,1,3)                                          
            /       /          /                                         
        (1,2,3)     (1,3,2)  (2,1,3)                                                  

*/