class Solution {
public:
    bool isValid(vector<int>& nums,int s, int e,int k){
        while(s<e && s + 1 < nums.size()){
            if(nums[s]>=nums[s+1]) return false;
            s++;
        }
        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        for(int i = 0;i+2*k<=nums.size();i++){
            int j = i+k;
            if(isValid(nums,i,i+k-1,k) && isValid(nums,j,j+k-1,k)){
                return true;
            }
        }
        return false;
    }
};

//Time complexity: O(n⋅k)
//Each isValid call checks k elements → O(k)  You do that for roughly n starting indices → O(n·k) total.
//Space Complexity: O(1)

/*

We’re checking two subarrays, both of length k, one after another.
first subarray = i .... i+k-1
second subarray = i+k .... i+k+k-1 ==> i+k .... i+2k-1

Now, for both to exist fully inside the array,
the last index we touch — which is i + 2*k - 1 —> must still be less than n.

So the condition becomes:
i + 2*k - 1 < n
If we simplify that:
i + 2*k <= n
This ensures there is enough room for two full subarrays of length k.


*/