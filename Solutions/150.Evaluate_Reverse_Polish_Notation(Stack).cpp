class Solution {
public:
    int Operate(int a,int b,string token){
        if(token=="+") return a+b;
        if(token=="-") return a-b;
        if(token=="*") return (long)a*(long)b;  // Long because while multiplying int can overflow
        if(token=="/") return a/b;

        return -1;

    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string &token:tokens){
            if(token=="+"||token=="-"||token=="*"||token=="/"){
                int b=st.top();
                st.pop();
                int a = st.top();
                st.pop();

                int res = Operate(a,b,token);

                st.push(res);
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};