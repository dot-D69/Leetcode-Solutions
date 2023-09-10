class Solution {
public:

    void Merge(vector<int>& nums,int low,int mid,int high){
        int left = low;
        int right = mid+1;

        vector<int> temp;

        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }

        for(int i = low;i<=high;i++){
            nums[i] = temp[i-low];
        }
    }
    
    void mergesort(vector<int>& nums,int low ,int high){
        if(low>=high){
            return;
        }
        int mid = (low+high)/2;

        mergesort(nums,low,mid);
        mergesort(nums,mid+1,high);
        Merge(nums,low,mid,high);

    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
        
    }
};