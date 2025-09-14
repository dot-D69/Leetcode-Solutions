class Solution {
public:
    set<string> Exactst;
    unordered_map<string,string> lowerMp;
    unordered_map<string,string> vowelMp;

            string toLower(string s) {  //funtion to convert tstring to its lowercase
            string result = s;
            for(char &c:result){
                c = tolower(c);
            }
            return result;
        }

        string replaceVowel(string s){
            string result = s;
            for(char &ch: result){
                ch = tolower(ch);
                if(ch=='a'||ch=='e'||ch=='i'|| ch=='o'|| ch =='u'){
                    ch = '*';
                }
            }
            return result;
        }

        string matchCheck(string &query){
            //Check if the the exact string matches
            if(Exactst.count(query)) return query;

            //For Lowercase check we first need to make given query string in to its lowercase , so that when we check the map , the map returns the key for the lowercase value of query

            string lower = toLower(query);
            if(lowerMp.count(lower)) return lowerMp[lower];

        //For Vowel match we need to two thinhgs first conver the string into its lowercase and then replace it;s vowel with *,  in replace vOwel both are handled
            string vowel = replaceVowel(query);
            if(vowelMp.count(vowel)) return vowelMp[vowel];

            return "";

        }


    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {




        for(string &str:wordlist){
            //Puts same words into theset for O(1) Lookup in exact matcxh case
            Exactst.insert(str);

            string Lowercase = toLower(str); //Converts the string to it's Lowercase to avoid lowercase Error

            if(!lowerMp.count(Lowercase)){ //If already not present in the map so we add the lowercase string (we don't add again if already present becuase we want the first Occurence)
                lowerMp[Lowercase] = str; // "kite" --> "KiTe"  since we will searching for lowecase letters
            }

            string vowel = replaceVowel(Lowercase); // Replace the vowels in the string to * so that two strings such as kite and keto become the same "k*t*" so there is no vowel error .Also if the string is Like KiTE we first make it lowe rthen change to "k*t*"
            if(!vowelMp.count(vowel)){ //Same if not already presnet we add it to the map 
                vowelMp[vowel] = str;  // "k*t*" --> "KiTe"
            }
        }

        vector<string> res;
        for(string &q: queries){ //Go thorugh the quesries
            res.push_back(matchCheck(q)); //If we find a match then we put it in the res
        }

        return res;
        
    }
};