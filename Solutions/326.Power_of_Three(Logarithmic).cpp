class Solution {
public:
    // Logarithmic Solution
    bool isPowerOfThree(int n) {
        if(n<=0){
            return false;
        }

        double x = log10(n)/log10(3);

        return x == (int)x;
    }
};

// What we are doing here is:

// For any n to be power of 3 it must be like  n=3^k;
// It is also only possible if k is a valid integer, Like k cannot be 3.33 or 4.6 or 0.23, all these are invalid for k as it cannot be power
// therfore we check for k
// log10(n) = log10(3^k)  --> log10(n ) = k log10(3) ---> k = log10(n)/log10(3)
// As discussed above k should be a whole integer, so we check if the k that we get from dividing, is eauql to the whole integer of k

// If double k = 3.00 then (int) k = 3  (same) --> power of 3
// if double k = 3.2 then (int) k = 3 (not same) --> not power of 3