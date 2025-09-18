// OPtimized Sliding window
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen =0;
        int start= 0;
        unordered_map<char,int> seen;
        for(int end =0;end<n;end++){
            if(seen.count(s[end])){
                start = max(start,seen[s[end]]+1);
            }
            seen[s[end]]=end;
            maxLen = max(maxLen,end-start+1);
        }
        return maxLen;
    }
};


/*

Explanation:
Use the sliding window technique with two pointers (start and end), but replace the set with a hash map.
The hash map (seen) stores the last index of each character.
If a duplicate is found, jump the start pointer directly to seen[s[end]] + 1 to skip over the duplicate efficiently.

Complexity:
Time: O(n) → Each character is processed once.
Space: O(n) → For the hash map storing character indices.

Why Is It Better Than the Set Solution?
Set Solution:
Typically involves repeatedly removing elements from the set when duplicates are encountered, which may cause unnecessary operations and slight inefficiencies.

Hash Map Solution:
By directly storing the last index of each character, you avoid repeated removals and can jump start to the correct position in O(1) time.

Conclusion: Hash maps are more efficient for this problem because they allow direct access to the index of a character, minimizing redundant operations. 




*/