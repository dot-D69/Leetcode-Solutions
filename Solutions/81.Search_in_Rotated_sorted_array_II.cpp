class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n =nums.size();
        int low =0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target) return true;

    //If the elements are equal in the low mid and high then we can not find the dorted Aay corrctly so 
        if(nums[low]==nums[mid]&&nums[mid]==nums[high]){
            //since we already checked key with mid if it is not equal to mid thenn it is also not equal to low and hig as all are same
            //So we move high andlow in order to trim our search space make it easy to find the sorted Aay
            low=low+1;
            high=high-1;
            continue;
        }

        //Check if left half is sorted
        if(nums[low]<=nums[mid]){ // means it is sorted
            //Then we check if the target is present in the left half
            if(nums[low]<=target && target<=nums[mid]){
                high=mid-1; // since the target is present we eleiminate the right half
            } 
            else { // If the target is not present in the left half
                low=mid+1; // we eleiminate the left half
            }
        }
        // if the left half is not sorted then definetly the right half is sorteed
        else{
            if(nums[mid]<=target && target<=nums[high]){  // check if the target is present in the right half
                low=mid+1; // since the target is present we eleiminate the left half
            }
            else{ // If the target is not present in the right half
                high=mid-1; // we eleiminate the right half
            }

        }
    }
    return false;
        
    }
};