class Solution {
public:

    long long solve(int l ,int r){
        // Rannges
        // 1 to 3  steps =1
        // 4ot 15 steps = 2
        // 16 to 63 steps =3

        // we start form the starting range and will jepp moving forward till we have ifnd a solution for all
        long long L =1;
        long long S =1;
        long long step =0;
        
        while(L<=r){ // Cause at anytime the starting Range is greater than the last element in our queries then it means, we have exhausted our array of [l to r] elements
        long long R = 4*L-1;
        
        //Now we have to find the elements present in our Range L To R with S
        long long start = max(L,(long long)l); //Since we are comparing we cannot compare a long long and a int so we type cast the l into long long
        long long end = min(R,(long long)r); //Same to make comparison we type cast r into long long

//The values from start to end --> tells us that element from start to end are present in the Range L to R

//Now we need to find the number of elements;
        if(start<=end){ //If for some value start is bigger than end , then the range we took is inalvid and we would have to move to another range so a check before getting the number of elements, that we are taking the right range and elements
    
    // To find the steps in which we may  make the elements 0 = no.of elements * S (Steps in the given range)
            step+= (end-start+1)*S;
        }
    //Now we move to another Range to check for any elements if present :
    S++; //Since in each rannge the steps only increase by 1
    L = L*4; // Each range starts a from a mulitple of 4 after the first range
    }
    return step;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long res = 0;

        for(auto &q: queries){
            int l = q[0];
            int r = q[1];

            long long steps = solve(l,r);
            res+= ceil(steps/2.0);
             
        }
        return res;
    }
};


// There may some difficulty in understanding the whole thing at first , but keep readin and go through all examples then may it become easy


/*
    let's say that for our query (2,7)  arr= [2,3,4,5,6,7]
    1 ---> (1/4) --> 0 (1 step)
    2 ---> (2/4) --> 0 (1 step)
    3 ---> (3/4) --> 0 (1 step)
    4 --> (4/4) -->1 ---> (1/4) --> 0 (2 steps)
    5 --> (5/4) -->1 ---> (1/4) --> 0 (2 steps)
    :
    :
    :
    :
    15 --> (15/4) -->1 ---> (1/4) --> 0 (2 steps)
    ---------------------------------------------
    16  --> (16/4) -->4 ---> (4/4) --> 1 --->(1/4) ----> 0  (3 steps)
    :
    :
    :
    63  --> (63/4) -->4 ---> (4/4) --> 1 --->(1/4) ----> 0  (3 steps)


    So we have found a pattern that is within:
    Range(1 to 3 ) it takes 1 step to make element 0
    Range (4 to 15) it takes 2 steps to make element 0
    Range (16 to 63) it takes 3 steps to make element 0
    Range (64 to 255) it takes 4 steps to make element 0
    so on and so forth

    So that's one part 

*****************************************************************************************

Now we need to find which query falls under which range:
Let's take example queries = [(1,2) , (2,4)]

queries[0] = (1,2) ---> Arr=[1,2]

let l =1, r=2

Now to  find the range in which it lies we go through each range and check, How? :
Let's start with the first range (1 to 3)
So here Let L = 1 and R= 3 and our steps be S =1

So to check which elements falls under this range we do
 start = max(L,l) = max(1,1) = 1
 ens = mins(R, r) = max(2,2) = 2

 so the elements 1 to 2 lie in the range (1 to 3)
 Now to find the steps we  need = no. of elements * S
 
 To find no. of elements we do = end-start+1 == 2-1+1 = 2
 Steps = 2*2 =4
 This is the steps we got for making all elements in (1,2) 0
 But the total operation to do so will be =steps/2 (WHY? --> Because we arenot taking elements one byone , we are supposed to take 2 elements at a time , hence our answer will be steps/2)

 
 $$$$$$$$$$ But this does not clear things let's move to another $$$$$$$$$$$$
 
 queries[1] = (2,4) = {2,3,4}  // NOw just by loking we can tell that all elements won't fall in the same range as it did for the previous query, like now we know thqat 2,3 will fall in range (1 to 3) and 4 will fall in range (4 ot 15) How do we represent this in code:

 Here our l = 2, r = 4

 We start from the Range (1 to 3) S=1
 L =1, R= 3

 Now we need to find the elements that lie in this range so:

 start = max(L,l) = max(1,2) = 2
 end = min(R,r) = min(3,4) = 3

 So from the upper formula we get to knoe that elements from 2 to 3 lie in the range  (1 to 3)
    But how does it actua;y work
    
    1--------2-----------3--------4    
    L        l           R        r        Here L and R are for the range  and l and r are for the elements
    So  form this number line we can see that within the range L to R only the elements form 2 to 3 lie
    so if we do max (L,l) so it will always take element after L
    and if we do min(R,r) so it will always take element before R 
    This ensures that we are within range and all the elements within that range are given to us

    Steps = no.of elements * S 
    Steps = (end-start+1) * S
    Steps = (3-2+1)*1
    Steps = 2*1 =2

    But for the arrya [2,3,4], we have not covered all the elements so  we move to the next range sincwe we have gotten  all the elemtns that are present in this range so if some element is not present in this range it will be someother rnage

Now L was 1, R was  3 and S was 1
TO move to the next Range (if you see iabove where we set our ranges the next range is ( 4 to 15))
 So to move to next range we do the following;
 S++; (since steps only increse by 1 in every range)
 L= L*4 (Every range starts in Multiple of 4 after the 1)
 R= 4*L-1 (4*4-1 =15  {which is the extreme of our another range})

 So Our Range becomes L=4 , R= 15, S=2;

    Again wee need to find the elements present in the range so we do:
    start = max(L,l) =(1,4) = 4
    end = min(R,r) = (15,4) = 4

    So only the element 4 is present in the range (4 to 15)

    Steps = no.of elements * S
    Steps = 1 *2 = 2

    Total steps = 2+2 = 4
    Operations = steps/2 = 4/2  = 2(as exlained beforer we are supposed to take 2 elements at a time)
*/


// JUST IN CASE THERE IS STILL CONFUSION THEN REFER TO : https://www.youtube.com/watch?v=VYDl3p9bkkw
// OR TRY TO DRY RUN THE GIVEN CODE IN  A COPY AND THEN SEE THE RESULT BY OYUR SELF

