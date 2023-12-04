class StockSpanner {
public:
    stack<pair<int,int>>st; // pair is to store the price and the span of the price so that we dont have to revesit all the elements
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span=1; // intianlly for the firs element the span will be 1 (obviously)
        while(!st.empty() && st.top().first<=price){
            span+=st.top().second;
            st.pop();
        }
        st.push({price,span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */