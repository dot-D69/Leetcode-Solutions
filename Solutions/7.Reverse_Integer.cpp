class Solution {
public:
    int reverse(int x) {
        long rev_num =0;
        while(x!=0){
            int last = x%10;
            x/=10;
            rev_num = (rev_num*10)+last;
        }

        if (rev_num > INT_MAX || rev_num < INT_MIN) {
                return 0;
        }
        
        return rev_num;
    }
};