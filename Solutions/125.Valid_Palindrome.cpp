class Solution {
public:
    bool Palindromechecker(int left, int right, string s){
        if(left>=right){
            return true;
        }
        while (left < right) {
    
        while (left < right && !isalnum(s[left])) { // skip the alphaumeric values
            left++;
        }
        while (left < right && !isalnum(s[right])) {  //skip the alphanumeric values
            right--;
        }

        if(tolower(s[left])!=tolower(s[right])){  // Convert to lowercase to compare
            return false;
        }
        left++;
        right--;
        
        }

        return Palindromechecker(left+1,right-1,s);
    }
    bool isPalindrome(string s) {
        int left=0;
        int right = s.length()-1;

        if(Palindromechecker(left,right,s)){
            return true;
        }
        return false;
    }
};