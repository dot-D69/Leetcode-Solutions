class Solution {
public:
    int DaysReq(vector<int> & weights,int cap){
        int days=1,load=0;

        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>cap){
                days+=1;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
            int low=*max_element(weights.begin(),weights.end());
        int high =accumulate(weights.begin(), weights.end(), 0);
        int ans=low;
        while(low<=high){
            int mid=(low+high)/2;
            int no_Days=DaysReq(weights, mid);
            if(no_Days<=days){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};