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
        while(i+1<nums.size()&&nums[i]==nums[i+1]) i++;
        subset(i + 1, nums, vec);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        subset(0, nums, vec);
        
        sort(result.begin(), result.end());  
        
        
        // result.erase(unique(result.begin(), result.end()), result.end());

        return result;
    }

private:
    vector<vector<int>> result;
};


// Instead of usin remove we could also use loop  to skip the same elements 
// It helps in the runtime of the program as it reduces the number of recursive calls
// Worst time complexity would still be O(2^n) as in the worst case all elements could be unique so it will go all the recursive calls  and the space complexity would be O(n)  for both the solutions 
