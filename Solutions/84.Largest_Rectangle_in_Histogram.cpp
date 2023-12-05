class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        int leftsmall[n],rightsmall[n];
        
        //To compute the leftsmall arr
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                leftsmall[i]=0;
            }
            else{
                leftsmall[i]=st.top()+1;
            }
            st.push(i);
        }

        //Clear the stack to reuse for rightsmall

        while(!st.empty()){
            st.pop();
        }

        //Compute rightsmall

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                rightsmall[i]=n-1;
            }
            else{
                rightsmall[i]=st.top()-1;
            }
            st.push(i);
        }

        //Computing the MaxArea using the left and right smaller area
        int MaxArea=0;

        for(int i=0;i<n;i++){
            MaxArea=max(MaxArea,heights[i]*(rightsmall[i]-leftsmall[i]+1));
        }
        return MaxArea;
    }
};