class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n==0) return 0;

        vector<int> F(31,0); //This is the array that we will use to precompute and sotre the value of every F[i]
        //So that we directly get the answer fro F[i]
        F[0] =1; // This means only 0th bit is set and that is 1 (01) and the operation req to convert 1 -> 0 is 1 hence F[0]=1

        for(int i=1;i<=30;i++){
            F[i] = 2*F[i-1]+1; // THis is the formula we derived to get the no. of operations to convert ith set bit to 0 
            //For derivation refer to MIK's Video
        }

        int res = 0; // TO store the res
        int sign = 1; // We willbe alternating the sign , hence a sign vairable is needed

        //We always solve form left to right (because if we did from right to left it is possible we may get stuck as the given rules are to followed)
        //So if we solved right to left then for 10000 we can't do anyuthing for the leftmost bit following the given rules but if we are solving left to right we can make 1000 to 1100 then solve for LMB using 2nd rule 1100 -> 0100 and then solve for 0100 -> 0000   : THAT'S WHY WE USE LEFT TO RIGHT

        for(int i =30;i>=0;i--){//left to right
            int iTH_bit = ((1<<i)&n); //This will tell us if the ith bit is set or not
            //We are tryting to solve Like eg : 110010 in this there are 3 bits set namely 5th bit, 4th bit and 1st bit
            //SO for 110010 we do F[5]-F[4]+F[1].... and so on (signs keep changing )
            //We have already computed all the bits in t our array so we jsut get the answer form that and it to the res 

            if(iTH_bit == 0){// If not set continue
                continue;
            }

            if(sign>0){
                res +=F[i];
            }else{
                res-= F[i];
            }

            sign = sign*(-1); //This alternates the sign everytime 
        }
        return res;
    }
};

//Time complexity : O(1)
//Space complexity: O(1)