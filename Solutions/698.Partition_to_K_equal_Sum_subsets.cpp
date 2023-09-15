class Solution {
public:

    bool get(int i,int current_bucket,int current_sum,int target_sum,int k, vector<int> &nums, vector<int> &check){

        if(current_bucket==k+1) return true;

        if(current_sum == target_sum) {
            return get(0,current_bucket+1,0,target_sum,k,nums,check);
        }

        if(i>=nums.size()) return false;
        if(current_sum>target_sum) return false;

        if(check[i]==1){
            return get(i+1,current_bucket,current_sum,target_sum,k,nums,check);
        }
        else{

            //pick the element
            current_sum+=nums[i];
            check[i]=1;
            bool pick = get(i+1,current_bucket,current_sum,target_sum,k,nums,check);

            //skip 
            current_sum-=nums[i];
            check[i]=0;
            bool skip = get(i+1,current_bucket,current_sum,target_sum,k,nums,check);

            return pick||skip;
        }
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        vector<int> check(nums.size(),0);
        int sum =0;
        for(int x: nums){
            sum+=x;
        }
        if(sum%k!=0) return false;

        int target_sum = sum/k;
        return get(0,1,0,target_sum,k,nums,check);
        
    }
};