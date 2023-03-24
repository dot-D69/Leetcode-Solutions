class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> ans(n, INT_MAX); // Initialize the answer vector with a maximum integer value
        int last_seen = -1; // Initialize last_seen variable to -1

        // Traverse the string from left to right
        for (int i = 0; i < n; i++) {
            if (s[i] == c) { // If the current character is equal to c
                last_seen = i; // Update the last_seen variable to the current index
            }
            if (last_seen != -1) { // If last_seen is not -1, i.e., if there is a previous occurrence of c
                ans[i] = min(ans[i], abs(i - last_seen)); // Update the answer vector with the minimum distance to the previous occurrence of c
            }
        }

        last_seen = -1; // Reset the last_seen variable to -1

        // Traverse the string from right to left
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c) { // If the current character is equal to c
                last_seen = i; // Update the last_seen variable to the current index
            }
            if (last_seen != -1) { // If last_seen is not -1, i.e., if there is a previous occurrence of c
                ans[i] = min(ans[i], abs(i - last_seen)); // Update the answer vector with the minimum distance to the previous occurrence of c
            }
        }

        return ans; // Return the answer vector
    }
};





// In this question first we wiil iterate from left to right 
// and find the distance of each character from the last seen character and store it in the ans array. 
// Then we will iterate from right to left and find the distance of each character from the last seen character and store it in the ans array. 
// Then we will return the ans array.