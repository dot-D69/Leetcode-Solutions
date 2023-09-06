class Solution {
public:
    vector<int> vec;
    
    void subset(int i, vector<int>& nums, vector<int>& vec) {
        if (i >= nums.size()) {
            result.push_back(vec);
            return;
        }
        vec.push_back(nums[i]);
        subset(i + 1, nums, vec);
        vec.pop_back();
        subset(i + 1, nums, vec);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        subset(0, nums, vec);
        
        sort(result.begin(), result.end());  
        
        
        result.erase(unique(result.begin(), result.end()), result.end());

        return result;
    }

private:
    vector<vector<int>> result;
};

/*
It is preety much similiar to the question 78. Subsets.
The only difference is that we have to remove the duplicates from the result.
So, what i did is that after generating the subset i sorted the result vector
After sorting the result vector
we first do unique(result.begin(),result.end()) which doesnt not remove the duplicates but pushes them to the end of the vector and returns a pointer to the first duplicate element
ex: [1,2,2,3,3,3,4,4,4,4,5,5,5,5,5] after unique() it becomes [1,2,3,4,5,2,3,4,5,5,5,5,5,5,5] and returns a pointer to the 2 which is the first duplicate element
then we do result.erase(unique(result.begin(),result.end()),result.end()) which removes the duplicates from th epointer returned by unique() to the end of the vector.

Now i dont know why we have to sort the input vector but it doesnt work without sorting the input vector and rule is if it works dont touch it 😅.

*/