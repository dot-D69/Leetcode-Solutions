class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int>res;
        int size=arr.size();
        sort(arr.begin(),arr.end());
        int i=0;
        while(i<size){
            int cnt=1;
            for(int j = i+1;j<size;j++){
                if(arr[i]==arr[j]){
                    cnt++;
                }
                else{
                    break;
                }
            }
            res.push_back(cnt);
            i+=cnt;
        }
        sort(res.begin(),res.end());
        for(int i=0;i<res.size()-1;i++){
            for(int j=i+1;j<res.size();j++){
                if(res[i]==res[i+1]){
                    return false;
                }
            }
        }
        return true;
    }
};
