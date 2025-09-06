class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
         for (int K = 1; K <= 60; K++) {  // limit ~60 since 2^60 > 1e18
            long long value = (long long)num1 - (long long)K * num2;
            if (value < 0) return -1;
            long long min_bits = __builtin_popcountll(value);
            if (min_bits <= K && K <= value) {
                return K;
            }
        }
        return -1;
    }
};


/*

We want to find the smallest integer K such that:

num1 - K * num2 = value

And the following conditions hold:
i.) value >= 0 (cannot be negative).
ii.) K ≤ value (feasibility constraint).

The number of set bits (1s) in the binary representation of value ≤ K.
If no such K exists, return -1.

***********************************************************************************************

Where does num1 - K*num2 come from?

We want to make num1 = 0 using exactly K operations.
In each operation, we can:

Subtract num2
Split the remaining number into powers of 2

Let's see how we got there:

We want to reduce num1 to 0 in exactly K operations.
In each operation we subtract:
    (2^i + num2)  (where ij​≥0 is some power of two we choose)

    Step 1 – Write operations explicitly
    Operation 1:  num1(1) = num1 - (2^i1 + num2)
    Operation 2: num1(2) = num1(1) - (2^i2 + num2) (Here we can substitute num1(1) from previous)
    so num1(2) = [num1 - (2^i1 + num2)] - (2^i2 + num2)
    Operation 3:num1(3) = num1(2) - (2^i3 + num2) (similarly here we substitue num1(2) from previous so )
    so num1(3) = [num1 - (2^i1 + num2) - (2^i2 + num2)] - (2^i3 + num2) 

    We also write num1(3) as = num1 - (2^i1+2^i2+2^i3) - 3*num2
    We can then write num1(4) as  num1 - (2^i1+2^i2+2^i3+2^i4) - 4*num2
    .
    .
    .
    so let's say after K operations we are able to get  0
    Operation K: 0 = num1- (2^i1+2^i2+2^i3+2^i4...2^ik) - K*num2

    So we can write this as : num1-k*num2 = (2^i1+2^i2+2^i3+2^i4...2^ik) 
                              [num1-k*num2  =  sum of K powers of 2] Now this is our eqaution
                        
    As the equation tranform our question into :
                [For  given num1 and mum2 and operation count k , we have to express them in sum of k powers  of 2]

So if we want to get  num1 as 0 , we want to find K (no. operations) , so that num1-K*num2 can be expressed in sum of powers of 2

From here we put K for every value and when it satisfy the following condition:
                                                            i.) value >= 0 (cannot be negative).
                                                            ii.) K ≤ value (feasibility constraint).

WE have found our K (no . of operations)  after which num1 will become 0



*********************************************************************************************

The code is like a searcher:
--> It tries every possible K (from 1 to 60).
--> For each K, it subtracts K * num2 from num1.
--> If what’s left (value) can be represented with at most K powers of two, and K is feasible, then we found the answer.
--> If we never find such a K, return -1.


**********************************************************************************************************************

Key Details

1. ) Why loop only to 60?
Because 2^60 is already bigger than 1e18. Beyond that, any value would blow past problem limits, so no need to check further.

2.)What’s __builtin_popcountll(value)?
Built-in GCC function: counts how many bits are 1 in value.
Example: value = 13 → binary 1101 → 3 ones.
This tells us the minimum number of summands of powers of 2 needed to represent value.

3.)Condition check:
min_bits ≤ K → means it’s possible to split value into at most K parts.
K ≤ value → sanity condition (you can’t have more parts than the number itself).

****************************************************************************************************

DRY RUN: 
num1 = 20, num2 = 3

Step 1: K = 1

value = 20 - 1*3 = 17
Binary(17) = 10001 → min_bits = 2

Check:
min_bits ≤ K → 2 ≤ 1 
Not valid.

Step 2: K = 2

value = 20 - 2*3 = 14
Binary(14) = 1110 → min_bits = 3

Check:
3 ≤ 2 
Not valid.

Step 3: K = 3

value = 20 - 3*3 = 11
Binary(11) = 1011 → min_bits = 3

Check:
min_bits ≤ K → 3 ≤ 3 
K ≤ value → 3 ≤ 11 

Both conditions hold!
So we return K = 3.

-------------------------------------------

DRY RUN:
num1 = 5, num2 = 2

Step 1: K = 1

Compute value = 5 - 1*2 = 3.
Binary of 3 = 11, so min_bits = 2.

Now check conditions:
min_bits ≤ K → 2 ≤ 1  (fails).
So K = 1 doesn’t work. Move ahead.

Step 2: K = 2

Compute value = 5 - 2*2 = 1.
Binary of 1 = 1, so min_bits = 1.

Check conditions:
min_bits ≤ K → 1 ≤ 2 .
K ≤ value → 2 ≤ 1  (fails).
Close, but still invalid.

Step 3: K = 3

Compute value = 5 - 3*2 = -1.

Since value < 0, we stop immediately.
The loop exits and returns -1.

*/