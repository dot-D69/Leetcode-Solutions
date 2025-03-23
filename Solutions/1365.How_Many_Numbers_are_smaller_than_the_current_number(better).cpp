class Solution {
    public:
        vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
            vector<int> sortednums= nums;
            sort(sortednums.begin(), sortednums.end());
    
            unordered_map<int,int> cntmap;;
            for(int i=0;i<nums.size();i++){
                if(cntmap.find(sortednums[i])==cntmap.end()){ // it means that the element we are on is not present in map
                    cntmap[sortednums[i]]=i; /* so we add the value along withs its index/ or you can say the count of the numbers it greater than, since we are iterating over a sorted array, so the elements index tells us the number that were before it were smaller thant it,  eg. [1,2,3,4]  1->0 (no number is smaller than 1), 2->1 (1 number is smaller than 2) , 3->2 (2 numbers are smaller than 3), 4->3 (3 numbers are smaller than 4)   */
                }
            }
            vector<int> res;
            for (int i: nums){
                res.push_back(cntmap[i]);
            }
            return res;
        }
    };
    
    // Time Complexity: O(n log n)
    // Space Complexity: O(n)
    