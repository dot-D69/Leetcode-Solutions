class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long currentStreak =0;
        long long count =0;

        for(int i =0;i<nums.size();i++){
            if(nums[i]==0){
                currentStreak++;
            }else if(nums[i]!=0 ){
                count+= (currentStreak * (currentStreak+1))/2; // We use the formula (n*(n+1))/k
                currentStreak =0;
            }
        }
// We need to append the count once more after the loop ends so that is takes all the zeroes subarrays
// Since within the loop the count only gets updated if we encounter a non zero numbwer, but if the arrays is aending with 0 m=, then we will not wencounter any non zero number and they wont' be added to the count
// So to overcome that we once more add to count to see if there were any more more zeroes afr the non zero element, that could have been missed
        count+= (currentStreak * (currentStreak+1))/2;
        return count;
    }
};

/*

Now hoe did we come to the conclusion to use n*(n+1)/2 : This is the formula to get the sum of numbers from 1 to n;

so let's consider there is this subarrays [0,0,0,...k]

So how many subarrays it will form:

1. All the single zeroes will form a subarray = k

2. All the subarray of lenght 2 , every adjacent zero= k-1

3.Subarrays of length 3: Every triple of adjacent zeros
Number of such subarrays = k-2
.
.
.
and it goes one till the lenght of subarray is equal to k (the whole array) then such subaaray will be only 1, as we have considered the whole array

Now we have to calculate the number of all the subarrays formed
total subarray  = k+(k-1)+(k-2)+......+1

 k+(k-1)+(k-2)+......+1 --> This is nothing but sum of numbers from 1 to k in reverse which  is still 
  =  (k *(k+1))/2

  hence to get the numbers of subarrays formed by k contigous 0's we use the formula =  (k *(k+1))/2

  Now the code is easy we just check if the element is equal to zero or not , and increase the currentStreak count, when we encounter a non zero element , it means we have encoutered the stop for our contigous zeores,

  So we add to count using the formual, if we have encountered 3 zeroes the currentStreak will be 3,
  TO get the subarryas made by 3 zeroes we use the formula as discussed.
  Then we set the streak to 0, and again start to check for zeroes



*/