//Optimal
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int L1 = 1; // Tracks the current increasing sequence length
        int L2 = 0; // Tracks the previous increasing sequence length (before a break)
        for(int i =1;i<n;i++){
            if(nums[i] > nums[i-1]){ // If the sequence is still strictly increasing → simply extend the current streak
                L1++;
            }
            else{ // When the sequence breaks (nums[i] <= nums[i-1]), we store the length of the *previous* increasing sequence in L2, and reset L1 to 1 (new streak starting from current element)
                L2=L1;
                L1=1;
            }
 //Case 1: Continuous increasing sequence long enough
            if( L1 >= 2*k) return true; // If we ever reach 2*k length, that means we can easily form two consecutive subarrays of size k each within this one long stretch.


// Case 2: Two separate increasing subarrays of length k each
            if(min(L1,L2) >= k ) return true;//This happens when the previous increasing segment (L2) and the current segment (L1) both have length ≥ k.
            // Example: [7,8,9] | [2,3,4] with k=3
        }

        return false;
    }
};


// Time Complexity: O(n)
// space Complexity: O(1)
/*
INTUITION BEHIND THE LOGIC:

We are looking for two strictly increasing subarrays of length `k` each.

Instead of checking all subarrays individually (which would take O(n*k)),
we "track" increasing sequences as we move through the array.

We maintain:
    L1 → the length of the current strictly increasing sequence
    L2 → the length of the previous increasing sequence (just before a drop)

At each step:
- If the current element continues the increasing trend → increment L1.
- If the sequence breaks (nums[i] <= nums[i-1]):
    - Save the previous sequence length in L2.
    - Reset L1 = 1 (start counting a new increasing sequence).

Now we check two conditions:

I.) **L1 >= 2*k**
   → Means there’s one continuous increasing segment long enough to contain
     two k-sized subarrays back-to-back (e.g., [1,2,3,4,5,6] for k=3).

II.) **min(L1, L2) >= k**
   → Means the last two sequences (before and after the break)
     are both individually long enough (e.g., [7,8,9] and [2,3,4]).

Once either condition is met, we can immediately return `true`
since the problem only asks whether it’s *possible*, not to list them.

---
WHY WE NEED BOTH L1 AND L2:

- L1 alone tells us about the current streak.
- But when the sequence breaks, we might still have a valid pair like:
    [7,8,9] ↓ break ↓ [2,3,4]
  So, we store the old streak length in L2 before resetting.

If we only kept L1, we’d lose track of what came before the break.

---
DRY RUN:

nums = [2,5,7,8,9,2,3,4,3,1], k = 3

Step by step:
- [2,5,7,8,9] → L1 = 5
- Break at (9→2) → L2 = 5, L1 = 1
- [2,3,4] → L1 = 3, L2 = 5
- min(L1, L2) = 3 ≥ k → return true

So the valid increasing subarrays are [7,8,9] and [2,3,4].

---
*/