class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
    int n=prices.size();
    vector<int> ans(n, -1);
    
    stack<int> st;
    st.push(0);
    
    for(int i=1; i<n; i++)
    {
        while(!st.empty() && prices[st.top()] >= prices[i])
        {
            ans[st.top()] = prices[st.top()] - prices[i];
            st.pop();
        }
        st.push(i);
    }
    
    for(int i=0; i<n; i++)
    {
        if(ans[i] == -1)
         ans[i] = prices[i];
    }
	
    return ans;
}
        
    
};