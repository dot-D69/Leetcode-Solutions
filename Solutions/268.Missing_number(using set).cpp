class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            unordered_set<int> s(nums.begin(), nums.end());
            for(int i=0;i<=nums.size();i++){
                if(s.find(i)==s.end()){
                    return i;
                }
            }
            return -1;
            
        }
    };
    
    //Time Complexity: O(n)
    //Space Complexity: O(n) , Although it takes up extra space for set which we can improve