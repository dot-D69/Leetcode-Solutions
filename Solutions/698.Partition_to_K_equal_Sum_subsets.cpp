class Solution {
public:
    bool get(int i, int current_bucket, int current_sum, int target_sum, int k, vector<int> &nums, vector<int> &check) {
        // Base cases
        if (current_bucket == k + 1) return true;
        if (current_sum == target_sum) {
            return get(0, current_bucket + 1, 0, target_sum, k, nums, check);
        }
        if (i >= nums.size() || current_sum > target_sum) return false;
        //
        
        if (check[i] == 1) {
            return get(i + 1, current_bucket, current_sum, target_sum, k, nums, check);
        }

        // Skip adding the element if adding it will exceed the target sum
        if (current_sum + nums[i] <= target_sum) {
            current_sum += nums[i];
            check[i] = 1;
            bool pick = get(i + 1, current_bucket, current_sum, target_sum, k, nums, check);
            if (!pick) {
                current_sum -= nums[i];
                check[i] = 0;
            }
            else return true; // Return true if a valid subset is found
        }
        
        // Pruning: Skip elements when current_sum exceeds target_sum
        while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
            i++;
        }
        return get(i + 1, current_bucket, current_sum, target_sum, k, nums, check);
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        vector<int> check(nums.size(), 0);
        int sum = 0;
        for (int x : nums) {
            sum += x;
        }
        if (sum % k != 0) return false;
        int target_sum = sum / k;

        // Sort nums in descending order
        sort(nums.rbegin(), nums.rend());

        return get(0, 1, 0, target_sum, k, nums, check);
    }
};


/*
Explanation
Using Pick or Skip method
1. Sort the array in descending order (it is not necessary but it will help in pruning)
2. If the sum of the array is not divisible by k, return false (because we cannot partition the array into k subsets with equal sum) eg. [7,3,9,3] k = 7 (sum = 22)/ 7 not divisible
3. If the sum of the array is divisible by k, then we can partition the array into k subsets with equal sum
4. First what we are doing is we create a vector to check if the current element is used or not. We initialize it with 0 (not used) for all the elements and i f we pick and element we make it 1 (used)
5. We first check if the i element is used or not, if it is ussed the we skip it and again call the function with i+1
6. then we check if adding the current element will exceed the target sum or not
7. we run a loop <=target_sum and within the loop 
            i.)check if adding the current element will exceed the target sum or not while the sum is not equl the loop will run and keep adding elements and checking for subst using Pick
            ii.)we intialize a boolean pick and call the function which return true or false if a valid subset is found or not
            iii.)if a valid subset is found we return true
            iv.)if a valid subset is not found we remove the current element and again call the function with i+1
            v.) if adding the element will exceed the target sum we do not enter the loop and call the function with i+1
8. this was the pick part of the function
9. now we move on to the skip part of the function
10. we run a loop to skip the elements which are equal to the current element because if we pick the current element we will also pick the elements which are equal to the current element and we will get the same subset
11. we call the function with i+1
12. if we reach the end of the array and we have not found a valid subset we return false
Now for base cases
1. if the current_bucket is equal to k+1 we return true because we have found k subsets with equal sum
2. if the current_sum is equal to target_sum we call the function with current_bucket+1 and current_sum = 0 because we have found a subset with equal sum and we need to find k-1 subsets with equal sum
3. if i>=nums.size() or current_sum>target_sum we return false because we have reached the end of the array or the current_sum has exceeded the target_sum

// To find the target sum we divide the sum of the array by k and store it in target_sum (it is the method to find the target sum)


*/