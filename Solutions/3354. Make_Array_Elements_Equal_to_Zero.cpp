class Solution {
public:
    bool isValid(vector<int>& nums,int dir,int curr){
        vector<int> temp = nums;
        int n = temp.size();

        while(curr>=0 && curr<n){
            if(temp[curr]==0){
                curr+=dir;
            }else{
                temp[curr]--;
                dir= -dir;
                curr+=dir;
            }
        }

        for(int x : temp){
            if(x!=0) return false;
        }
        return true;
    }
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i =0;i<n;i++){
            if(nums[i]==0){
                if(isValid(nums,1,i)){
                    res++;
                }
                if(isValid(nums,-1,i)){
                    res++;
                }
            }
        }
        return res;
    }
};