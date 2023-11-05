class Solution {
public:
    int SumofD(vector<int>&arr, int divisor){
	int n=arr.size();
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=ceil((double)(arr[i])/(double)(divisor));
	}
	return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(nums.begin(),nums.end());  // max_element returns the iterator that points to the max element so    we  * to obtain the value
	    int ans=1;
	    while(low<=high){
		    int mid=(low+high)/2;
		    int val=SumofD(nums,mid);
		    if(val<=threshold){
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