//Brute Force
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;
        for (int i =0;i<n;i++){
            unordered_set<char> seen;
            for(int j=i;j<n;j++){
                if(seen.count(s[j])) break;
                seen.insert(s[j]);
                maxLen=max(maxLen,j-i+1);
            }
        }
        return maxLen;
    }
};

/*

Explanation:
Check every possible substring of the string.
For each substring, verify if all characters are unique.
Track the maximum length of substrings with unique characters.

Steps:
Use two loops:
Outer loop for the starting point of the substring.
Inner loop for the endpoint of the substring.
Use a set to check if all characters in the substring are unique.
Update the maximum length if the substring is valid.

*/