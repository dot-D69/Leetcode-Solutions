//simple two-pointer approach

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n =numbers.size();
        int s=0;
        int e =n-1;
        
        for(int i=0;i<n;i++){
            if(i<0 && numbers[i]==numbers[i-1]) continue;

            while(s<e){
                if(numbers[s]+numbers[e]>target) e--;
                else if(numbers[s]+numbers[e]<target) s++;
                else{
                    return {s+1,e+1};
                }
            }
        }
        return {-1,-1};
    }
};
