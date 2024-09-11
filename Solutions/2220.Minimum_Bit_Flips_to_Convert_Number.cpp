//Using XOR

class Solution {
public:
    int minBitFlips(int start, int goal) {
        //Basically we only have to count the bit positions where they both differ
        //XOR has this property
        // XOR between Same Bits:
        // 0 ^ 0 = 0
        // 1 ^ 1 = 0

        // XOR between Different Bits:
        // 0 ^ 1 = 1
        // 1 ^ 0 = 1

        //SO If we XOR two different numbers so the places that have 0 those are the same bits and the places that 
        // have 1 those are the differing bits, so we just need to change those bits hence the number of bit flip

        int XOR   = start ^ goal;
        int count = 0;

        
        while(XOR) {
            count += (XOR & 1); //If the right most bit is 1(this checks if the rightmost bit is 1 if it is then   we increase the count by 1)

        //shift right to rule out the right most bit
        //We shift the bit to the right (i.e. 1101 ---> 0110)
            XOR = (XOR >> 1);
        }
        return count;
    }
};

//T.C : O(1) 
//S.C : O(1)
