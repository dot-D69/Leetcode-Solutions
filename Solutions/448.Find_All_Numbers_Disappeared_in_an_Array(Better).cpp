class Solution {
    public:
        vector<int> findDisappearedNumbers(vector<int>& nums) {
            vector<int> res;
            unordered_set<int>s(nums.begin(),nums.end());
            for(int i=1;i<=nums.size();i++){
                if(s.find(i)==s.end()){
                    res.push_back(i);
                }
            }
            return res;
        }
    };
    
    // Time complexity: O(n) average case
    // Space complexity: O(n)