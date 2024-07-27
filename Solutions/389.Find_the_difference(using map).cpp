class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp;
       for(char c:t){
        mp[c]++;
       }

       for(char c:s){
        mp[c]--;
       }

       for(auto pair:mp){
        if(pair.second==1){
            return pair.first;
        }
       }
        return '0';   
    }
};

//we use unordered map to get the xtra character from the strings

//we are basically counting the frequency of each item in every string

// Since the string is always going to be greater than the String s , so first we will add the char and their frequency in the map
// right now every element has a frequency of 1

// now we run the same thing for string s and every time we find a element we have in our map we reduce it's frequency 
// in last we will only have the extra element frequency as 1, which will be our answer

// To get the element from the map we use pair, iterate through the map and then check for the pair that has freq has 1 return the first of that pair
