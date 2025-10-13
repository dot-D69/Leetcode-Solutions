class Solution {
public:
    bool isAnagram(string a, string b){
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        return a == b;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        res.push_back(words[0]);
        for(int i =1;i<words.size();i++){
            if(!isAnagram(words[i],res.back())){ 
                res.push_back(words[i]);
            }
        }
        return res;
    }
};

// Time Complexity: O(nlogn) per comparison
// Space Complexity: O(1) (in-place sort)