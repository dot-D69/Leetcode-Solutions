// Without Using extra 2*n of space
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n =nums.size();


        //Now we need to count the total number of ones present in tha array we could do that by using a simple  for loop
        // But since there are only 0 & 1's so we could just add up

        int totalOnes=accumulate(nums.begin(),nums.end(),0); // The 0 is the initial sum that all the otehr will be added to

        int i=0,j=0;
        int curr_ones=0;
        int Maxcount=0;

        while(j<2*n){  // iterate over the array  
            if(nums[j%n]==1){
                curr_ones++;
            }

            if(j-i+1>totalOnes){ // Sliding window (if the window exceeds the totalones length so we minimize the window i.e i++)
                curr_ones-=nums[i%n];// Subtract the element at the ith position since i would be moving forward
                i++;
            }

            Maxcount = max(Maxcount,curr_ones);
            j++;
        }
        return totalOnes-Maxcount;
    }
};


//Time Complexity : O(n)
//Space Complexity: O(n)

// Instead of using  of an extra array we just modulo the indexex that we are accesing by 
// So when the index reaches the end of the array it is again reset to the 0th Index thus giving uss the Circular array
