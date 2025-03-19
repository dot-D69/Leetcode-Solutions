class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            unordered_set<int> s;
            for(auto val:nums){
                if(s.find(val)!=s.end()){
                    return true;
                }
                s.insert(val);           
            }
            return false;
        }
    };

    
    /*
    THE OPTIMAL SCEANRIO IS WE DON'T KEEP THE COUNT OF THE ELEMENTS AS WE DON'T NEED THEM WE ARE JUST SUPPOSED TO TELL IF THERE IS ANY DUPLICATE ELEMENT OR NOT.
    
    SO IF THE ELEMENT IS ALREADY PRESENT IN THE SET WE SIMPLY RETURN TRUE AS IT WILL BE A DUPLICATE
    IF NOT WE ADD IT TO THE SET AND MOVE TO NEXT ELEMENT TO CHECK THE SAME CONDITION.
    
    TIME COMPLEXITY :
    BEST CASE: O(1)
    AVERAGE CASE : O(N)
    
    SPACE COMPLEXITY: O(N)
    */