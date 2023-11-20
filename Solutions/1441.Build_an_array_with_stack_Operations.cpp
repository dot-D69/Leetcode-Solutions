class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int idx=0;
        int  num=1;

        while(num<=n && idx<target.size()){
            int x = target[idx];
            if(x==num){
                res.push_back("Push");
                num++;
                idx++;
            }
            else{
                res.push_back("Push");
                res.push_back("Pop");
                num++;
            }

        }
        return res;
        
    }
};