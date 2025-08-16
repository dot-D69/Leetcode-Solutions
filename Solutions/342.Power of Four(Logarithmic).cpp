class Solution {
public:
    //Follow Up with loop or recursion
    bool isPowerOfFour(int n) {
        // 1. Logarithmic
        if(n<=0){
            return false;
        }

        double k = log10(n)/log10(4);

        return k == (int) k;
    }
};