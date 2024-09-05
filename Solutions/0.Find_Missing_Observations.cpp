class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size(); //  to get the value of m
        int obs_sum=0;
        for(int i: rolls){
            obs_sum+=i; // get the sum of the elements we have
        }

        int total_sum = mean *(m+n); // to get the total sum we use this formula
        int target_sum = total_sum-obs_sum; // to find the sum of the missing observations or the sum tha

        if(target_sum<n || target_sum>n*6){ //if the target sum is less than or greater than the min or max value of n array
            return {}; //  return an empty array
        }

        vector<int> res (n,1); //  intialize an n-size array with all elements as 1 

        int rem_sum = target_sum- accumulate(res.begin(),res.end(),0); // calculate how much more we have to add to the array elements to make them equal to target sum

        int i=0;
        while(rem_sum>0){
            int val = min(5, rem_sum); // the max we can add to res[i] is 5 as the res[i] is 1 intially and 5+1=6 the max we can go as the dice has the max number as 6
            res[i]+=val; // add to the element
            rem_sum-=val; // subtract the value added from remaining value 

            i =  (i+1)%n; // to treat the array as a circular array so it distribute the sum to all the elements of the array
        }
        return res;
    }
};

// suppose we have the rolls [3,2,4,3] mean =4, n=2
// To get the total sum of the all the elements we use  mean*(m+n) --> 4*(4+2) = 24
// Now we calculate the sum of the missing observation =  total_sum - observed_sum ---> 24-12 =12
// 12 is our target sum i.e. we want our array of n elements to sum upto 12
// before we check if the target sum is acheivable i.e we will initialize an array of n with the minimum number on the dice i.e 1
// In this case our n is 2 so [1,1]
// so to check if our target_sum can be acheived or not we will check whether the target sum lies with range of sum of min elements of array  to the sum of max elements 
// i.e. 2<= 12 <= 12 so our target sum can be acheived within the range of 1 to 6

// now we will run a loop till the rem_sum is not equal to zero (once it becomes 0 it means our target sum has been reached )
// now we need to add the value to the res array element  since the array has element [1,1] so the max we can add is 5 as 5+1 =6
// so we use the minimum of  (5 , rem_sum) i.e min(5,12) we gives use 5
// we add the 5 to the res array = [6,1]
// subtract the added value from rem_sum = 12- 5 = 7
// again we repeat the same step of taking the min adding it then subtracting
// we use (i+1)%n so that not all the value is added to one element and the other element are left as 1,  this make sure to go on to the next element and treats array as cicrcular array
