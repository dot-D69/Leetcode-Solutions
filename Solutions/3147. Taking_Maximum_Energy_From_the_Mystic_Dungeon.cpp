class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> res (n);
        for(int i = n-1;i>=0;i--){
            int new_index = i+k;

            if(new_index>=n){
                res[i]= energy[i];
            }else{
                res[i] = energy[i]+res[new_index];
            }
        }

        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            ans = max(ans,res[i]);
        }

        return ans;
    }
};


//Time Complexity: O(n)
//Space Complexity: O(n)

/*
We will do a reverse traveral of the empty array and at every index we will store the ans in a different res array

why we are doing so , because it helps us to what will the be answer 
    If we are at index 1 and we know the answer at +k steps will be 10 so we don't have to run a different loop to calculate it that's why

At last in the res array wil have the answer for all the indexex we just need to find max from it


DRY RUN Example:

energy = [5,2,-10,-5,1]
res = []

at i = 5
res[i] = 1 //since i+k goes out of bound
res= [1]   

i = 4
res[i] = -5 //since i+k goes out of bound
res=[-5,1]  

i = 3
res[i] = -10  //since i+k goes out of bound
res = [-10,-5,1] 

i=2
res[i] = enrgy[i] + res[i+k] = 2+1 = 3
res= [3,-10,-5,1]

i=1
res[i] = enrgy[i]+res[i+k] = 5+(-5) =0

res = [0,3,-10,-5,1]

max of res  = 3
ans = 3
*/