// Optimal
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        if (n <= 1) {
            return n;
        }
        
        int left = 0;
        for (int right = 1; right < n; right++) {
            if (nums[right] != nums[left]) {
                left++;
                nums[left] = nums[right];
            }
        }
        
        return left + 1;
    }
};

/*

Check the size of the nums array, denoted as n:

If n is less than or equal to 1, return n immediately because there are no duplicates to remove, and the array is already non-decreasing.
Initialize two pointers, left and right, both initially pointing to the first element of the array (left = 0, right = 1).

Start a loop that iterates through the array from the second element (right = 1) to the end of the array (right < n).

Inside the loop:

Check if nums[right] is not equal to nums[left], indicating that a new unique element is encountered.
If they are not equal:
Increment the left pointer by 1 to move to the next position in the array.
Update nums[left] with the value of nums[right]. This effectively removes duplicates by overwriting them with the new unique element.
Continue this process until the right pointer reaches the end of the array.

Return left + 1 as the size of the modified array. The left pointer now points to the last unique element, and adding 1 gives you the count of unique elements.

*/