class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string res ="";
        for(int i =0;i<n-2;i++){
            if(num[i]==num[i+1] && num[i+1]==num[i+2]){
                string temp = num.substr(i,3);
                res= max(res, temp);
            }

        }
        return res;

    }
};

/*

Well, we need to iterate over the String num
but first we need a var to store the max substring.
So we Intialize an empty String res

Now we iterate the array from index 0 to n-2 why?

Because we will also be checking for each index if the next two digits are equal ( if (num[i]==num[i+1]==num[i+2])).
so to prevent overflow we go from 0 to n-2

Now we check if the three digits from the current position are same
If they are the same we store them in a temp variable.
And compare with res to get the max, and store it in res.

We will compare the string stored in temp each time with res , whenever we find a 3 digit same number.

Then we simply return the res( as it will be containing the max substring)

If we don't find any 3 digit same number w enever eneter the condition and return an empty res string

*/