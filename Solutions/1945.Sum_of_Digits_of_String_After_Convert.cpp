class Solution {
public:
    int getLucky(string s, int k) {
        string num="";

        for(char &ch : s){
            int chr = ch-'a' + 1; // convert number to its corresponding no. such as'a'->1 , 'b'->2 and so on
            num+= to_string(chr);
        }
        
        int sum =0;
        while (k--){
            sum =0;
            for(char &ch : num){
                sum+= ch-'0';// converts the given char to int type
            }

            num = to_string(sum); // to convert the obtained sum into string and store it in num for the next iteration
        }

        return stoi(num);  //string to int because the return type is int

    }
};
