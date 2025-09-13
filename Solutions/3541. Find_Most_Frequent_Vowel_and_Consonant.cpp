class Solution {
public:
    int maxFreqSum(string s) {
        //TO maintain the count of vowels and consonant
        int vowel = 0;
        int consonant =0;
        
        //This arr helps us to store the count of the characters and since it is fixed so spacee is just O(1)
        int arr[26] ={0};// Intiallize all to 0

        for(char &ch: s){
            arr[ch-'a']++;//when we do ch-'a' it returns a int value , which is the position or the value of the character from a, like if the character is e it will returns 4 (as it subtracst the ascii value of e from a i.e 101-97)
// So at index 4, that is the fifth position willbe incremented to 1 indicating we have one e in the string and so on for all the characters in the string

            if(string("aeioiu").find(ch)!=string::npos ){// This condition checks if the selected character is a vowel
                vowel = max(vowel,arr[ch-'a']); //If it is we update the value of vowels to the the max of all the vowels we wil fidn through out the string
            }
            else{
                consonant  = max(consonant,arr[ch-'a']);//similiar thing for consonants
            }
        }
        return consonant+vowel;
    }
};