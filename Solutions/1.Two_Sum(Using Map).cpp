class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
           int x=nums[i];
           int y=target-x;
           if(map.find(y)!=map.end()){
                return{i,map[y]};
           }
           map[nums[i]]=i;
        }
        return {-1,-1}; 
    }
};


// This implementation only requires a single pass through the nums vector and has a time complexity of O(n) and a space complexity of O(n).
// We use an unordered_map to map all the array indexes to the map.
// if x+y=target so target-x =y (This is the main logic of this code).
// If there exists a y in the map that satisfies our problem, we have our pair of solutions.
// The above code also works if there are duplicate elements. 
// e.g [2,1,2] target =4 answer = {0,2}.
// The first time any element is inserted in the map is when one iteration is completed,so when we have x=2 our y is also 2 but there is no 2 in the map
// After the iteration 2 is inserted in the map so when we x=2(index 2) and y is again 2, so it returns the index 0 (of the 2 that we inserted) 
