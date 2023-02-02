
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(auto a:nums){
            set.insert(a);
        }
        int ans =0;
        for(int i=0;i<nums.size();i++){
            int start =nums[i];
            if(set.find(start-1)!=set.end()) continue;
                while(set.find(start)!=set.end()){
                    start++;
                }

            ans=max(ans,start-nums[i]);
        }
        return ans;
    }
}; 


// Time complexity is O(n)
// Runtime 604 ms    
// Memory 49.8 MB

// Since it takes O(n) Complexity so it not an optimal Solution

// Explanation of the above code:

//1. 'class Solution '- this is the start of the class definition, a blueprint for creating objects (instances) of a certain type.

//2. int longestConsecutive(vector<int>& nums) - this is the declaration of a member function named longestConsecutive that takes a vector of integers nums as an input. The function returns an integer.

//3. unordered_set<int> set; - this line creates an unordered set named set to store the unique integers from the input vector nums.

//4. for(auto a:nums) - this line starts a for-each loop, which iterates over each element of the input vector nums. The variable a is assigned the value of each element in the vector nums.

//5. set.insert(a); - this line inserts the current element a into the unordered set set.

//6. int ans =0; - this line declares an integer variable ans and sets its initial value to 0. ans will be used to store the length of the longest consecutive sequence.

//7. for(int i=0;i<nums.size();i++) - this line starts a for loop, which iterates over the elements of the input vector nums. The variable i is used as the index of the elements in the vector. The loop continues until i is equal to the size of the vector nums.

//8. int start =nums[i]; - this line declares an integer variable start and sets its value to the ith element of the vector nums.

//9. if(set.find(start-1)!=set.end()) continue; - this line checks if the value start-1 is present in the unordered set set. If it is, the loop continues with the next iteration (as the current element start is not the start of a consecutive sequence).

//10. while(set.find(start)!=set.end()){ - this line starts a while loop that continues as long as the value start is present in the unordered set set.

//11. start++; - this line increments the value of start by 1 in each iteration of the while loop.

//12. ans=max(ans,start-nums[i]); - this line updates the value of ans to be the maximum between its current value and the length of the consecutive sequence starting from nums[i].

//13. return ans; - this line returns the final value of ans, which is the length of the longest consecutive sequence in the input vector nums.

