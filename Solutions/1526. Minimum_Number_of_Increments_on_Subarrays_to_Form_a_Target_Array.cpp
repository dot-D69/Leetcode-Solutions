class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        long long res = 0; 
        int curr = 0;
        int prev = 0;

        for(int i = 0;i<n;i++){
            curr = target[i]-0;
            if(curr>prev){
                res+=curr-prev;
            }
            prev = curr;
        }
        return res;
    }
};

// /Time Complextiy: O(n)
// Space Complexity : O(1)


/*This proble is an easier version of the problem 3229 , So for the full explanation please check for the problem 3229 */