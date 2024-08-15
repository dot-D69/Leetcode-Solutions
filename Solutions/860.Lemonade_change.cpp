class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;

        for(int money : bills ){
            if(money==5){
                five++;
            }
            else if(money==10){
               if(five>0){
                five--;
                ten++;
               }
               else{
                return false;
               }
            }
            else if(five>0 && ten>0){
                five--;
                ten--;
            }
            else if(five>=3){
                five-=3;
            }
            else {
                return false;
            }
        }  
        return true;
    }
};
