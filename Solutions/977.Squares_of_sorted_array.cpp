class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int i =0 , j=n-1;
        int k = n-1;
        while(j>=i){
            if(abs(nums[j])>=abs(nums[i])){
                res[k]=nums[j]*nums[j];
                j--;
                k--;
            }
            else{
                res[k]=nums[i]*nums[i];
                i++;
                k--;
            }
            
        }

        return res;
    }
};


// Time Complexity O(n)


// EXPLANATION

//1. int n = nums.size(); - This line initializes an integer variable n with the size of the input vector nums.

//2. vector<int> res(n); - This line declares a new vector of integers named res with the size of n, which is the same as the size of the input vector nums.

//3. int i = 0, j = n - 1; - This line initializes two integer variables i and j, which will be used as indices to traverse the input vector nums. i is initialized to 0, and j is initialized to n-1.

//4. int k = n - 1; - This line initializes an integer variable k with the value of n-1. k will be used as an index to traverse the output vector res in reverse order.

//5. while(j >= i) - This line starts a while loop that will continue until the index j is less than i.

//6. if(abs(nums[j]) >= abs(nums[i])) - This line checks if the absolute value of the element at index j in the input vector nums is greater than or equal to the absolute value of the element at index i in the input vector nums. If it is, the code inside the curly braces is executed.

//7. res[k] = nums[j] * nums[j]; - This line assigns the square of the element at index j in the input vector nums to the element at index k in the output vector res.

//8. j--; k--; - These two lines decrement the indices j and k by 1.

//9. else - This line is executed if the condition in line 7 is not true.

//10. res[k] = nums[i] * nums[i]; - This line assigns the square of the element at index i in the input vector nums to the element at index k in the output vector res.

//11. i++; k--; - These two lines increment the index i by 1 and decrement the index k by 1.

//12. return res; - This line returns the output vector res, which contains the squares of the elements in the input vector nums sorted in non-decreasing order.