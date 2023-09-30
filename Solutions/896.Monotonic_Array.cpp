class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increasing = true;
        bool decreasing = true;

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] > nums[i - 1]) {
            decreasing = false;
        } else if (nums[i] < nums[i - 1]) {
            increasing = false;
        }

        // If neither increasing nor decreasing, the array is not monotonic
        if (!increasing && !decreasing) {
            return false;
        }
    }

    return true;
        
    }
};

// basically it checks at a time if the current element is greater than the last element if it is we update the decreasing variable to false (if the it is false then the array is not monotonic decresing)

// Else we check if the current element is less than the previous element then we update the increasing bool to false(if it is fale then it means that the array is not monotonic increasing)

// Then we check for the both if both are false we return false else we return true
