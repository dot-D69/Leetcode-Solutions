class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n =nums.size();
        int low =0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target) return mid;
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
    return -1;
        
    }
};

//Since the array is rotated so one half of the array  will alawas be sorted while the  other half will not be sorted
//We just have to search for the half that is sorted and check it for the target if our target is in that half
//  if it is then we eliminate the other half
//  else if it is not in the sorted half so we eliminate the sorted half and check for the target in the other hafl

//We keep doing the same step agan and again until we foudnt he target or the array is exhausted