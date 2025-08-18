class Solution {
public:
    //Follow Up with loop or recursion
    bool isPowerOfFour(int n) {
        // 2. bitmasking
        return n>0 && (n & (n-1)) == 0 && (n%3==1);
    }
};

// n>0 checks num is only positive since all powers of 4 are positive|
// n &(n-1) == 0 checks that the number is an power of 2
// n%3==1 ( Using this we filter , out of all the powers of , only the powers of 4, cause, power of 4 divided by leave a reaminder 1)

// So using a combination of both we get the answer