class Solution {
public:
    char findTheDifference(string s, string t) {
        char extrachar=0;

        for (char c:s){
            extrachar^=c;
        }

        for(char c:t){
            extrachar^=c;
        }
        return extrachar;
    }
};

// it will xor the ASCII value of each character from string s and then string t at last the ASCII value of the  extra char will be stored as char into extrachar
