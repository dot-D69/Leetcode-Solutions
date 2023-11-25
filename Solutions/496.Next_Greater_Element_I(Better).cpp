// O(n*m) Complexity using hashmap

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> mp;
        for (int i = 0; i < nums1.size(); i++)
        {
            mp.insert({nums1[i], i});
        }
        vector<int> res(nums1.size(), -1);

        for (int i = 0; i < nums2.size(); i++)
        {
            if (mp.find(nums2[i]) == mp.end())
            {
                continue;
            }
            for (int j = i + 1; j < nums2.size(); j++)
            {
                if (nums2[j] > nums2[i])
                {
                    int idx = mp[nums2[i]];
                    res[idx] = nums2[j];
                    break;
                }
            }
        }
        return res;
    }
};