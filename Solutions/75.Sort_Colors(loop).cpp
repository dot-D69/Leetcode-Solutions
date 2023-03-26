class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int k=0;
        int l= n-1;
        for(int i =0;i<n;i++){
            if(nums[i]==0){
                swap(nums[k],nums[i]);
                k++;
            }
        }

        for(int i =n-1;i>=0;i--){
            if(nums[i]==2){
                swap(nums[l],nums[i]);
                l--;
            }
        }
    }
};


// Time Complexity -O(n)