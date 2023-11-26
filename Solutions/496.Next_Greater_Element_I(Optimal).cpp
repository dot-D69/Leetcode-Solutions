// Stack Solution
// O(n+m) Complexity

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
        stack<int> st;

        for (int i = 0; i < nums2.size(); i++)
        {
            int curr = nums2[i];
            while (!st.empty() && curr > st.top())
            {
                int val = st.top();
                st.pop();
                int idx = mp[val];
                res[idx] = curr;
            }
            if (mp.find(curr) != mp.end())
            {
                st.push(curr);
            }
        }
        return res;
    }
};