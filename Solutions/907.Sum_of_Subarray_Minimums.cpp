class Solution {
public:

    vector<int> getNSL(vector<int>& arr,int n){
        vector<int> res(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                res[i]=-1;
            }
            else{
                while(!st.empty() && arr[st.top()]>arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    res[i]=-1;
                }
                else{
                    res[i]=st.top();
                }
            }

            st.push(i);
        }
        return res;
    }

    vector<int> getNSR(vector<int>& arr,int n){
        vector<int> res(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                res[i]=n;
            }
            else{
                while(!st.empty() && arr[st.top()]>=arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    res[i]=n;
                }
                else{
                    res[i]=st.top();
                }
            }

            st.push(i);
        }
        return res;
    }


    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        long long sum=0;
        int M =1e9+7;
        vector<int> NSL =getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);

        for(int i=0;i<n;i++){
            long long left_ele = i-NSL[i];
            long long right_ele = NSR[i]-i;

            long long totalsubarray=left_ele*right_ele;
            long long totalSum = arr[i]*totalsubarray;

            sum=(sum+totalSum)%M;
        }
        return sum;
    }
};