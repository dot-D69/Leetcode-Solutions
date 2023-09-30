class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int index = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                index = i;
                break;
            }
        }
        // Edge case that is when the given permutation is the last so the index would remain -1 and hence to get the next permutation we just have to reverse
        if (index == -1)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            for (int i = n - 1; i >= index; i--)
            {
                if (nums[i] > nums[index])
                {
                    swap(nums[i], nums[index]);
                    break;
                }
            }

            reverse(nums.begin() + index + 1, nums.end());
        }
    }
};