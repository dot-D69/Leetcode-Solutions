class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n =matrix.size();
        //Transpose the matrix (rows becomes columns, columns becomes rows)
        for(int i=0;i<n-1;i++){ //  it means form 0 to second last as (i<n is last) so i<n-1  is second last
            for(int j=i+1;j<n;j++){ // it means we travese from i+1 to the last
                swap(matrix[i][j],matrix[j][i]);
            }
        }
// now we have transposed now to get our answer we need to reverse every row so that it is acc to our answer
        for(int i=0;i<n;i++){
            //since each row is represened by matrix[i] so we will use that
            reverse(matrix[i].begin(),matrix[i].end());
        }

        
    }
};