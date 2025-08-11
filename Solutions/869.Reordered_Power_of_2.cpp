class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string digits = to_string(n);
        sort(digits.begin(),digits.end());

        int power = 1;
        while(power<=1000000000){
            string powerStr = to_string(power);
            sort(powerStr.begin(),powerStr.end());

            if(digits == powerStr){
                return true;
            }

            power*=2;
        }
        return false;
    }
};

// <----------------------------------------------------------------------------------------------------------------------->
// We can store in set

class Solution {
public:
    bool reorderedPowerOf2(int n) {

        unordered_set<string> Powerst;
        int power = 1;
        while(power<=1000000000){
            string p = to_string(power);
            sort(p.begin(), p.end());
            Powerst.insert(p);

            power*=2;
        }

        string digits = to_string(n);
        sort(digits.begin(),digits.end());

        return Powerst.count(digits)>0;
    }
};

// We calculate all the powers of 2 till 10^9 
// First we take the input, covert it into string and sort it ( so that it is easier for us to rearrange the digits)
//Then for each n we run a loop that will calculate all the powers of two till 10^9
// Each power of two is converted to a String and then sorted
// Then checks if the sorted input and th sorted power are same , then it is true ,else false

// Eg: n = 46 , after converting and sorting -> "46"
// power  = 64 , after converting and sorting -> "46"
// Both are equal, it means 46 can be arranged in a way that it is the power of 2

// n =215, after converting and sorting -> "125"
// n = 512, after converting and sorting -> "125"
// both are equal so it will return, since 125 can be rearranged into a power of 2

// n = 10000, after converting and sorting -> "00001"
// power = 1 , after converting and sorting -> "1"
// Power is not equal to n , then it will return false