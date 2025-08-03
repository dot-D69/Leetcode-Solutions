class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> result (rowIndex+1);

        for (int i=0;i<result.size();i++){
            result[i] = vector<int> (i+1,1);
            for(int j=1;j<i;j++){
                result[i][j] = result[i-1][j]+result[i-1][j-1];
            }
        }
        return result[rowIndex];
        
    }
};


// Refer to solution no 118, same logic and same code.s