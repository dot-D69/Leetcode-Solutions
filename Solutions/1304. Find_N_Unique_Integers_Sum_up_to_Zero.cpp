//brute Force
// Approach 1: O(n) time and O(n) space
// 
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        for(int i=1;i<=n/2;i++){ // we go through the loop and pairs of number +i and -i
            res.push_back(i);
            res.push_back(-i);
        }
        //If the n is odd then we add a zero at end to balance out
        if(n%2!=0){ 
        res.push_back(0);
        }
        
    return res;
    }
};
// Dry Run
// n=5
// We will go through the loop for i=1 and i=2 since n/2=2 
// we add 1,-1,2,-2 to the result vector
// res = [1,-1,2,-2]
// n is odd so we add a 0 at end
// res = [1,-1,2,-2,0]
// return res

// n=4
// We will go through the loop for i=1 and i=2 since n/2=2
// we add 1,-1,2,-2 to the result vector
// res = [1,-1,2,-2]
// n is even so we dont add anything at end
// return res

/*----------------------------------------------------------------------------------------------------------------------*/


// Approach 2: O(n) time and O(n) space

vector<int> sumZero(int n) {
    vector<int> res;
    res.reserve(n);
    int sum = 0;
    for (int i = 1; i < n; i++) {
        res.push_back(i);
        sum += i;
    }
    res.push_back(-sum);
    return res;
}

/*

in this solution for a given n.

We add 1 t n-1 numbers in the vector
and the last element is the negative of sum of all numbers from (1 to n-1)

for example 
n =5
 add 1 to n-1  = [1,2,3,4]
 sum of 1 to n-1 = n*(n-1) / 2 = 10 
 add the negative to the arr = [1,2,3,4,-10]
 This way the whole sum will always be zero


*/
