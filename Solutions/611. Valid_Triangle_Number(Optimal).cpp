// Optimal Approach
//Time Complexity: O(n^2)
//We use the help of two pointers and sorting instead of binary Search


class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return 0; // As we need atleast three sides to form a triangle;

        sort(nums.begin(),nums.end()); // crucial: sorting makes the array non-decreasing: nums[0] <= nums[1] <= ... <= nums[n-1]. This order allows monotonic reasoning about sums.
        int count =0;

//iterate k from the end downwards; treat nums[k] as the largest side c. We start at k=n-1 (largest element) and go down until k=2 (smallest index that allows two smaller elements) as we need at least 3 elements for a valid triangle.
        for(int k = n-1;k>=2;k--){
//we will search for pairs (i, j) with 0 <= i < j < k such that nums[i] + nums[j] > nums[k]. Start with the smallest possible i and the largest possible j (just left of k).
            int i=0;
            int j = k-1;

            while(i<j){
                if(nums[i]+nums[j]>nums[k]){
                    count+= (j-i);
                    j--;
                }
                else{
                    i++;
                }
            }
        }
        return count;
    }
};

/*
Quick summary

The goal: count (unordered) triples (a,b,c) from nums that can form a triangle.
Key fact (triangle inequality): for sides a,b,c, we need all three:
a + b > c, b + c > a, c + a > b.
After sorting the array ascending and picking c as the largest of the three (index k), we only need to check a + b > c. Sorting gives monotonicity we can exploit with two pointers to count many valid pairs at once, reducing O(n³) brute force to O(n²).
*/


//###################################################################################

/*

Why sort and why only check a + b > c

Sorting allows us to make nums[k] the largest side in any triple (i,j,k) with i < j < k. If nums is sorted and i<j<k then nums[i] <= nums[j] <= nums[k]. For such a triple, the triangle inequalities reduce to just nums[i] + nums[j] > nums[k]. Why?

Since nums[k] is the largest side, if the two smaller sides sum to more than nums[k], the other two inequalities are automatically satisfied:

nums[i] + nums[k] > nums[j]: because nums[k] >= nums[j] and nums[i] + nums[k] >= nums[i] + nums[j] > nums[k] >= nums[j] → so a + c > b.

nums[j] + nums[k] > nums[i]: obviously true because nums[j] + nums[k] >= nums[k] >= nums[i]. (Strictness: if a+b>c holds, b+c>a can't be equality case unless all zeros — but a+b>c rules that out.)

Therefore checking a + b > c (with sorted a <= b <= c) is necessary and sufficient for a valid triangle.


*/


//###################################################################################

/*

How we derived the two-pointer idea (thought process)

Brute force: check all triples (i,j,k) with i<j<k → O(n³).

Observation 1: After sorting and fixing k (largest side), the condition is nums[i] + nums[j] > nums[k]. So for each k we need count of pairs (i,j) in [0..k-1] with i<j and sum > nums[k].

Observation 2 (monotonicity): In a sorted array, if you fix j, then as i increases, nums[i] increases, so nums[i] + nums[j] is monotonic in i. Similarly, if you fix i, as j decreases, the sum decreases. This monotonic behavior is perfect for two pointers.

Two-pointer trick: set i to start of range, j to end (k-1). If nums[i] + nums[j] > nums[k], then because nums[i'] >= nums[i] for any i' in (i..j-1), all those i' also satisfy nums[i'] + nums[j] > nums[k]. So count them all: j - i. Then you move j left to try other pairs. If nums[i] + nums[j] <= nums[k], then even the smallest i fails with this j — decreasing j will only make sum smaller — so you must increase i.

This gives O(k) time per k in the while loop; summing over k yields O(n²).

*/

//###################################################################################

/*
Why count += (j - i) when nums[i] + nums[j] > nums[k] — proof

Given sorted array nums and indices i < i' < j:
nums[i'] >= nums[i] because it's sorted.
So nums[i'] + nums[j] >= nums[i] + nums[j] > nums[k].
Therefore for fixed j, every i' in [i, j-1] forms a valid pair with j.
The number of such i' is j - i. We count them and then decrement j (we've exhausted pairs that use this j).


Why j-- (after counting) and i++ (in the else)

j-- after counting: we counted all pairs with this j and i..(j-1) — no need to examine those again. To find more pairs, we must try a smaller j (a smaller second side).

i++ in the else: if even the smallest i (current i) combined with current j produces nums[i] + nums[j] <= nums[k], then for the same j any i' < i would be smaller sum (but there are none smaller than i). Decreasing j makes the sum smaller, so the only way to possibly make the sum exceed nums[k] is to increase i (choose a larger nums[i]). Thus i++.

This choice guarantees correctness and no double counting:

We only count pairs (i', j) exactly once when we hit j with the smallest i that makes the inequality true.

Pairs are never revisited because either j is decreased after counting or i increased when current pair fails.
*/

//###################################################################################

/*
DRY RUN:

Input: nums = [2, 2, 3, 4]
Sorted (already): [2, 2, 3, 4]. n = 4. count = 0.

We will enumerate k from 3 down to 2.

k = 3, nums[k] = 4:

i = 0 (nums[i]=2), j = 2 (nums[j]=3)

nums[i] + nums[j] = 2 + 3 = 5 > 4

So count += (j - i) = 2 - 0 = 2 → count = 2. (These two pairs are (i=0,j=2) and (i=1,j=2).)

j-- → j = 1.

Now i = 0, j = 1:

nums[0] + nums[1] = 2 + 2 = 4 → not greater than 4.

So i++ → i = 1. Now i == j, stop while.
End of k=3 loop. Triangles counted: (indices) (0,2,3) and (1,2,3) → sides (2,3,4) twice.

k = 2, nums[k] = 3:

i = 0, j = 1

nums[0] + nums[1] = 2 + 2 = 4 > 3

count += (1 - 0) = 1 → count = 3.

j-- → j = 0. Now i >= j, stop.
End k=2.

Final count = 3. The valid triangles are (by indices): (0,1,2) -> [2,2,3], (0,2,3) -> [2,3,4], (1,2,3) -> [2,3,4].

*/