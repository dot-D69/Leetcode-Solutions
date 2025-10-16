class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> mp;

        for(int i : nums){
            int rem = ((i%value)+value)%value;

            mp[rem]++;
        }

        int MEX = 0;
        while(mp[(MEX%value)] > 0){
            mp[(MEX%value)]--;

            MEX++;
        }

        return MEX;
    }
};


//Time Complexity : O(n)
//Space Complexity : O(n)

/*

We want the maximum MEX (smallest non-negative integer missing from the array) after we can add or subtract value any number of times from any element.

-----------------------------------------------------------------------------
Key idea behind the solution

If you take any number i, and keep adding or subtracting value to it,
you’ll only ever reach numbers that have the same remainder when divided by value.

So, every number belongs to a “remainder group” — defined by:

remainder = i % value


Example:
If value = 3,
then numbers ... -3, 0, 3, 6, 9 ... all belong to remainder 0.
Numbers 1, 4, 7, 10 ... belong to remainder 1.
Numbers 2, 5, 8, 11 ... belong to remainder 2.

Hence, we only care about how many numbers we have for each remainder group.

-------------------------------------------------------------------------------
Step 1: Build frequency of remainders
unordered_map<int,int> mp;

We’re creating a hash map (like a frequency table).

It will store:
remainder → how many times this remainder occurs.

Example:
if value = 3 and nums = [1, 4, 7, 2, 5],
then remainders = [1, 1, 1, 2, 2] →
so mp = {1:3, 2:2}

Q.) Why not use set?**

A set only stores unique values.
But we need to know how many times a remainder occurs.

Because when we start calculating the MEX,
we might "use up" a remainder multiple times.

Example:
nums = [1, 4, 7], value = 3
remainders = [1, 1, 1]

We can form numbers 1, 4, 7 → all have remainder 1.

So:
The first remainder 1 helps us make MEX = 0
The second remainder 1 helps MEX = 1
The third remainder 1 helps MEX = 2

If we used a set, we’d only know that 1 exists once — not that it appears 3 times!
That would make us stop too early and give the wrong MEX.
Hence we need a map (with counts).

-----------------------------------------------------------------------------1

Step 2: : Handle negative numbers safely***

int rem = ((i%value)+value)%value;

Q.)Why not just i % value?

Because % in C++ can give negative remainders if i is negative.

Example:
i = -1, value = 3
-1 % 3 = -1   (not 2!)


We actually want remainder in range [0, value-1].

So we fix it:

rem = ((i % value) + value) % value;


Let’s test:

i	value	i % value	((i % value)+value)%value	Correct remainder
5	 3	         2	                 2	                ✅ 2
-1	 3	        -1	                 2	                ✅ 2
-4	 3	        -1	                 2	                ✅ 2

So this trick ensures the remainder is always positive and within range [0, value-1].

----------------------------------------------------------------------------

Step 3: Finding the MEX
// int MEX = 0;
// while(mp[(MEX%value)] > 0){
//     mp[(MEX%value)]--;
//     MEX++;
// }
// return MEX;


Let’s explain this slowly:

MEX (Minimum EXcluded number)
It’s the smallest non-negative integer that can’t be represented.

Loop idea:

We start with MEX = 0 and check:

Do we have a remainder that can represent this number?

To represent any number MEX,
we need at least one number in our array whose remainder = MEX % value.
If we do → we can form this number, so we consume one occurrence (-- count).
Then move to next number (MEX++).
We keep doing this until we find a MEX where the remainder group is empty (no count left).
That’s the answer.



*/


/*
DRY RUN

nums = [1, -10, 7, 13, 6, 8], value = 5

Step 1: Compute remainders
num	i % 5	((i%5)+5)%5	remainder
1	1	(1+5)%5 = 1	      1
-10	0	(0+5)%5 = 0	      0
7	2	(2+5)%5 = 2	      2
13	3	(3+5)%5 = 3	      3
6	1	(1+5)%5 = 1	      1
8	3	(3+5)%5 = 3	      3

 Final remainders = [1, 0, 2, 3, 1, 3]

Step 2: Group numbers by remainder (build the map)
Remainder 0 → [ -10 ]         (count = 1)
Remainder 1 → [ 1, 6 ]        (count = 2)
Remainder 2 → [ 7 ]           (count = 1)
Remainder 3 → [ 13, 8 ]       (count = 2)

Map view:

mp = { 0:1, 1:2, 2:1, 3:2}


Step 3: Finding the MEX visually

Iteration 1
MEX = 0 → MEX % 5 = 0
Check bucket 0 → count = 1 > 0  use one count


Bucket 0 loses one 

Remainder	New Count
0	            0
1	            2
2	            1
3	            2

MEX++ → MEX = 1

Iteration 2
MEX = 1 → MEX % 5 = 1
Bucket 1 has 2 → use one count

Remainder	New Count
0	            0
1	            1
2	            1
3	            2
4	            0

MEX = 2

Iteration 3
MEX = 2 → MEX % 5 = 2
Bucket 2 has 1 → use one count

Remainder	New Count
0	            0
1	            1
2	            0
3	            2
4	            0

MEX = 3

Iteration 4
MEX = 3 → MEX % 5 = 3
Bucket 3 has 2 → use one counr

Remainder	New Count
0	            0
1	            1
2	            0
3	            1


MEX = 4

Iteration 5
MEX = 4 → MEX % 5 = 4
Bucket 4 has 0 ❌ → stop


So we cannot form 4.

Final Answer
MEX = 4


*/
