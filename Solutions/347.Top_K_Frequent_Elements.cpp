// Top k Frequent Elements using Bucket Sort
// Time Complexity: O(n), Space Complexity: O(n)

//Example: nums = [1,1,1,2,2,3], k = 2
//Output: [1,2]

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(auto x:nums){
            map[x]++;
        }
        int n = nums.size();

        vector<vector<int>> bucket(n+1);

        for(const auto& pair:map){
            bucket[pair.second].push_back(pair.first);
        }

        vector<int> result;
        for(int i =n;i>0;i--){
            for(int num:bucket[i]){
                result.push_back(num);
            }
        }

        result.resize(k);
        return result;

        
    }
};