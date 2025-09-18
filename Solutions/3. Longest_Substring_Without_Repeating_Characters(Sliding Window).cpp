//Sliding Window
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;
        int start =0;
        int end =0;
        unordered_set<char> seen;
        while(end<n){
            while(seen.count(s[end])){
                seen.erase(s[start]);
                start++;
            }
            seen.insert(s[end]);
            maxLen = max(maxLen,end-start+1);
            end++;
        }
        return maxLen;
    }
};

/*

Explanation:
Use the sliding window technique with two pointers (start and end).
Expand the end pointer to include a character in the window.
If a duplicate is found, move the start pointer to shrink the window until it's valid again.
Use a set to store characters in the current window.

Complexity:
Time: O(n) → Each character is added to and removed from the set once.
Space: O(n) → For the set storing unique characters.


*/