class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            int n = nums.size();
            vector<int> res;// result array
            int i =-1;
    
            for(int k=0;k<n;k++){
                if(nums[k]<0){
                    i = k;     //This gives us the index of the last negative number in the array.
                }
                else break;
            }
    
            int j = i+1; // Gives us the index of the first positive number in the array
    
            //Merge the array of the two parts 
    
            while(i>=0 && j<n){
                if(nums[i]*nums[i]<nums[j]*nums[j]){
                    res.push_back(nums[i]*nums[i]);
                    i--;
                }
                else{
                    res.push_back(nums[j]*nums[j]);
                    j++;
                }
            }
    
            // fill the array with the remaining elemesnts
    
            while(i>=0){
                res.push_back(nums[i]*nums[i]);
                i--;
            }
    
            while(j<n){
                res.push_back(nums[j]*nums[j]);
                j++;
            }
    
            return res;
    
        }
    };
    
    //Time Complexity: O(n)
    // Space Complexity: O(n)
    
    
    // Separate Negative and Positive, Then Merge Like MergeSort
    /*
    
    The input array nums is already sorted in non-decreasing order, like this:
    nums = [-7, -3, 0, 2, 5]
    
    Because the array is sorted:
    i.)The most negative numbers are on the left.
    ii.)The largest positive numbers are on the right.
    
    Negative part of the array (e.g., [-7, -3]) becomes sorted in decreasing order when squared:
    [-7, -3] → [49, 9]
    Positive part is already sorted when squared:
    [0, 2, 5] → [0, 4, 25]
    
    So now we have:
    
    i.)One decreasing list (from squaring the negative numbers)  [49, 9].
    ii.)One increasing list (from squaring the positive numbers) [0, 4, 25].
    
    Now we can merge these two sorted lists (one decreasing, one increasing) into a new sorted list.
    
    First we find the split point:
    nums = [-7, -3, 0, 2, 5]
                   ↑
                (first non-negative index)
    Let’s say i = 1 (last negative index = -3), and j = 2 (first non-negative = 0)
    We now walk:
    i leftward (i--)
    j rightward (j++)
    At each step, compare the square of nums[i] and nums[j] and insert the samller one into the array.
    
    Finish off whichever side has leftovers.
    */