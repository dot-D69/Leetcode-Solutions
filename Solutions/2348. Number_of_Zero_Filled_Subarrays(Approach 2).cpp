class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res =0;

        int count =0;

        for(int i =0;i<nums.size();i++){
            if(nums[i]==0){
                count++;
            }
            else{
                count=0;
            }
            res+=count;
        }

        return res;
    }
};

/*

This works on simpl observation
 i.) 0 -> subarrays =1
 ii.) 0 , 0  - > subarrays = 3    ( we already calculate for when single 0 it gives 1, now just add the number of zeroes to it  i.e. 1+2 =3 (this is the exact number of subarrays that will be formed)
 iii. ) 0,0,0 -> subarrays = 6( Same we aldready calculate for two 0's -> 3, just add the number of zeores to this i.e. 3+3 = 6)

 iv.) 0,0,0,0 -> subarrays = 10 (Similarly we calcul,ate for three 0's, just add no. of zeors to it i.e. 6+4=10)

 


*/