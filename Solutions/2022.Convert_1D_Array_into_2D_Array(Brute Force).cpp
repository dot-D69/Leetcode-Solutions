//Brute Force
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> res(m,vector<int>(n)); // This is to initalize a 2D vector correctly
        if(original.size()!=m*n){ // check if the size of the original array is not greater than the size of 2D array
            return {};
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res[i][j] = original[i*n+j];  // Use to map the Original Array to the 2-D array
            }
        }
        return res;
    }
};


// vector<vector<int>> res(m,vector<int>(n));
// This line works like : the vecotr<int>(n) creates an 1-D array of size n and intializes it with 0 (as nothing else is set)
// Then vector<vector<int> creates a 2-D array res of m  rows where each column is of size n 

// res[i][j] = original[i*n+j]; 
//  if we want to fill the 1st column (0th) and 1st row(0) so we need to map to the original array using both 
// Let’s assume original = {1, 2, 3, 4, 5, 6} and we want to convert this into a 2 x 3 (i.e., m = 2, n = 3) 2D array:
// so if we want to fill the 0,0 of the 2-D array so we need the 1st element of the original array
// i=0 , j=0to2 (j<n)
// Original array = (0*3+0)= Original[0] =1
// Original array = (0*3+1)= Original[1] =2
// Original array = (0*3+2)= Original[2] =3
// We have filled the first row of the 2D array
 
// 2nd row i=1 , j = 0 to 2
// Original array = (1*3+0)= Original[3] =4
// Original array = (1*3+1)= Original[4] =5
// Original array = (1*3+2)= Original[5] =6

// That is how it works and is important to map to the 2-D array
