class Solution {
public:
    void find_comb(int i,int n,int k,vector<int> &store,vector<vector<int>> &result){
        //base conditons
        if(k==0){
            result.push_back(store);
            return;
        }
        if(k>n-i+1) return;  // checks if the remaining elements(n-i+1) are greater than 4 else it won't  go to call that recursion
        if(i>n) return;


        store.push_back(i);
        find_comb(i+1,n,k-1,store,result);
        store.pop_back();
        find_comb(i+1,n,k,store,result);
    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> result;
        vector<int> store;
        find_comb(1,n,k,store,result);
        return result;
    
    }
};