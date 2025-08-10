class Solution {
public:
    bool isPowerOfTwo(int n) {
        // we use bit manipulation for this
        // All the powers of are like : 1,2,4,8,16,32,128....
        //So the binary of these are : 1, 10,100,1000,10000,100000,1000000...
        //You see any power of two has the starting bit as 1 and rest bits are following zeros
        // Now 3: 11, 10: 1010, 50: 110010, 100: 1100100 . so they will not pass as they multiple 1 bits and followings one and zeros

        // To check we check like n-1 -> so if n is 16 = 10000 -> then n-1 = 01111 ( it will flip all the bits)
        // Now if we and n& n-1 ->10000 & 01111 = 00000 -> this gives zero so , it is valid
        // n  = 10 : 1010 , n-1 = 1001 , n&n-1 = 1010 * 1001 = 1000 -> not 0 (false)

        if(n>0 && (n&(n-1))==0){
            return true;
        } 
        return false;
    }
};