class Solution
{
public:
    void Combination(int index, int target, vector<int> &candidates, vector<int> &store, vector<vector<int>> &result)
    {
        // Base case
        if (index == candidates.size())
        {
            if (target == 0)
            {
                result.push_back(store);
            }
            return;
        }

        if (candidates[index] <= target)
        {
            store.push_back(candidates[index]);
            Combination(index, target - candidates[index], candidates, store, result);
            store.pop_back();
        }

        Combination(index + 1, target, candidates, store, result);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> store;
        Combination(0, target, candidates, store, result);
        return result;
    }
};