class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> vowel {'A','E','I','O','U','a','e','i','o','u'};// Keep a set of vowels
        vector<char>  found;
        for(auto &it:s){ 
            if(vowel.count(it)){ // check the dtring s for vowels
                found.push_back(it);  //if a vowel is found put them into the found array
            }
        }

        sort(found.begin(),found.end()); // this sorts the founded vowels acc to ACII values

        string t = ""; // store thenew strinf=g wit sorted vowels
        int idx =0; // index pointing at the sorted vowels in the found array
        for(int i =0;i<s.length();i++){
            if(vowel.count(s[i])){ // If we find a vowel
                t+=found[idx]; // we replace it with the vowel in the found array which is sorted
                idx++;  // increse the pointer to point at the next vowelinthefound array
            }else{ // if the element is not vowel , so we just simply add it to the new string 
                t+=s[i];
            }
        }

        return t; // at last we have thestirng with vowels sorted acc to ASCII value
    }
};

/*

Setup

unordered_set<char> vowel → fast check for vowels.

vector<char> found → store vowels as we find them.

Collect vowels:

Loop through each character of s.
If it’s in vowel, append to found.

Sort vowels:

Sort found in ascending ASCII order.
Prepares the replacement order.

Build the result string t:
t = "", idx = 0

Loop through s again:
If consonant → append as-is.
If vowel → append found[idx] and increment idx.

Return t
New string has vowels in ASCII-sorted order and consonants in original positions.


Dry Run :

Step 0: Initialize
Input string: "lEetcOde"
found = [] → will store vowels.

Step 1: Traverse string to collect vowels
   i = 0, s[0] = 'l' → consonant → do nothing → found = []
   i = 1, s[1] = 'E' → vowel → add to found → found = ['E']
   i = 2, s[2] = 'e' → vowel → add to found → found = ['E', 'e']
   i = 3, s[3] = 't' → consonant → do nothing → found = ['E', 'e']
   i = 4, s[4] = 'c' → consonant → do nothing → found = ['E', 'e']
   i = 5, s[5] = 'O' → vowel → add to found → found = ['E', 'e', 'O']
   i = 6, s[6] = 'd' → consonant → do nothing → found = ['E', 'e', 'O']
   i = 7, s[7] = 'e' → vowel → add to found → found = ['E', 'e', 'O', 'e']

✅ After Step 1, found = ['E', 'e', 'O', 'e']


Step 2: Sort the vowels by ASCII:
Original vowels: ['E', 'e', 'O', 'e']
ASCII values: E=69, e=101, O=79, e=101
Sorted ascending → ['E', 'O', 'e', 'e']

✅ Sorted vowels: ['E', 'O', 'e', 'e']



Step 3: Build new string t
Initialize: t = "", idx = 0 → points to current vowel in found.
i = 0, s[0] = 'l' → consonant → t = "l" → idx = 0
i = 1, s[1] = 'E' → vowel → replace with found[idx]='E' → t = "lE" → idx = 1
i = 2, s[2] = 'e' → vowel → replace with found[idx]='O' → t = "lEO" → idx = 2
i = 3, s[3] = 't' → consonant → t = "lEOt" → idx = 2
i = 4, s[4] = 'c' → consonant → t = "lEOtc" → idx = 2
i = 5, s[5] = 'O' → vowel → replace with found[idx]='e' → t = "lEOtce" → idx = 3
i = 6, s[6] = 'd' → consonant → t = "lEOtced" → idx = 3
i = 7, s[7] = 'e' → vowel → replace with found[idx]='e' → t = "lEOtcede" → idx = 4


Step 4: Return result
Final string: "lEOtcede"
Consonants unchanged, vowels sorted by ASCII.

*/