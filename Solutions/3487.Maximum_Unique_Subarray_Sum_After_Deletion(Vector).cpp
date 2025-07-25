class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum = 0;
        int max_neg = INT_MIN;
        vector<int> s (101,-1);// Vector of size 101 to track seen numbers (0 to 100)

        for(int &n:nums){
            if(n<=0){
                max_neg= max(max_neg, n);  // If number is negative, track the maximum negative
            }
            else{
                if(s[n]==-1){ // If it's a positive number and not already seen
                    sum+=n;
                   s[n] = 1; // Mark as seen
                }
            }
        }
    if(sum==0){
        return max_neg;
    }
    else{
        return sum;
    }
    }
};

/*

We are doing th same thing we did in unodered set but with vector as it is mentioned that the num is in between 0 to 100

we make the vector of 100 size mark all the indexes as -1 (It will only keep track of psoitive numbers  and we also only need the positive numbers to add), when we have visited or seen an element wer mark the index as 1

If the whole array is only negative numbers like [-15,-2,-4,-8] then the sum will be -2 as we a re supposed to return the max sum and in case of negative numbers we don't want to add as -2 + -4 = -6 which smaller than -2. Therefore in case of negative numbers we only store the max negative number i.e the largest number and just return that

Below is an walk through of each of the case


 Case 1: All Numbers are Positive (No Duplicates)
\U0001f9ea Input: [1, 2, 3]
Let’s trace it line by line:

sum = 0, max_neg = INT_MIN, s is a list of 101 -1s.

We loop through the vector:

First number = 1 → It’s greater than 0 → Check if s[1] == -1 → yes →
→ Add 1 to sum → sum = 1 → Mark s[1] = 1

Next number = 2 → s[2] == -1 → Add 2 → sum = 3 → s[2] = 1

Next number = 3 → s[3] == -1 → Add 3 → sum = 6 → s[3] = 1

Done looping. sum = 6, which is not 0, so we return 6.

\U0001f3ac Case 2: All Positive Numbers with Duplicates
\U0001f9ea Input: [1, 1, 2, 2, 3]

sum = 0, max_neg = INT_MIN, s initialized.

Loop:

1 → unseen → add to sum = 1 → mark s[1] = 1

1 again → s[1] == 1 → skip

2 → unseen → add to sum = 3 → mark s[2] = 1

2 again → s[2] == 1 → skip

3 → unseen → add to sum = 6 → mark s[3] = 1

Final sum = 6 → return 6.

\U0001f3ac Case 3: All Negative Numbers
\U0001f9ea Input: [-3, -8, -1]

sum = 0, max_neg = INT_MIN, s initialized.

Loop:

-3 ≤ 0 → update max_neg = max(INT_MIN, -3) = -3

-8 → max_neg = max(-3, -8) = -3

-1 → max_neg = max(-3, -1) = -1

End loop. sum = 0, so return max_neg = -1.

\U0001f3ac Case 4: Mix of Positive and Negative
\U0001f9ea Input: [1, -1, 2, -2, 3]

sum = 0, max_neg = INT_MIN, s initialized.

Loop:

1 → >0 → not seen → add → sum = 1, s[1] = 1

-1 → ≤0 → max_neg = -1

2 → >0 → not seen → add → sum = 3, s[2] = 1

-2 → ≤0 → max_neg = -1 (remains)

3 → >0 → not seen → add → sum = 6, s[3] = 1

Final sum = 6 → return 6

\U0001f3ac Case 5: All Zeros
\U0001f9ea Input: [0, 0, 0]

sum = 0, max_neg = INT_MIN, s initialized.

Loop:

0 → not less than 0 → check s[0] → -1 → add 0 → sum = 0 → s[0] = 1

0 again → s[0] = 1 → skip

0 again → skip

sum = 0 → return max_neg = INT_MIN
⚠️ This case returns garbage value, so maybe we should handle zeros separately if needed.

\U0001f3ac Case 6: Only Duplicates
\U0001f9ea Input: [1, 1, 1, 1]

First 1 → not seen → add → sum = 1, s[1] = 1

All others → seen → skip

Return sum = 1

\U0001f3ac Case 7: Edge of 0 and Negatives
\U0001f9ea Input: [0, -1, -5, 0, -2]

Loop:

0 → not ≤ 0 → unseen → add 0 → sum = 0 → s[0] = 1

-1 → update max_neg = -1

-5 → max_neg = -1

0 → already seen → skip

-2 → max_neg = -1

sum == 0 → return max_neg = -1






*/