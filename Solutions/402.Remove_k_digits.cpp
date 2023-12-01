class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        if(num.length()<=k) return "0";

        if(k==0) return num;

        st.push(num[0]);
        for(int i=1;i<num.length();i++){
            while(k>0 && !st.empty() && num[i]<st.top()){
                st.pop();
                k--;
            }
            st.push(num[i]);
 
            if(st.size()==1 && num[i]=='0') { // To remove the zeroes that  wont add any meaning like if the answer is 0200 so we wont need the the first zero hence to remove that
                st.pop();
            }
        }

        while(!st.empty() && k>0){
            st.pop();
            k--;
        }

        string ans="";
        while(!st.empty()){
           ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        // to remove leading zeroes 
       if(ans.length()==0){
           return"0";
       }
       return ans;

        
    }
};