    class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int val =0;
        for(auto op : operations){
            if(op[1]=='-') {
                val--;
            }
            else val++;
        }
        return val;
    }
};