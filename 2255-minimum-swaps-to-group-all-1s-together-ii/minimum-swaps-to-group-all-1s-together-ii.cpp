// Using extra 2*n of space
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n =nums.size();
        vector<int> arr(2*n); // initilaze an array twice the sie of nums in order to create a circular arra

        for(int i=0;i<2*n;i++){
        // To make a circular copy of the nums array (modulo helps us when we reach the end of the array)
        // if arr {1,0,1,1} so our arr would be{1,0,1,1,1,0,1,1} which will act as circular array
            arr[i]=nums[i%n];   
        }

        //Now we need to count the total number of ones present in tha array we could do that by using a simple for loop
        // But since there are only 0 & 1's so we could just add up

        int totalOnes=accumulate(nums.begin(),nums.end(),0); // The 0 is the initial sum that all the otehr will be added to

        int i=0,j=0;
        int curr_ones=0;
        int Maxcount=0;

        while(j<2*n){  // iterate over the array  
            if(arr[j]==1){
                curr_ones++;
            }

            if(j-i+1>totalOnes){ // Sliding window (if the window exceeds the totalones length so we minimize the window i.e i++)
                curr_ones-=arr[i];// Subtract the element at the ith position since i would be moving forward
                i++;
            }

            Maxcount = max(Maxcount,curr_ones);
            j++;
        }
        return totalOnes-Maxcount;
    }
};


//Time Complexity : O(n)
//Space Complexity: O(2*n)


// A Brief dry run to understand the working
/*
nums = [0, 1, 0, 1, 1, 0, 0]
temp = [0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0]
totalOnes = 3 (since there are 3 ones in nums)

Iteration 1: 
j = 0
Element: temp[0] = 0
curr_ones = 0 (no change)
Window size = j - i + 1 = 1
Condition j - i + 1 > totalOnes is false
maxcount = max(0, 0) = 0
Increment j: j = 1

Iteration 2:
 j = 1
Element: temp[1] = 1
curr_ones = 1 (increment because temp[1] is 1)
Window size = j - i + 1 = 2
Condition j - i + 1 > totalOnes is false
maxcount = max(0, 1) = 1
Increment j: j = 2

Iteration 3:
j = 2
Element: temp[2] = 0
curr_ones = 1 (no change)
Window size = j - i + 1 = 3
Condition j - i + 1 > totalOnes is false
maxcount = max(1, 1) = 1
Increment j: j = 3

Iteration 4: 
j = 3
Element: temp[3] = 1
curr_ones = 2 (increment because temp[3] is 1)
Window size = j - i + 1 = 4
Condition j - i + 1 > totalOnes is true
Slide window: i++ (i = 1)
Since temp[0] is 0, curr_ones remains 2
maxcount = max(1, 2) = 2
Increment j: j = 4

Iteration 5: 
j = 4
Element: temp[4] = 1
curr_ones = 3 (increment because temp[4] is 1)
Window size = j - i + 1 = 4
Condition j - i + 1 > totalOnes is true
Slide window: i++ (i = 2)
Since temp[1] is 1, curr_ones becomes 2
maxcount = max(2, 2) = 2
Increment j: j = 5

Iteration 6: 
j = 5
Element: temp[5] = 0
curr_ones = 2 (no change)
Window size = j - i + 1 = 4
Condition j - i + 1 > totalOnes is true
Slide window: i++ (i = 3)
Since temp[2] is 0, curr_ones remains 2
maxcount = max(2, 2) = 2
Increment j: j = 6
*/
