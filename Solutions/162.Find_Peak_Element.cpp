class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        // Edge cases:
        if (n == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        int low = 1, high = n - 2;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            // If nums[mid] is the peak:
            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
                return mid;

            // If we are in the left, that is if the previous element is less than mid element so we know peak is in the right half so we eliminate the left search space
            if (nums[mid] > nums[mid - 1])
                low = mid + 1;

            // If we are in the right,
            else
                high = mid - 1;
        }
        // Dummy return statement
        return -1;
    }
};