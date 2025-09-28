class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n =nums.size();
        sort(nums.begin(),nums.end());

        for(int i = n-3;i>=0;i--){
            if(nums[i]+nums[i+1]>nums[i+2]){
                return nums[i]+nums[i+1]+nums[i+2];
            }
        }
        return 0;
    }
};


/**
 * Explanation:
 * We first sort the array of side lengths in non-decreasing order.
 * Then, we iterate through the sorted array from the end, checking for the largest valid triangle.
 * Valid triangle condition: For three sides a, b, c (where a ≤ b ≤ c), they can form a triangle if a + b > c and b + c > a and c + a > b.
 * Since we are iterating from the largest side, we only need to check if the sum of the two smaller sides is greater than the largest side.
 * If we find a valid triangle, we return its perimeter.
 * If no valid triangle is found, we return 0.
 * Time Complexity: O(n log n) due to sorting.
 * Space Complexity: O(1) if we ignore the input storage.
 * This solution efficiently finds the largest perimeter of a triangle that can be formed with the given side lengths.
 * The approach ensures that we always consider the largest possible sides first, maximizing the perimeter.
 * This solution is optimal for the problem constraints and effectively handles edge cases.
 * The use of sorting simplifies the triangle inequality check, making the implementation straightforward.
 * Sorting is a key stap as we dontt need to check all combinations, just the largest three sides in sorted order.
 * 
 * 
 * DRY RUN CODE
 * Input: nums = [2,1,2]
 * Output: 5
 * Explanation: The valid triangle with the largest perimeter is formed by the sides 2, 2, and 1.
 * The perimeter is 2 + 2 + 1 = 5.
 * The function sorts the array to [1, 2, 2].
 * It then checks the triplet (2, 2, 1) and finds that 2 + 2 > 1, confirming a valid triangle.
 * The function returns the perimeter 5.
 * This demonstrates the function's ability to correctly identify and calculate the largest perimeter of a valid triangle.
 * 
 * [1,2,1,10]
 * Output: 0
 * Explanation: No valid triangle can be formed with the given side lengths.
 * The function sorts the array to [1, 1, 2, 10].
 * It checks the triplet (10, 2, 1) and finds that 1 + 2 is not greater than 10, so it cannot form a triangle.
 * The function continues checking other triplets but finds no valid combinations.
 * Finally, it returns 0, indicating that no valid triangle can be formed.
 */