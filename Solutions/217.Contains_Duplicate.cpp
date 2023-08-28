class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> freq;
        for(auto i : nums){
            freq[i]++;
            if(freq[i]>1){
                return true;
                break;
            }
        }   
        return false;
    }
};

/*
Here's how it works:

When you encounter a new element nums[i], freq[i] is evaluated. If arr[i] is not already a key in the map freq, it will be automatically inserted into the map with a default-initialized value (0 in the case of an int).

After inserting or finding the key arr[i], you use the post-increment operator (++) to increment the associated value by one.

This process repeats for each element of the vector nums.

The line if(freq[i]==2) returns the value associated with the key i.e. it will return the frequency for i 
*/