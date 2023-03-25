class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        int a=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                swap(nums[a],nums[i]);
                a++;
            }

        }
        return nums;
    }
};


// Time Complexity - O(n)


// EXPLANATION

//1. int n = nums.size(); - This line declares an integer variable n and sets its value to the size of the input vector nums.

//2. vector<int> arr(n); - This line declares a new vector of integers named arr with the same size as the input vector nums.

//3. int a=0; - This line declares an integer variable a and sets its initial value to 0. This variable will be used to keep track of the index of the next even number in the input vector nums.

//4. for(int i=0;i<n;i++) - This line starts a for loop, which iterates over the elements of the input vector nums. The variable i is used as the index of the elements in the vector. The loop continues until i is equal to the size of the vector nums.

//5. if(nums[i]%2==0) - This line checks if the current element (nums[i]) is an even number. If it is, the code inside the curly braces is executed.

//6. swap(nums[a],nums[i]); - This line swaps the current element (nums[i]) with the next even number in the input vector (nums[a]), which is indicated by the variable a. This effectively moves all even numbers to the front of the vector.

//7. a++; - This line increments the value of a by 1, indicating that the next even number in the input vector has been found.

//8. return nums; - This line returns the modified input vector nums, which now has all even numbers in the front and odd numbers in the back.