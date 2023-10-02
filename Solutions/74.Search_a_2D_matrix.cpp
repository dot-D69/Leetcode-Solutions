class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        unordered_map<int,int> mp;
        for(auto it:matrix){
            for(auto i : it){
                mp[i]++;
            }
        }
        return mp.find(target)!=mp.end();
    }
};