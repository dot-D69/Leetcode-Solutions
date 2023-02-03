#include<bits/stdc++.h>
using namespace std;

    int majorityelement(vector<int>& nums){
        int n = nums.size();
        unordered_map<int,int> map;
        for(auto a:nums){
            map[a]++;
            if(map[a]>n/2){
                return a;
            }
        }
        return -1;
    }


// The time complexity of this code is O(n) as it iterates through the whole array only once.
// Runtime 26 ms
// Memory 19.6 MB







// Explanation:

// 1.int n = nums.size();
// This line declares an integer variable 'n' and stores the size of the vector 'nums'.

//2. unordered_map<int,int> map;
// This line declares an unordered_map with key as integer and value as integer.

//3. for(auto a:nums)
// This line starts a for-each loop that iterates through each element in the 'nums' vector.

//4. map[a]++;
// This line increments the value associated with key 'a' in the map.

//5. if(map[a]>n/2){
// This line checks if the value associated with key 'a' in the map is greater than n/2. If it is true then it is a majority element.

//6. return a;
// This line returns the majority element.

//7. return -1;
// This line returns -1 if no majority element is found.

