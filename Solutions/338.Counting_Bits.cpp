class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        
        for(int i=0;i<n+1;i++){
            bitset<sizeof(int)*8> binary(i); // the bitset converts integer to binary form using the sizeof(int)*8 bits
            ans[i]=binary.count(); // count() counts the number of 1's in the binary form and stores it in ans[i]
        }
        

        return ans;
        
        
        
    }
};
