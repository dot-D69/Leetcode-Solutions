class Solution {
public:

    void solve(vector<int>&candidates,int target, vector<int>& curr, vector<vector<int>>& res, int idx){
        if(target<0) return; // if the target becomes negative so we have choosen a worng path altogether so we should just abort that path
        if(target == 0){
            res.push_back(curr);
        }

        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;  // To filter out any duplicates combinationa that may form

            curr.push_back(candidates[i]); //Do
            solve(candidates,target-candidates[i],curr,res,i+1);//Explore
            curr.pop_back();//Undo
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res; // To store the curr in the result;
        vector<int> curr;  // To store the combination for the selected index

        sort(candidates.begin(),candidates.end()); //Sort to avoid Duplicates combinations while backtracking
        solve(candidates, target, curr, res,0);
        return res;
    }
};
