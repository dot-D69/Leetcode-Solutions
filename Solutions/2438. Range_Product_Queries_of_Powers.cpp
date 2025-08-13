class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int MOD = 1e9+7;
        vector<int> Powers;
        vector<int> res;

        for(int i=0;i<32;i++){
            if((n& (1<<i)) != 0){ //it checks if the ith bit is set
                Powers.push_back(1<<i); // We add the power of 2 that has the set bit (i.e if 0 is the set bit then 1<<i means 2^0,if 4 is the set bit then 1<<i means 2^4 ... )
            }
        }
        // We obtain our Powers set


        // now we on,y need to find the product of the elements in the power set from start to end as mentioned in each queries element
        for(auto &q: queries){
            int start = q[0];
            int end = q[1];

            long  product  =1; // The result can get longer 
            for(int i=start;i<=end;i++){
                product= (product *Powers[i])%MOD; // Modulo with 1e9+7
            }
            res.push_back(product);// store the product in result for each query element
        }
        return res;// Return the result
    }
};