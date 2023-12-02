class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int m = pushed.size();
        int i=0,j=0;
        while(i<m && j<m){
            st.push(pushed[i]);

            while(!st.empty()&&j<m&&popped[j]==st.top()){
                st.pop();
                j++;
            }
            i++;
        }
        return st.empty();
        
    }
};