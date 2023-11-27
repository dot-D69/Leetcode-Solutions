class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,-1);
        stack<int> st;

        for(int i=2*n-1;i>=0;i--){ // We duplicate the arr elements to creata a hypothetical extended queue in order to serve us as a circular queue, and we start from the last element;
            while(!st.empty() && nums[i%n]>=st.top()){
                st.pop();
            }

            if(i<n){
                if(!st.empty()){
                    res[i]=st.top();
                }
            }
        st.push(nums[i%n]);
        }   
        return res;
    }
};