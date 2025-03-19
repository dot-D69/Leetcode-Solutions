class Solution {
    public:
        vector<int> findDisappearedNumbers(vector<int>& nums) {
            int n = nums.size();
            vector<int> res;
            for(int i=0;i<n;i++){
                int index = abs(nums[i])-1;  // convert the value into index 
                if(nums[index]>0){
                    nums[index] = -nums[index];  // Make the value at that index as negative (i.e. mark visited)
                }
            }
    
            for(int i=0;i<n;i++){
                if(nums[i]>0) res.push_back(i+1);
            }
            return res;
        }
    };
    
    //Time Complexity: O(n)
    //Space Complexity: O(1)
    
    // The dry run for the code will be :
    
    /*
    1st pass
     i=0; ,  index = nums[i]= 4, 4-1 =3
     nums[index] = nums[3]=7
     nums= [4,3,2,-7,8,2,3,1] marked as visited
    
    2nd pass
     i=1; ,  index = nums[i]= 3, 3-1 =2
     nums[index] = nums[2]=2
     nums= [4,3,-2,-7,8,2,3,1] marked as visited
    
     3rd pass
     i=2; ,  index = nums[2]= -2 , 2-1 =1
     nums[index] = nums[1]=3
     nums= [4,-3,-2,-7,8,2,3,1] marked as visited
    
     4th pass
     i=3; ,  index = nums[i]= -7, 7-1 =6
     nums[index] = nums[6]=-3
     nums= [4,-3,-2,-7,8,2,-3,1] marked as visited
    
     5th pass
     i=4; ,  index = nums[i]= 8, 8-1 =7
     nums[index] = nums[1]=1
     nums= [4,-3,-2,-7,8,2,-3,-1]   marked as visited
    
      6th pass
     i=5; ,  index = nums[i]= 2, 2-1 =1
     nums[index] = nums[1]= -3 (already neagtive)
     nums= [4,-3,-2,-7,8,2,-3,-1] already marked as visited
    
     7th pass
     i=6; ,  index = nums[i]= 3, 3-1 =2
     nums[index] = nums[2]=-2 (already neagtive)
     nums= [4,-3,-2,-7,8,2,-3,-1] already marked as visited
    
      8th pass
     i=7; ,  index = nums[i]= -1, 1-1 =0
     nums[index] = nums[0]= 4 
     nums= [-4,-3,-2,-7,8,2,-3,-1]  marked as visited
    
    
     so our marked array is nums= [-4,-3,-2,-7,8,2,-3,-1]
    
     When we iterate to find the indexes that are not negative we get 5,6 which we push in the vector which is the answer
     */