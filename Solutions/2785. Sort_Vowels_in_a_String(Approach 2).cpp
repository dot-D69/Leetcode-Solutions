class Solution {
public:

    bool isVowel(char c){
        c = tolower(c);
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
        }

    string sortVowels(string s) {
        unordered_map<char, int> mp;

        for(char &c:s){
            if(isVowel(c)){
                mp[c]++;
            }
        }

        string vowel = "AEIOUaeiou";
        int j=0;

        for(int i=0;i<s.length();i++ ){
            if(isVowel(s[i])){
                while(mp[vowel[j]]==0){
                    j++;
                }
                s[i] = vowel[j];
                mp[vowel[j]]--;
            }
        }
        return s;

    }
};

/*


Time Complexity (TC): O(n)

Space Complexity (SC): O(1) extra



s = "lEetcOde"

Step 0: Initialization
mp → an unordered_map<char,int> to store frequency of each vowel in s.
vowel = "AEIOUaeiou" → the order we will place vowels back (ASCII order).
j = 0 → pointer to track which vowel in vowel array to use next.


Step 1: Count vowels in string
Loop through s:
s[0] = 'l' → isVowel('l') → false → skip
s[1] = 'E' → isVowel('E') → true → mp['E']++ → mp = {E:1}
s[2] = 'e' → isVowel('e') → true → mp['e']++ → mp = {E:1, e:1}
s[3] = 't' → consonant → skip
s[4] = 'c' → consonant → skip
s[5] = 'O' → vowel → mp['O']++ → mp = {E:1, e:1, O:1}
s[6] = 'd' → consonant → skip
s[7] = 'e' → vowel → mp['e']++ → mp = {E:1, e:2, O:1}

Frequency map after Step 1:
mp = { E:1, e:2, O:1 }



Step 2: Place vowels back in sorted ASCII order
Loop through s again:

vowel = "AEIOUaeiou"

j = 0 → pointer in vowel array

i=0, s[0]='l' → consonant → skip

i=1, s[1]='E' → vowel

    while(mp[vowel[j]]==0)? vowel[0]='A', mp['A']=0 → j++

    vowel[1]='E', mp['E']=1 → use 'E'
    s[1] = 'E', mp['E']-- → mp['E']=0
    s = "lEetcOde", j=1

i=2, s[2]='e' → vowel
    vowel[1]='E', mp['E']=0 → j++
    vowel[2]='I', mp['I']=0 → j++
    vowel[3]='O', mp['O']=1 → use 'O'
s[2] = 'O', mp['O']-- → mp['O']=0
s = "lEOtcOde", j=3

i=3, s[3]='t' → consonant → skip

i=4, s[4]='c' → consonant → skip

i=5, s[5]='O' → vowel
    vowel[3]='U', mp['U']=0 → j++
    vowel[4]='a', mp['a']=0 → j++
    vowel[5]='e', mp['e']=2 → use 'e'
s[5] = 'e', mp['e']-- → mp['e']=1

s = "lEOtceOde", j=5

i=6, s[6]='d' → consonant → skip

i=7, s[7]='e' → vowel
    vowel[5]='e', mp['e']=1 → use 'e'
    s[7]='e', mp['e']-- → mp['e']=0
    s = "lEOtcede"

Final output:
"lEOtcede"


Code Story
1.)Check vowels → helper isVowel(char c) converts to lowercase and checks a,e,i,o,u.

2.)Count vowels → iterate string once, store frequency in mp.

3.)Prepare ordered vowels → vowel = "AEIOUaeiou" for sorted ASCII order.

4.)Replace vowels → iterate string again:

5.)For each vowel, find next available vowel in vowel array with non-zero frequency.

6.)Replace original vowel with sorted vowel.

7.)Return modified string → consonants stay in place, vowels sorted.


*/