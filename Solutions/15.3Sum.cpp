// Optimal Solution (two-pointer approach)

class Solution {
public:

    
    void twoSum(vector<int>& nums,int target,int i,int j,vector<vector <int>>& res){
        while(i<j){
            if(nums[i]+nums[j]<target) i++; // if the sum is less than the target move i to the right as the array is sorted so moving i to the right will overall increase the sum
            else if(nums[i]+nums[j]>target) j--; // if the sum is greater than the target move j to the left as the array is sorted so moving j to the left will overall decrease the sum
            
            else{ //This means we have found the answer
                res.push_back({-target,nums[i],nums[j]}); //push the answer elements to the res vector
                while(i<j && nums[i]==nums[i+1]) i++; // to skip any duplicates elements that are already in the array
                while(i<j && nums[j]==nums[j-1]) j--; // to skip any duplicates elements that are already in the array
                // move the pointers forward to look for another possible answer
                i++; 
                j--;
            }
        }

    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return {}; //can't return a triplet if nums is less than 3
        vector<vector<int>> res; //to store the result
        sort(nums.begin(),nums.end()); //Sorting is helpful for two pointer technique and should be used when returning the elements of an array(not the same in case of indexes)

        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue; // To skkip any duplicates of n1 element
        

            int n1 = nums[i]; // fix the n1 element

            twoSum(nums,-n1,i+1,n-1,res); // now use the function to solve the question as a two sum problem to find n2 and n3
        }
            return res;
    }
};

//Time Complexity: O(n^2)
//Space Complexity: 
// The sorting operation typically requires O(1) auxiliary space if an in-place sorting algorithm is used
// The res vector is used to store the resulting triplets. In the worst case, all possible triplets are unique, and there could be up to 
// \U0001d442(\U0001d45b^2)triplets. Therefore, the space complexity due to res is \U0001d442(\U0001d45b^2)

//Sorting helps when we are supposed to find elements instead of indexes and also sorting wil adi in the two pointer approach

// n1+n2+n3=0 i.e  (n2+n3)=-n1
