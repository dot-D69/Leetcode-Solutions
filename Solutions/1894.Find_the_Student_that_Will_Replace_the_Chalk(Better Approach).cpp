class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = accumulate(chalk.begin(),chalk.end(),0LL);
        int rem  = k%sum;

        for(int i=0;i<chalk.size();i++){
            if(rem<chalk[i]){
                return i;
            }
            rem-=chalk[i];
        }
        return 0;

    }
};

// Assume this 
// We have this [5,1,5] k =29
// so we start 
//1st iteration : 5 +1+5 =11 , 29-11 = 18
// 2nd iteration : 5+1+5 = 11 , 18-11 = 7
// 3rd iteration : the 0th one will get 5 chalks leaving us with 2 chalks
// 3rd iteration: then in continued 1th indexex will get 1 chalk leacing with 1 chalk
// Now the 2nd index needs 5 chalks but there only 1 chalk so (K<chalk[i]) 
// So our output will be 2

// From the above exam we observe that what actually matters is to know the last remaining number
// As we know that it will go to some iterations i.e. it went to 2 iterations using all the elements
// we get to know what will be the output when we ge to know the last remaining number 7 

//Number of full iterations possible = K/sum

//So we just need to get the remainder of K to all the elements of sum
// K%sum will gives us the remainder 
// Then we can just check using the simulation(Brute force) to get the answer
