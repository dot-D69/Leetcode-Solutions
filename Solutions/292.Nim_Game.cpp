class Solution {
public:
    bool canWinNim(int n) {
        if(n%4!=0 ) return true;
        
        return false;
    }
};


/*
    Nothing much to explain
    If the given number is a multiple of 4 , you will loose no matter what , since you have to pick first

    Else in all other scenarios, where n is not a multiple of 4, there is chances of winning

*/