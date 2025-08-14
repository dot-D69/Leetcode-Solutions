class Solution {
public:
    // Iterative Approach
    bool isPowerOfThree(int n) {
        if(n<=0){
            return false;
        }

        while(n%3==0){
            n/=3;
        }
        return n==1;
    }
};

// We keep divinding by 3 until it is no more divisble by 3, atlst we check if the number remaining is 1 or not,
// If it is 1, then it means nwas didvisble by 3 completely and hence is a power of 3