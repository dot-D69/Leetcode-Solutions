class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int curr =1;
        int prev =0;
        int res = 0;

        while(curr<colors.size()){
            if(colors[curr]==colors[prev]){
                res += min(neededTime[curr],neededTime[prev]);

                if(neededTime[curr]>neededTime[prev]){
                    prev = curr;
                }
            }else{
                prev = curr;
            }
            curr++;
        }
        return res;
    }
};