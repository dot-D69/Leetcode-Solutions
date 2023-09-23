class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int cnt0=0,cnt1=0,cnt2=0;

        for(int i =0;i<n;i++){
            if(nums[i]==0)cnt0++;
            else if(nums[i]==1)cnt1++;
            else cnt2++;
        }

        int j=0;
        while(cnt0--){
            nums[j]=0;
            j++;
        }
        while(cnt1--){
            nums[j]=1;
            j++;
        }
        while(cnt2--){
            nums[j]=2;
            j++;
        }
    }

};


// Time compelxity -O(n)