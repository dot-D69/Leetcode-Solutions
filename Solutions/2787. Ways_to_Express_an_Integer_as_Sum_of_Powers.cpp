class Solution {
public:
    int MOD =1e9+7;
    vector<vector<int>> t;// cache for memoization, since normal recursion gives TLE

    int solve(int num,int n , int x){
        if(n==0){
            return 1;
        }
        
        int numPower = pow(num,x);
        if(numPower>n){
            return 0;
        }

        if(t[n][num] != -1){
            return t[n][num];
        }

        int take = solve(num+1,n-numPower,x);
        int skip = solve(num+1,n,x);

        return t[n][num] =  (take+skip)%MOD;

    }
    int numberOfWays(int n, int x) {
        t.resize(301,vector<int>(301,-1));
        return solve(1,n,x);
    }
};



/*


We want to find how many ways we can write 4 as a sum of unique numbers raised to the 1st power (just normal unique numbers).

We start by trying the smallest number num = 1.

For each number, we have two choices:

Take it: Include num^x in our sum and reduce the target sum n.

Skip it: Ignore num and move to the next number.

Start at (num=1, n=4):

Can we take 1?
Yes, because 1 ≤ 4.
After taking 1, remaining sum is 4 - 1 = 3, now try next number (num=2, n=3).

Or, can we skip 1 and try (num=2, n=4) directly?

At (num=2, n=3) (after taking 1):

Take 2?
Yes, 2 ≤ 3.
Remaining sum: 3 - 2 = 1. Next: (num=3, n=1).

Skip 2?
Try (num=3, n=3).

At (num=3, n=1):

Take 3?
No, because 3 > 1 (can't take). So 0 ways here.

Skip 3?
Same (num=4, n=1).

At (num=3, n=3):

Take 3?
Yes, 3 ≤ 3. Remaining sum 3 - 3 = 0.
Found a valid way! Return 1.

Skip 3?
(num=4, n=3).

At (num=4, n=3):

Take 4?
No, 4 > 3, 0 ways.

Skip 4?
(num=5, n=3), which is invalid as 5 > max n, 0 ways.

Now, back to skipping 1: (num=2, n=4):

Take 2?
Yes, (num=3, n=2).

Skip 2?
(num=3, n=4).

At (num=3, n=2):

Take 3?
No, 3 > 2, 0 ways.

Skip 3?
(num=4, n=2), which will also fail later.

At (num=3, n=4):

Take 3?
Yes, (num=4, n=1).

Skip 3?
(num=4, n=4).

At (num=4, n=1):

Take 4? No, 4 > 1, 0 ways.

Skip 4? (num=5, n=1), invalid → 0 ways.

At (num=4, n=4):

Take 4?
Yes, (num=5, n=0).
Valid way found! Return 1.

Skip 4?
(num=5, n=4), invalid → 0 ways.

Final result:
From taking 1, total ways = 1

From skipping 1, total ways = 1

So total ways = 1 + 1 = 2


The RECURSION TREE MAY LOOK LIKE THIS:

                                (1,4)
                              /        \
                    take (2,3)          skip (2,4)
                    /         \          /        \
           take (3,1)       skip(3,3) take(3,2)   skip(3,4)
            /      \         /     \    /     \      /     \
       take(4,-) skip(4,-) take(4,0) skip(4,3) take(4,1) skip(4,4)
        (X)      (X)        (✔)       (X)      (X)      /      \
                                               take(5,0) skip(5,4)
                                                  (✔)        (X)

*/