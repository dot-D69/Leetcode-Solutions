class Solution {
public:
    void generate (int i,int k,int n ,int sum, vector<int> &store,vector<vector<int>> &result){

        if(k==0 && sum ==n){
            result.push_back(store);
            return;
        }

        if(k>n-i+1)return;
        if(i==10 || sum>n) return;

        //take
        sum+=i;
        store.push_back(i);
        generate(i+1,k-1,n,sum,store,result);
        sum-=i;// backtrack
        store.pop_back(); // backtrack

        //not take
        generate(i+1,k,n,sum,store,result);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> store;
        generate(1,k,n,0,store,result);
        return result;
        
    }
};