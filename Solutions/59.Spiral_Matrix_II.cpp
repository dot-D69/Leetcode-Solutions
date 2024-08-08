class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0)); // create a 2-D matrix
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int num=1;

        while (top <= bottom && left <= right) {
            // Right
            for (int i = left; i <= right; i++) {
                matrix[top][i]=num++;
            }
            top++;

            // Down
            for (int i = top; i <= bottom; i++) {
                matrix[i][right]=num++;
            }
            right--;

            // Check if there are more rows to process
            if (top <= bottom) {
                // Left
                for (int i = right; i >= left; i--) {
                    matrix[bottom][i]=num++;
                }
                bottom--;
            }

            // Check if there are more columns to process
            if (left <= right) {
                // Up
                for (int i = bottom; i >= top; i--) {
                    matrix[i][left]=num++;
                }
                left++;
            }
        }
        return matrix;
    }
};


// vector<vector<int>> matrix(n,vector<int>(n,0));
// The way this works is first we create a 2D matrix of size 3 
/*
[[],[],[]]
inside the 2D matrix we create a another array or coloumns of the matrix of the same size as the size of the matrix (i.e. n^2)
vector<int> (n,0) means  [0,0,0]

so for every n=3 in each of the matrix row we have anotehr matrix which is [0,0,0]
[[0,0,0]
 [0,0,0]
 [0,0,0]
]

Then it's simple we do what we did in Spiral Matrix I and insert the num into the matrix and increase the num count



*/
