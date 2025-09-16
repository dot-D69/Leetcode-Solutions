class Solution {
public:
    int josephus(int n, int k) {
        if (n == 1) return 0; // base case: survivor index
        return (josephus(n - 1, k) + k) % n;
    }
    int findTheWinner(int n, int k) {
       return josephus(n,k)+1;
    }
};

/*

findTheWinner(5,2)
 └─ josephus(5,2)
      └─ josephus(4,2)
           └─ josephus(3,2)
                └─ josephus(2,2)
                     └─ josephus(1,2)   <-- base case



We’ll go from deepest call (n=1) back up.

Step 1: josephus(1,2)
Base case: n == 1
Returns 0 (the only person has index 0)


Step 2: josephus(2,2)
Needs result of josephus(1,2) → got 0
Compute:
(0 + 2) % 2 = 2 % 2 = 0
Returns 0 (survivor index among [0,1])


Step 3: josephus(3,2)
Needs result of josephus(2,2) → got 0
Compute:
(0 + 2) % 3 = 2 % 3 = 2
Returns 2 (survivor index among [0,1,2])


Step 4: josephus(4,2)
Needs result of josephus(3,2) → got 2
Compute:
(2 + 2) % 4 = 4 % 4 = 0
Returns 0 (survivor index among [0,1,2,3])


Step 5: josephus(5,2)
Needs result of josephus(4,2) → got 0
Compute:
(0 + 2) % 5 = 2 % 5 = 2
Returns 2 (survivor index among [0,1,2,3,4])


Step 6: findTheWinner(5,2)
Take result 2 from josephus(5,2)
Adds 1 (convert from 0-based → 1-based):
2 + 1 = 3
Final answer = 3


People = [1,2,3,4,5]
Remove 2 → [1,3,4,5]
Remove 4 → [1,3,5]
Remove 1 → [3,5]
Remove 5 → [3]

✅ Winner = 3 → same as recursion result.

*/