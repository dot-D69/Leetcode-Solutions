class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int s = nums.size();
        unordered_map<int,int> pair;
        vector <int> result;
        for(int i=0;i<s;i++){
            int k = target-nums[i];
            if(pair.count(k)>0){
                result.push_back(pair[k]);
                result.push_back(i);
                break;
            }
            pair[nums[i]]=i;
        }
    return result;
    }
};




// Explanation:

// 1. Initialize an unordered map map and a result vector result.
// 2. Loop through the nums vector.
// 3. For each iteration, calculate the complement value (target minus the current element nums[i]).
// 4. Check if the complement is in the map. If it is, push the indices of both elements (the complement and the current element) into the result vector and break the loop.
// 5. If the complement is not in the map, insert the current element into the map with its index as the value.
// 6. After the loop, return the result vector.
    
// This implementation only requires a single pass through the nums vector and has a time complexity of O(n) and a space complexity of O(n).

