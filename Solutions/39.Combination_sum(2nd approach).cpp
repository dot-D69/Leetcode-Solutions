// second appraoch
class Solution
{
public:
    void Combination(int i, int target, int sum, vector<int> &candidates, vector<int> &store, vector<vector<int>> &result)
    {

        if (sum == target)
        {
            result.push_back(store);
            return;
        }
        if (i >= candidates.size() || sum > target)
            return;

        // Take the element
        sum += candidates[i];
        store.push_back(candidates[i]);
        Combination(i, target, sum, candidates, store, result); // recursive call (we dont incremeent i as we may have to take ii again)
        sum -= candidates[i];                                   // backtracking whatever changes we did removing them
        store.pop_back();                                       // backtraacking

        // Skip the element
        Combination(i + 1, target, sum, candidates, store, result);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> store;
        sort(candidates.begin(), candidates.end());
        Combination(0, target, 0, candidates, store, result);
        return result;
    }
};