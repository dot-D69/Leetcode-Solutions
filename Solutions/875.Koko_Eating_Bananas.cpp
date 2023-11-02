class Solution {
public:

    int findmax (vector<int>&piles){
    int maxi=INT_MIN;
    int n=piles.size();
    for(int i=0;i<n;i++){
        maxi=max(maxi,piles[i]);
    }
    return maxi;
}

long long totalhours(vector<int> &piles, int h){
    long long hours=0;
    int n=piles.size();
    for(int i=0;i<n;i++){
        hours+=ceil((double)(piles[i])/ (double)(h));
    }
    return hours;
}
    int minEatingSpeed(vector<int>& piles, int h) {
         int low=1,high=findmax(piles);
    int ans=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        long long Hours = totalhours(piles,mid);
        
        if(Hours<=h){
            ans=min(ans,mid);
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
        
    }
};


// We know that thee minimum number of bananas to be eaten are 1 and the max number that can be eaten could be any number but since we require the minimum so the max  number of banana present in the pile are the max
// So low =1 high= max element of the array
// now we find the mid and then we check the with mid by dipilesind the each element of the array by the mid element and storing the ceil pilesalue of the dipilesison in order to find out the numbers of hours 
// it would take if monkey eats arr[mid] bananas per hour 

// If the hours returned are less than then timeline so it maybe our answer and we update it to our pilesariable ans 
// Since we need the minimum number so if we get our answer by the arr[mid] so we dont need to search to for elements at its right since they wil be high only and we need minimum so we eleiminate the right part
// similarily when we reach a arr[mid] such that the it exceeds our gipilesen timline so we will not find the answer to the left of it so eliminate the left part

//We keep doing the abopilese steps utinl low passees high