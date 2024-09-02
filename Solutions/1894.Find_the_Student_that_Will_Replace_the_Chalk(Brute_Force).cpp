//Brute force - Gives TLE Due to very Large value of K

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        while(true){ 
            for(int i=0;i<chalk.size();i++){
                if(k<chalk[i]){
                    return i;
                }
                k-=chalk[i];
           }
    }  return 0;
      
    }
};
