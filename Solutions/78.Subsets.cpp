class Solution {
public:
    vector<int> vec;
    void generate_subset(int i,vector<int>& nums,vector<int>& vec){
        if(i>=nums.size()){
            result.push_back(vec);
            return;
        }

        vec.push_back(nums[i]);
        generate_subset(i+1,nums,vec);
        vec.pop_back();
        generate_subset(i+1,nums,vec);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        generate_subset(0,nums,vec);
        return result;
        
    }
private:
    vector<vector<int>> result;
};



/*
I will explain the main part of the code that is:
    1.vec.push_back(arr[index]);
    2.subsequence(index+1,arr,size,vec);
    3.vec.pop_back();
    4. subsequence(index+1,arr,size,vec);

    i=0 push 3 to vec so [3]
    then call subsequence(1,arr,size,vec)
    i=1 push 1 to vec so [3,1]
    then call subsequence(2,arr,size,vec)
    i=2 push 2 to vec so [3,1,2]
    then call subsequence(3,arr,size,vec)
    i=3>=size so print vec and return to previous call ( print [3,1,2])
    after returning it goes to pop_back() so it removes the last that is 2 so [3,1]  (line 3)
    after pop_back() it moves to line 4 and calls subsequence(3,arr,size,vec)
    i=3>=size so print vec and return to previous call ( print [3,1])
    when vec [3,1] the index was i =1 so when it returns to previous or backtracks it goes to line 2 then it moves to line 3 then pop_back() so [3]
    then it moves to line 4 and calls subsequence(2,arr,size,vec) (as i was 1 so i+1=2)
    i=2 push 2 to vec so [3,2]
    then call subsequence(3,arr,size,vec)
    i=3>=size so print vec and return to previous call  ( print [3,2])
    when vec [3,2] the index was i =2 so when it returns to previous or backtracks it goes to line 2 then it moves to line 3 then pop_back() so [3]
    then it moves to line 4 and calls subsequence(3,arr,size,vec) (as i was 2 so i+1=3)
    i=3>=size so print vec and return to previous call  ( print [3])
    when vec [3] the index was i =0 so when it returns to previous or backtracks it goes to line 2 then it moves to line 3 then pop_back() so []
    then it moves to line 4 and calls subsequence(1,arr,size,vec) (as i was 0 so i+1=1)  
    i=1 push 1 to vec so [1]
    then call subsequence(2,arr,size,vec)

    and so on.....
*/
