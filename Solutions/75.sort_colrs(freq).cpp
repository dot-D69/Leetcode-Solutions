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

        int x=0;
        while(cnt0--){
            nums[x]=0;
            x++;
        }
        while(cnt1--){
            nums[x]=1;
            x++;
        }
        while(cnt2--){
            nums[x]=2;
            x++;
        }
    }

};


// Time compelxity -O(n)