class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum = 0;
        int max_neg = INT_MIN;
        unordered_set<int> s;

        for(int &n:nums){
            if(n<=0){
                max_neg= max(max_neg, n);
            }
            else{
                if(!s.count(n)){
                    sum+=n;
                    s.insert(n);
                }
            }
        }
    if(sum==0){
        return max_neg;
    }
    else{
        return sum;
    }
    }
};