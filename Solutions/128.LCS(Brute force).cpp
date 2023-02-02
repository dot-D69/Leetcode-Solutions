//  BRUTE FORCE METHOD

/*
!!!!! Don't Use this Code as it will Result in TLE(Time Limit Exceeded)  Because
The time complexity of the code is O(n^2), where n is the size of the input vector nums. This is because the findNum method is called in a loop, and the time complexity of findNum is O(n) since it performs a linear search on the vector. The total time complexity becomes O(n^2) due to the nested loop structure.

*/

class Solution {
public:
bool findNum(int n,vector<int>& nums){
    for(auto a: nums){        //Returns all the elements of the given arr one by one
        if(a==n){
            return true;
        }
    }
    return false;
}
    int longestConsecutive(vector<int>& nums) {
        int ans =0;
        int s =nums.size();
        for(int i =0;i<s;i++){
            int start =nums[i];
            while(findNum(start,nums)){
                start++;
            }
            ans = max(ans,start-nums[i]);

        }
        return ans;   
    }
};



// Explaination 

// 1.The code defines two functions, findNum and longestConsecutive.

// 2.The findNum function takes an integer n and a vector of integers nums as input. It returns true if the integer n is in the vector nums, and false if it is not

// 3.The longestConsecutive function takes a vector of integers nums as input and returns the length of the longest sequence of consecutive integers in that vector.

// 4.Inside the longestConsecutive function, the code first initializes a variable ans to store the length of the longest sequence.

// 5.Then, it uses a for loop to iterate over all the elements in the vector nums.

// 6.In each iteration, it sets a variable start to the current element of the vector.

// 7.Then, it enters a while loop. The loop continues as long as the findNum function returns true for the value of start.

// 8.In each iteration of the while loop, the code increments the value of start by 1.

// 9.Once the findNum function returns false, meaning the current value of start is not in the nums vector, the while loop stops.

// 10.The code then updates the value of ans to be the maximum of ans and start - nums[i]. This represents the length of the longest sequence of consecutive integers that starts at nums[i].

// 11.The for loop then continues to the next iteration and repeats these steps until all elements in the nums vector are processed.

// 12.Finally, the code returns the value of ans which is the length of the longest sequence of consecutive integers in the nums vector.