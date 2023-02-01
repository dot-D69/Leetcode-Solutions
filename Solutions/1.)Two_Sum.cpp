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