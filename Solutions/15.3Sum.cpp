// Optimal Solution (two pointer approach)
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // this is to check if the previous element of i is same as curr element then move also if the the i si at the first element sot here will be no prevous element so  to check that i>0
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)
                {
                    j++; // since the array is sorted and if we get negative so we need to increase thus we move j so as to get 0
                }
                else if (sum > 0)
                {
                    k--; //  since the array is sorted and if we get more than 0  so we need to decrease the k so as to get 0
                }
                else
                { // this means the sum is zero and we have found our triplet
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    res.push_back(temp);
                    j++; // since we will not again start from the j and k that we have just pushed into the res so we move them one ahead
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }

        return res;
    }
};
