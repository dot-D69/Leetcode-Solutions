class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        	int n = nums.size();
    if(n==1) return nums[0]; // If the array is of single element return the element 
    //To make a reeadable code and avoid unnneccesary conditionals we take low and high as 1 and -2 so to take care of the first and last element
    if(nums[0]!=nums[1]) return nums[0]; // if first ele is not same as the second ele then that is our single element 
    if(nums[n-1]!=nums[n-2]) return nums[n-1]; // if the last ele is not same as the second last ele then that is our element

    int low=1,high=n-2;

    while(low<=high){
        int mid=(low+high)/2;

        //If we want to find the single element then the base idea is that the elements at its right and left will not be equal since the array is sorted and all other elements appear twice

        if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]) return nums[mid]; 


        // Check if we are at left half which has 2 conditons 
        // (even,odd) if we are at ood indeex and the the element at the previous odd index is same then 
        // Or if we are at even index and the element at the next odd index is same  then we are at left half
        // If we are at left half it means the element is at right half so we elimeinate the lft half search space
        if((mid%2==1 && nums[mid-1]==nums[mid]) || (mid%2==0 && nums[mid]==nums[mid+1])){
            low=mid+1; //eliminateleft half
        }
        else{
            high=mid-1; // Eliminate right halft
        }
    }
    return -1;    
    }

};class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        	int n = nums.size();
    if(n==1) return nums[0]; // If the array is of single element return the element 
    //To make a reeadable code and avoid unnneccesary conditionals we take low and high as 1 and -2 so to take care of the first and last element
    if(nums[0]!=nums[1]) return nums[0]; // if first ele is not same as the second ele then that is our single element 
    if(nums[n-1]!=nums[n-2]) return nums[n-1]; // if the last ele is not same as the second last ele then that is our element

    int low=1,high=n-2;

    while(low<=high){
        int mid=(low+high)/2;

        //If we want to find the single element then the base idea is that the elements at its right and left will not be equal since the array is sorted and all other elements appear twice

        if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]) return nums[mid]; 


        // Check if we are at left half which has 2 conditons 
        // (even,odd) if we are at ood indeex and the the element at the previous odd index is same then 
        // Or if we are at even index and the element at the next odd index is same  then we are at left half
        // If we are at left half it means the element is at right half so we elimeinate the lft half search space
        if((mid%2==1 && nums[mid-1]==nums[mid]) || (mid%2==0 && nums[mid]==nums[mid+1])){
            low=mid+1; //eliminateleft half
        }
        else{
            high=mid-1; // Eliminate right halft
        }
    }
    return -1;    
    }

};