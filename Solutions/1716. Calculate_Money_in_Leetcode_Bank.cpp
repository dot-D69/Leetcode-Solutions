class Solution {
public:
    int totalMoney(int n) {
        int completeWeeks = n/7;
        int remainingDays = n%7;

        int last_term = 28 + (completeWeeks - 1) * 7; // last_term = a0 + (x-1)*d

        int res =  (completeWeeks* (28 + last_term))/2; // sum of x terms  = x * (a0 +ax)/2;

        int monday_money = completeWeeks+1;
        for(int i = 0 ; i<n%7 ;i++){
            res+=monday_money+i;
            
        }
        return res;
    }
};