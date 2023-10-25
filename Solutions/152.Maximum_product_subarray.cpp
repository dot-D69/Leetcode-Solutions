class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int prefix = 1;
        int suffix = 1;
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            if (prefix == 0)
                prefix = 1;
            if (suffix == 0)
                suffix = 1;

            prefix = prefix * nums[i];
            suffix = suffix * nums[n - i - 1];
            maxi = max(maxi, max(prefix, suffix));
        }
        return maxi;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)

