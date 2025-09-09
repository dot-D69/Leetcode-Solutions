class Solution {
public:
// This checks if any digit of the number is a 0 so we return false
// Example: 205 --> 205%10 = 5 Valid , then a = 20 --> 20%10 = 0 Not valid
    bool notZero(int a){
        while(a>0){
            if(a%10 == 0) return false;
            a=a/10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        
        for(int i=1;i<n;i++){ //The max we can subteact from the given has got to be less than the number
        //Subtracting get us the first number and the number we subtracted from it is the second number
            int a = n-i; // we get a by subtracting i from it
            if(notZero(a) & notZero(i)){ // We just check if both numbers do not contain zero in them
                return{a,i};// This means both numbers are No-Zero integer 
                break; // no need to  check further we have gotten an answer
            }
        }
        return {}; // This never gets executed since we always find a solution
    }
};

// Time complexity :O(nlogn)
// Space complexity: O(1)