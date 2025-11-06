class Solution {    
public:

    bool isValid(vector<int>& have,vector<int>& need){
        for(int i =0;i<256;i++){
            if(have[i]<need[i]){
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();

        if(m<n){
            return "";
        }

        vector<int> have (256,0); // This is to check the charcters that we have in the string s
        vector<int> need (256,0); // This helps to check if the characters needed to amke the window valid are present in "have"

        for(int i =0;i<n;i++){
            need[t[i]]++;
        }
        //Sliding window template
        int low = 0;
        int high = 0;
        int res = INT_MAX; //because we want the minimum window
        int start = -1; // It will point to the star of the minimum window substring

        for(high = 0 ;high<m;high++){
            have[s[high]]++; //Put the character in our have

            while(isValid(have , need)){ // it will run till we have a valid substring i.e that ahs characters form string t
                int len = high - low +1;
                if(res>len){ //updated the res with the minimum valid length substring
                    res = len;
                    start = low;
                }
                have[s[low]]--; // Then we remove the low from the window and 
                low++; // Then shringk the window in hope to find a valid substring that is even smaller thatn our current valid substring
            }
        }
        if(res == INT_MAX) return "";
        return s.substr(start, res);
    }
};