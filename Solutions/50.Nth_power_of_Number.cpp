class Solution {
public:
    double myPow(double x, int n) {
        // Handle the case where n is 0, any number raised to the power of 0 is 1.
        if (n == 0) {
            return 1;
        }

        // Convert n to a long long to handle INT_MIN, which is -2147483648.
        long long ln = n;

        // Handle negative exponent by taking the reciprocal of x.
        if (ln < 0) {
            ln = -ln;
            x = 1 / x;
        }

        // Calculate the result iteratively to avoid recursion.
        double ans = pow(x, ln / 2);

        // If ln is odd, multiply ans by itself and x to maintain the correct exponent.
        if (ln % 2 == 1) {
            return ans * ans * x;
        }

        // If ln is even, simply square ans.
        return ans * ans;
    }
};
