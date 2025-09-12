class Solution {
public:
    bool isVowel(string s){
        
        for(char c :s){
            if(c =='a'|| c=='e'|| c=='i'||c=='o'||c=='u'){
               return true;
            }
            
        }
        return false;
    }
    bool doesAliceWin(string s) {
        if( isVowel(s)) return true;

        return false;

    }
};


/*
    If there is even a single vowel, Alice can always win by choosing that vowel.
    If there are no vowels, Bob wins.

    In summary, Alice wins if there is at least one vowel in the string, otherwise Bob wins.
    eg s = "hello"
    'e' and 'o' are vowels, so Alice can choose  either and win.
    eg s = "rhythm"
    There are no vowels, so Bob wins.


*/