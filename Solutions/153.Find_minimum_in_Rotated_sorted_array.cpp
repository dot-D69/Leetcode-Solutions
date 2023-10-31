class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0, high=n-1, ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;

            //Check if left array is sorted
            if(nums[low]<=nums[mid]){
                ans=min(ans,nums[low]);
                low=mid+1; // Eliminate the rest of the lft half search space since we already have the minimum
            }
            else{
                ans=min(ans,nums[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
};

//We have to find minimum so the first thing we need is to find the sorted half that is how all questions of Rotated Sorted Array works mostly
// So first we find the the sorted half using the same old formla arr[low]<=arr[mid] for the left half 
// we dont need to write the same for right half cuase if the left half is not sorted then right half will definetly be
// now when we have the sorted array we find the min of that part if the sorted array isleft then min = arr[low]
// If the sorted array is right the min is arr[mid]
// Whichever part we pick after getting the minimum we eliminate that search space i.e low=mid+1 or high=mid-1;
//Now keep doing the same steps until we have exhausted the array 
