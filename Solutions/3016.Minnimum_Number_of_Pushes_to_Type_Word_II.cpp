class Solution {
public:
    int minimumPushes(string word) {
        vector<int>arr(26);
        for(auto i:word){
            arr[i-'a']++; //This line increments the count of the character i in the arr vector.For example, if i is 'b', i - 'a' evaluates to 1, which is the index for 'b' in the vector. so it increases the count at the index of 'b' i.e 1
        }
        sort(arr.rbegin(),arr.rend()); // sort the arr in descending order
        int total =0;
        for(int i=0;i<26;i++){
            total+=(arr[i]*(i/8 + 1));
        }
        return total;
        
    }
};

// [0,0,0,......,4,4,4] for the string "xyzxyzxyzxyz" the arr is like this
// we sort it in  descending order  [4,4,4,0,0,....,0,0,0]
// now we can get the minimum number of clicks to get the desired string
// To get the total we do :
/* Iteration 0 (i = 0):

arr[0] = 4
Weight: 0 / 8 + 1 = 1
Contribution: 4 * 1 = 4
Update total: total = 0 + 4 = 4
Iteration 1 (i = 1):

arr[1] = 4
Weight: 1 / 8 + 1 = 1
Contribution: 4 * 1 = 4
Update total: total = 4 + 4 = 8
Iteration 2 (i = 2):

arr[2] = 4
Weight: 2 / 8 + 1 = 1
Contribution: 4 * 1 = 4
Update total: total = 8 + 4 = 12
Iteration 3 to 25 (i = 3 to i = 25):

All remaining arr[i] values are 0, so they do not contribute to the total.
Total remains 12.
Final Total
After iterating through the entire array, the final total is:

Total = 12
*/
