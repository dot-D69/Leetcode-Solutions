class Solution {
public:
    int reverse(int x) {
        long rev_num =0;
        while(x!=0){
            int last = x%10;
            x/=10;
            rev_num = (rev_num*10)+last;
        }

        if (rev_num > INT_MAX || rev_num < INT_MIN) {
                return 0;
        }
        
        return rev_num;
    }
};


/*
Step-by-step dry run for x = -123

Initial values:

x = -123
rev_num = 0


First loop iteration:

last = x % 10   // -123 % 10 = -3   (in C++, remainder has same sign as dividend)
x /= 10         // -123 / 10 = -12
rev_num = (0 * 10) + (-3) = -3


Second iteration:

last = -12 % 10 = -2
x = -12 / 10 = -1
rev_num = (-3 * 10) + (-2) = -32


Third iteration:

last = -1 % 10 = -1
x = -1 / 10 = 0   // loop ends here
rev_num = (-32 * 10) + (-1) = -321

Why does it "just work" for negatives?

Because C++ % (modulus) operator preserves the sign of the dividend (x).
So for negative numbers, x % 10 gives negative remainders (e.g., -123 % 10 = -3).

The same logic that works for positives also works for negatives since digits are extracted with their correct sign.


*/