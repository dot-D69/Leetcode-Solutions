class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int unplaced = 0;
        vector<bool> used (n,false);
        for(auto f: fruits){
            bool placed = false;
            for(int i=0;i<n;i++){
                if(baskets[i]>=f && used[i]==false){
                    placed = true;
                    used[i] = true;
                    break;
                }
            }
             if(placed == false){
                    unplaced++;
                }
        }
        return unplaced;   
    }
};