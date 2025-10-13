class Solution {
public:
    bool isAnagram(string &a, string &b){
        if(a.size()!=b.size()) return false;
        vector<int> freq(26);
        //Count the freq of all the  characters in string a
        for(char c: a){
            freq[c-'a']++;
        }

        for(char c: b){
            int idx = c-'a'; // We check each letter of the word in string b
            freq[idx]--; //Since we are using it up to find the freq so we remove one, everytime
            if(freq[idx]<0){ // If the count of letter are same then the freq[idx] will not be negative ,but if string b has more count then it will the freq of that letter will become zero 
                return false;
            }
        }

        for(int cnt : freq){
            if(cnt!=0) return false;
        }
        return true;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        res.push_back(words[0]);
        for(int i =1;i<words.size();i++){
            if(!isAnagram(words[i],res.back())){ //  if botht he words are not anagraams then we push it into the res
                res.push_back(words[i]);
            }
        }
        return res;
    }
};

// Time Complexity: O(n) per comparison
// Space Complexity: O(26)≈O(1) extra