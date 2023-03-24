class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        vector<int> v(101);

        for(auto a:nums){
            v[a]=1;
        }

        for(int i =1;i<=100;i++){
            ans+=v[i];
        }

        return ans;


    }
};