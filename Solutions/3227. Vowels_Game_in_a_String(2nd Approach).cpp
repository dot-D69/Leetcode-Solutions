class Solution {
public:

    bool doesAliceWin(string s) {
          for(char c :s){
            if (string("aeiou").find(c)!=string::npos){ // checks if an chararcter is an vowel in that case Alice wins
                return true;
            }
            
        }
        return false; //else if no vowel presnt so  bob wins:
    }
};

/*

1.)What find() does

s.find(ch) searches for a character ch in a string s.
Returns:
    Index (0, 1, 2 …) if the character is found.
    string::npos if the character is not found.


2.) What string::npos is

string::npos is a special constant in C++ meaning “not found”.
Internally, it’s the largest possible size_t value, not 0.
Whenever find() returns npos, it indicates the character doesn’t exist in the string.


3.) Why returning find() directly in a bool is wrong

C++ converts numbers to bool like this:
    0 → false
    Non-zero → true

If you write:
return s.find('a'); // inside a bool function
    'a' at index 0 → returns 0 → interpreted as false ❌
    'x' not found → returns npos (huge number) → interpreted as true ❌

So direct return gives wrong results for boolean functions.


4.) Correct way: compare with npos
    return s.find('a') != string::npos;
    Character found: index != npos → true ✅
    Characer not found: index == npos → false ✅
Works correctly even if the character is at index 0.
*/