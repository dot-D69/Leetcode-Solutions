class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mp;
        for(auto it: arr){
            mp[it]++;
        }
        int cnt=0;
        for(auto it: arr){
            if(mp[it]>1) continue;
            cnt++;
            if(cnt==k) return it;
        }
        return "";
    }
};
