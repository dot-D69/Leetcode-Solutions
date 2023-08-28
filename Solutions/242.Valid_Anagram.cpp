class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }

        map<char,int>freqS;
        for(auto it : s){
            freqS[it]++;
        }

        map<char,int>freqT;

        for(auto it : t){
            freqT[it]++;
        }

        return freqS==freqT;
        
    }
};


/*
It checks if the lengths of the strings s and t are different:
    .If the lengths are different, the function immediately returns false, as they cannot be anagrams.
Two maps, freqS and freqT, are created to store character frequencies for strings s and t respectively.
The code loops through each character in string s and increments its frequency in the map freqS.
Similarly, the code loops through each character in string t and increments its frequency in the map freqT.
Finally, the function compares the two frequency maps, freqS and freqT:
    .If the maps are identical, the function returns true, indicating that the strings are anagrams.
    .If the maps are not identical, the function returns false, indicating that the strings are not anagrams
*/