class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;              // to store the number of good pairs
        vector<int> freq(101, 0); // create an array freq of size 101  as given consdtraint is 1<=nums[i]<=100

        for (int i = 0; i < n; i++)
        {
            freq[nums[i]]++; // count the freq of all the elements of the array nums
        }

        for (int i = 1; i <= 100; i++)
        {
            ans += (freq[i] * (freq[i] - 1)) / 2; // to calculate the number of good pairs we use the formula (n*(n-1))/2 and the ans
        }
        return ans;
    }
};