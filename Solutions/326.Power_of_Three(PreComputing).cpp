class Solution {
public:
    // Precomputing Largest power
    bool isPowerOfThree(int n) {
        int num = pow(3,19);
        if(n<=0) return false;
        return num%n==0;
    }
};

// if n is a power of 3 it will divide another power of 3 completely
// Example : n =9 , it will completely divide 27, 27%9 =0
// If n=15 , it will not divide 81%15 !=0
// Now it can happen that we are given n = 243, so if 81%243 !=0 , even though 243 is a power of 3
// So we need to take highes power of 3 , that is under 32 bits and that is 3^19 ( as integer is only 32 bits)
// now any power of 3 will completely divide 3^19 and it if doesn't , it is not a power 3