class Solution {
public:

    void get_comb(int i ,string digits,unordered_map<char,string> &map,string &temp, vector<string> &result){

        if(i==digits.length()){
            result.push_back(temp);
            return;
        }

        string str = map[digits[i]];
        for(int j=0;j<str.length();j++){

            temp+=str[j];
            get_comb(i+1,digits,map,temp,result);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        unordered_map<char,string> map;
        
	    map['2']="abc";
	    map['3'] = "def";
	    map['4'] = "ghi";
	    map['5'] = "jkl";
	    map['6'] = "mno";
	    map['7'] = "pqrs";
	    map['8'] = "tuv";
	    map['9'] = "wxyz";

        vector<string> result;
        string temp;

        if(digits==""){
            return result; 
        }

        get_comb(0,digits,map,temp,result);
        return  result;
    }

};