class Solution {
public:
    bool notpicked(vector<int>& selected , string curr){
        vector<int> Curr_check(26,0);
        for(int i =0;i<curr.size();i++){
            if(Curr_check[curr[i]-'a']==1) return false;
            Curr_check[curr[i]-'a']=1;
        }

        for(int i =0;i<curr.size();i++){
            if(selected[curr[i]-'a']==1) return false;
        }
        return true;
    }

    int get_len(int i,vector<string>& arr, vector<int>& selected, int len){
        //Base case

        if(i==arr.size()){
            return len;
        }


        string curr_str = arr[i];
        if(notpicked(selected,curr_str)==false){
            return get_len(i+1,arr,selected,len);
        }
        else{
            //pick
            for(int j=0;j<curr_str.size();j++){
                selected[curr_str[j]-'a']=1;
            }
            len+=curr_str.size();
            int pick = get_len(i+1,arr,selected,len);

            //skip;
            for(int j=0;j<curr_str.size();j++){
                selected[curr_str[j]-'a']=0;
            }
            len-=curr_str.size();
            int skip = get_len(i+1,arr,selected,len);

            return max(pick , skip);

        }
    }

    int maxLength(vector<string>& arr) {
        vector<int> selected(26,0);
        return get_len(0,arr,selected,0);
        
    }
};



/*
Explanation:
1. We have to find the maximum length of the string that can be formed by concatenating the strings in the given array.
2. We will use backtracking to solve this problem.
3.What we are basically doing is checking if the current character is already present in the selected array or not.
4. To check for the characters we will use a vector of size 26 and will mark the character present in the string as 1.
4. If it is present then we will not take that string as it means that a duplicate character is present in the string or a string having same character is choosen and thus the present string cannot be concatenated.
5. To do  that we use a boolean function notpicked which checks if the current string is valid or not.
6. If it is not valid so will move to the next index and check for the next string.
7. if the string is valid then we:
            //Pick
            i.) we will first run a for loop so that we coul mark all character present in the string as 1 in the selected array.( we do that using curr_str[j]-'a' it works like this if curr_str[j] is 'e' then 'e'-'a' = 4 and thus we mark the 4th index as 1 in the selected array)
            ii.) we will increase the length by the length of the current string.
            iii.) we will call the function again with the next index and the updated length.

            //Skip
            i.) we will again run a for loop so thqt we could unmark all the chracters that we marked while picking the string since we are not picking the string now so we have to unmark the characters.
            ii.) we will decrease the length by the length of the current string.
            iii.) we will call the function again with the next index and the updated length we store the valuue of length returned by this  in skip variable as we have to return the maximum of the string we obtain by picking and skipping the string.

8. We will return the maximum of the pick and skip variable.


// The boolean function:
    1. the first conddition checks if the string itself doesn't have duplicate characters. eg: "abca"
        to do this we initalize a vector that is of length 26 so and mark all the characters present in the string as 0.
        then we run a for loop inside the for loop we 
        i.) check if the character is already present in the vector if it is present then we return false.
        ii.) if it is not present then we mark the character as 1 in the vector.
    2. the second condition checks if the string is already present in the selected array or not.
        to do this we run a for loop and check if the character is present in the selected array if it is present then we return false.
        if it is not present then we return true.


Time Complexity: O(2^n)
Space Complexity: O(n)
*/

