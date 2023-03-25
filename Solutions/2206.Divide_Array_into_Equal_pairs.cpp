class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(501,0);
        for(int i =0;i<n;i++){
            freq[nums[i]]++;
        }
        for(int i =1;i<=500;i++){
            if((freq[i]%2)!=0){
                return false;
            }
        }
        return true;
    }
};


// Time complexity O(n)



// EXPLANATION

//1. int n = nums.size(); - This line initializes an integer variable n with the size of the input nums vector. This value represents the number of elements in the array.

//2. vector<int> freq(501,0); - This line initializes a vector of integers named freq with a size of 501, and sets all the values in the vector to 0. This vector will be used to store the frequency of each integer in the input nums array.

//3. for(int i =0;i<n;i++) - This line starts a for loop that iterates through each element of the input nums array. The variable i is used as an index to access each element.

//4. freq[nums[i]]++; - This line increments the value in the freq vector at the index corresponding to the integer in the nums array. This effectively counts how many times each integer appears in the nums array.

//5. for(int i =1;i<=500;i++) - This line starts another for loop that iterates through all integers from 1 to 500.

//6. if((freq[i]%2)!=0) - This line checks if the frequency of the integer at index i in the freq vector is odd.

//7. return false; - This line is executed if the condition in line 7 is true. It returns false, indicating that it is not possible to divide the input nums array into two parts with equal sums of elements.

//8. return true; - This line is executed if the for loop in line 6 completes without returning false. It returns true, indicating that it is possible to divide the input nums array into two parts with equal sums of elements.