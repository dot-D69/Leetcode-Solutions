class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i = n-1;i>=0;i--){
           if(digits[i]<9){ //If less than 9 just add 1 and then return since no carry
            digits[i]+=1;
            return digits;
           }
            digits[i] =0; //If 9 or gretert so we set the digit as 0, and 1 gets added in the next iteration to the digit in next place
        }
        //Special Case:
        //If All digits are 9 9 9 then by use of the upper loop all will become  0 0 0 and no carry of 1 happens for that only we add 1 at the begining
        digits.insert(digits.begin(),1);
        return digits;
    }
};

/*

Dry run

digits = [4,3,2,1]
start from the back
digit [i] = 1;
is(1<9) yes
digit[i]+=1;
digits become [4,3,2,2]
return digits;



Special Case:

if digit = [9 , 9]
start from the back 
i=n-1 ,digits[i]= 9
is(9<9) no
then digits[n-1] = 0

now digit = [9,0]

i = n-2, digits[i]=9
is(9<9) no
then digits[n-1] = 0

at this point digit =[ 0 , 0]
and no returns happen at this point

so we move to condition
digits.insert(digits.begin(),1)
now digits = [1,0,0]
return digits

*/