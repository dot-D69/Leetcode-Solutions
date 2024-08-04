// Brute Force
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD =1e9+7;
        vector<int> temp;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                temp.push_back(sum);
            }
        }
        sort(temp.begin(),temp.end());

        int res=0;
        for(int i=left-1;i<=right-1;i++){
            res+=temp[i];
            res%=MOD;
        }
        return res;
    }
};

// we use j=i instead of j=0 in the nested loop as we want to generate the all subarray sum
// when j=0 for i=0 it will calculate the correct subarray sum for nums = [1, 2, 3, 4].
// for i=0 sum=[1, 3, 6, 10]
// but for i =1 sum = [1, 3, 6, 10] whic is incorrect

// for j=i , the sum for i=0 will be [1, 3, 6, 10]
// for i=1 , the sum is [2, 5, 9]
// for i=2 , the sum is [3.7]

//That is why we use j=i 
