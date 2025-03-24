class Solution {
    public:
        vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
            int freq[101] = {0}; // frequency array, the curly rackets are important for the intialization
            for(int i: nums){
                freq[i]++; // add the frequency of the elemnets
            }
    
            int prefix_sum[101]={0}; // prefix sum array
            for(int i=1;i<101;i++){
                prefix_sum[i]= prefix_sum[i-1] +freq[i-1]; // compute prefix_sum to find how many nos are smaller than each number:
            }
    
        //Map back to the orignal array.
        vector<int> res;   
        for(int i:nums){
            res.push_back(prefix_sum[i]); // we return the freq of the nums elements in the intended way
        }
    
        return res;
        }
        
       
    };
    
    //  Time Complexity: O(n)
    //  Space Complexity: O(101) ≈ O(1) (fixed-size arrays)
    
    /* DRY RUN  FOR EXPLANATION.
    
    Input: nums = [8, 1, 2, 2, 3]
    
    Step 1: Build Frequency Array (freq[101])
    freq[i] stores how many times i appears in nums.
    
    nums = [8, 1, 2, 2, 3]
    
    freq array after counting:
    ----------------------------------------------------
    Index | 0  1  2  3  4 ...  8  ... 100
    Freq  | 0  1  2  1  0 ...  1  ...  0
    ----------------------------------------------------
    
    Explanation:
    - `1` appears once → freq[1] = 1
    - `2` appears twice → freq[2] = 2
    - `3` appears once → freq[3] = 1
    - `8` appears once → freq[8] = 1
    
    Step 2: Build Prefix Sum Array (prefix[101])
    prefix[i] tells us how many numbers are smaller than i.
    
    prefix[i] = prefix[i-1] + freq[i-1]
    
    ----------------------------------------------------
    Index | 0  1  2  3  4 ...  8  ... 100
    Freq  | 0  1  2  1  0 ...  1  ...  0
    ----------------------------------------------------
    prefix[0] = 0
    prefix[1] = prefix[0] + freq[0] = 0 + 0 = 0
    prefix[2] = prefix[1] + freq[1] = 0 + 1 = 1
    prefix[3] = prefix[2] + freq[2] = 1 + 2 = 3
    prefix[4] = prefix[3] + freq[3] = 3 + 1 = 4
    prefix[5] to prefix[7] stay 4 (no new numbers appear)
    prefix[8] = prefix[7] + freq[7] = 4 + 0 = 4
    ----------------------------------------------------
    Index | 0  1  2  3  4 ...  8  ... 100
    Prefix| 0  0  1  3  4 ...  4  ...  0
    ----------------------------------------------------
    
    Now, prefix[i] tells us how many numbers are smaller than `i`.
    
    Step 3: Map back to the original array
    
    For each num in nums, result[i] = prefix[num]
    
    nums:     [ 8,  1,  2,  2,  3]
    prefix:   [ 4,  0,  1,  1,  3]
    
    Final Output: [4, 0, 1, 1, 3]
    
    
    */