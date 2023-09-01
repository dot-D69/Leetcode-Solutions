class Solution {
public:
    int clumsy(int N) {
        if (N == 1) {
        return 1;
        } else if (N == 2) {
            return 2;
        } else if (N == 3) {
            return 6;
        } else if (N == 4) {
            return 7;
        }

        if (N % 4 == 0) {
            return N + 1;
        } else if (N % 4 <= 2) {
            return N + 2;
        } else {
            return N - 1;
        }
    }   
};

/*
The approach to this solution is that we are observing the pattern of the sequence 
Using that we have solved this as we can see from the question that the sequence is repeating after every 4 numbers  i.e. '*,/,+,-'
So we have used the same pattern to solve this question
starting we have the base cases as 1,2,3,4  as these do not follow any pattern
If N is 1, the clumsy factorial is 1.
If N is 2, the clumsy factorial is 2.
If N is 3, the clumsy factorial is 6.
If N is 4, the clumsy factorial is 7.

then for number greater than 4 we have the patter i.e
 i.)  if N is divisible by 4 without leaving a remainder then we have the factorial by adding 1 to the number 
    how do we know,  if we for example take 8 then we have (8*7/6)+(5)-(4*3/2)+(1) = 9+5-6+1=9  i.e. 8+1=9 
ii.)  if N leaves a remainder of 0, 1, or 2 when divided by 4. then we have the factorial by adding 2 to the number
    how do we know, if we for example take 10 then we have (10*9/8)+(7)-(6*5/4)+(3-2*1) = 18-7+1= 12 i.e. 10+2=12
iii.) if N leaves a remainder of 3 when divided by 4. then we have the factorial by subtracting 1 from the number
    how do we know, if we for example take 11 then we have (7*6/5)+(4)-(3*2/1)+(0) = 8+4-6+0= 6 i.e. 7-1=6

so we just use the above pattern to solve the question
*/

