class Solution {
public:

    bool isPalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void get_partition(int index,string s,vector<string> &store,vector<vector<string>> &result){
        if(index==s.size()){
            result.push_back(store);
            return;
        }

        for(int i =index;i<s.size();++i){
            if(isPalindrome(s,index,i)){
                store.push_back(s.substr(index,i-index+1));
                get_partition(i+1,s,store,result);
                store.pop_back();
            }
        }

    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> store;
        get_partition(0,s,store,result);
        return result;
        
    }
};

/*
Time Complexity: O(n*2^n)
Space Complexity: O(n)
*/