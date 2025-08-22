class Solution {
public:
//Recursion+Memoization
    int m,n; // class variable, so that we don't have to explicitly pass them in every functin within the class

    int solve(int i,int j,vector<vector<int>>& matrix, vector<vector<int>>&t){
        if(i>=m || j>=n) return 0; //if we reach the end then we need to return 

        if(matrix[i][j] == 0) return 0; // if the element encourtered while searching is a zero , then we need to return 0 , as the submatrix has to only contain of 1's

        if(t[i][j] != -1){//Check if the condition being called is already computed
            return t[i][j]; // If yes, then simply return it , no need to compute it again
        }
        
        int right = solve(i,j+1,matrix,t); // Goes to right to check for 1s
        int diagonal = solve(i+1,j+1,matrix,t);// Goes diagonally to check for 1s
        int bottom = solve(i+1,j,matrix,t);// Goes to bottom to check for 1s

        return t[i][j] = 1+min({right,diagonal,bottom}); // We add 1 for the element (i,j) that we are currently onme for which all the neioghbours are being checked, as that element is also a 1, so that we have atleast 1 submatrix that is the element itself
    }

    int countSquares(vector<vector<int>>& matrix) {
       m = matrix.size();
       n = matrix[0].size();
       int res =0; // To store the count of all the submatrixes returned
       vector<vector<int>>t (m,vector<int>(n,-1)); // Cache used for memoization

//To Traverse through the matrix we need a nmested for loop so that every element is visited
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            res+=solve(i,j,matrix,t);  // call a recursive fuinction that will check in all three directions(right, diagonal, bottom) and then return the answer, store the answer in res, the move onto the next element and do it all again
        }
       }
       return res; // return the answer stores of all the submatrices
    }
};