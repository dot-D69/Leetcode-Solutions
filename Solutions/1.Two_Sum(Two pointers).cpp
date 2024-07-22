class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>> res;
        for(int i=0;i<n;i++){
            res.push_back({nums[i],i});
        }
        sort(res.begin(),res.end());
        int s=0;
        int e=n-1;
        while(s<e){
            int sum=res[s].first+res[e].first;
            if(sum==target){
                return {res[s].second,res[e].second};
            }
            else if(sum>target) e--;
            else s++;
        }
        return {-1,-1}; 
    }
};
//Time Complexity: O(nlogn)
//Space Complexiity: O(n)
