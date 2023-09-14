class Solution {
public:
    void generate_subset(int i,int target,int sum,vector<int>&candidates,vector<int>&store,vector<vector<int>> &result){

        if(sum==target){
            result.push_back(store);
            return;
        }

        if(i>=candidates.size() || sum>target) return;

        // pick the elements  (when piccking elements we may pick the duplicate elements)
        sum+=candidates[i];
        store.push_back(candidates[i]);
        generate_subset(i+1,target,sum,candidates,store,result);
        sum-=candidates[i];
        store.pop_back();

        //not pick the element  (when not picking a element we will not any of duplicates of the element)
        while(i+1<candidates.size() && candidates[i]==candidates[i+1]) i++; // to skip duplicate elements
        generate_subset(i+1,target,sum,candidates,store,result);

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> store;
        sort(candidates.begin(),candidates.end());
        generate_subset( 0, target, 0,candidates,store,result);
        return result;
        
    }
};

