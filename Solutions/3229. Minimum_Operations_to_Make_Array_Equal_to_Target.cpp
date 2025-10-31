class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();

        vector<int> diff(n); //TO store the difference between target array and the nums array
        long long res = 0; 

        for(int i =0;i<n;i++){  //This wil calculate the difference in elements between our target and num
            diff[i] = target[i] - nums[i];
        }

        //Once we have our difference arrays  , we just need to make the  difference array element 0 , as the  difference will lower our nums will become more closer to our target array

        //for eg: if diff = [2,1,1,1]  then the number of operations it will take to make the diff elements to [0,0,0,0] is the numbers of operations in which the nums will become equal to our target

        //What i am trying to say is we got the difference between two arrays, if we make the difference 0  then both will become the same i.e (nums == target)

        // Now we can either go from diff[]  => [0,0,0,0]  or [0,0,0,0]  => diff[] {BOTH ARE SAME AS THE NUMBER POPERATIONS WILL BE SAME WHTHER WE GO FROM DIFF ELE TO 0 OR FROM 0 to DIFF ELE}


// We try to calculate the numbers of operations it will take to make the diff equal to 0 
        int curr = 0;
        int prev = 0;

        for(int i = 0;i<n;i++){
            curr = diff[i];

            //If there is different sign i.e. ([1,-2,2] or [-2,3,-1]) : THIS IS special case so we need to check before starting if there change of sign between two elements
            if((curr<0 && prev>0)  || (curr>0 && prev<0) ){
                res+=abs(curr);
            }
            else if(abs(curr)>abs(prev)){
                res+=abs(curr-prev);
            }
            prev = curr;
        }
        return res;
    }
};

//TIme ciomplexity : O(n)
//SPace complexity : O(n)