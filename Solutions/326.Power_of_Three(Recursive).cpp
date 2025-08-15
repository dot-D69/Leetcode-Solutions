class Solution {
public:
    // Recursive Approach
    bool valid(int n) {
        if (n <= 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }

        if (n % 3 != 0) {
            return false;
        }

        return valid(n / 3);
    }
    bool isPowerOfThree(int n) { 
        return valid(n); 
    }
};

// Same thing as iterative approach just doing it recurively
// Base case if n<= 0 then it is false, if n becomes 1 , then it's true