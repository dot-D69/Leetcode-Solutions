class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
        unordered_map<int,int> mp;
        if(numerator ==0) return "0";

        if((long long)numerator*(long long)denominator <0){
            res+="-";
        }

        long long posnumerator = labs(numerator);
        long long posdenominator = labs(denominator);

        long long quotient = posnumerator/posdenominator;
        res+=to_string(quotient);

        long long remainder = posnumerator%posdenominator;

        if (remainder ==0){
            return res;
        }
        
        res+=".";

        while(remainder!=0){
            if(mp.count(remainder)){
                res.insert(mp[remainder], "(");
                res+=")";
                break;
            }

            mp[remainder] = res.length();
            remainder*=10;
            int digit = remainder/posdenominator;
            res+=to_string(digit);

            remainder%=posdenominator;
        }
        return res;
    }
};


/*

Explantion and DRY Run:
Dry Run:
Example: numerator = 1, denominator = 3
1. Initialize an empty string `res` to store the result and an unordered map `mp` to track remainders and their positions in the result string.
2. Check if the numerator is zero. If it is, return "0" immediately. 
3. Determine the sign of the result. If the product of numerator and denominator is negative, append a '-' to `res`.
4. Convert both numerator and denominator to their absolute values to simplify calculations.
5. Calculate the integer part of the fraction by performing integer division of the absolute numerator by the absolute denominator. Append this integer part to `res`.
6. Calculate the initial remainder by taking the modulus of the absolute numerator with the absolute denominator.
7. If the remainder is zero, return `res` as there is no fractional part.
8. Append a decimal point to `res` to indicate the start of the fractional part.
9. Enter a loop that continues until the remainder becomes zero:
   a. Check if the current remainder has been seen before (exists in `mp`). If it has, it indicates the start of a repeating sequence. Insert an opening parenthesis at the position stored in `mp` for this remainder and append a closing parenthesis at the end of `res`. Break out of the loop.
   b. If the remainder is new, store its position in `res` in `mp`.
   c. Multiply the remainder by 10 to prepare for the next digit calculation.
   d. Calculate the next digit of the fractional part by performing integer division of the updated remainder by the absolute denominator. Append this digit to `res`.
   e. Update the remainder by taking the modulus of the updated remainder with the absolute denominator.
10. After exiting the loop, return the final result string `res`./*
Time Complexity: O(n) where n is the number of digits in the fractional part before it starts repeating or becomes zero.
Space Complexity: O(n) for storing the result string and the map of remainders.
In the worst case, we may need to store all the digits of the fractional part in the result string, which takes O(n) space. Additionally, the map `mp` could potentially store all the remainders encountered during the division process, which also takes O(n) space in the worst case.


*/