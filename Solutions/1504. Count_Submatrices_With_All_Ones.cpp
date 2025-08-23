class Solution {
public:
    int subCount( vector<int> &temp){ /// simple just checks if the curr ele is 1 , if it is updates curr count and add it to total count, this is how we find all the submatrices in 1D array
        int curr_cnt = 0;
        int total_cnt =0;

        for(int x : temp){
            if(x==0){
                curr_cnt =0;
            }
            else{
                curr_cnt++;
            }
            total_cnt+= curr_cnt;
        }
        return total_cnt;
    }


    int numSubmat(vector<vector<int>>& mat) {
        int m  = mat.size(); 
        int n = mat[0].size();
        int res = 0; // To store the count of all the submatrices

        for(int stRow =0;stRow<m;stRow++){ // StartRow  is fixed, util all the rows from start to end are traversed
            vector<int> temp(n,1); // we assume in starting that all cols are valid for submatrix
            for(int endRow =stRow;endRow<m;endRow++){ // Traverse all the rows from start to the end
                for(int cols = 0;cols<n;cols++){
                    temp[cols] = temp[cols] & mat[endRow][cols]; // We check if our assumtion s true or if there are any zeroes, If there are the vec will update , since 1&0 =0;
                }

                res+= subCount(temp); // To ge the count of submatices of 1D array we use this
                //whatever countis return is stored in res,after very iteration res is updated
                //At last res will have the count of al submatrices of 1 in the 2D matrix
            }
        }
        return res;
    }
};


/*

Example to Dry Run
mat = [
  [1, 0, 1],
  [1, 1, 0]
]


We’ll trace it exactly with your code.

Step 1 – Outer Loop (stRow = 0)

Initialize temp = [1,1,1].

Inner Loop (endRow = 0)

Row0 = [1,0,1]

temp = [1&1, 1&0, 1&1]
     = [1,0,1]


Call subCount([1,0,1]):

x=1 → curr_cnt=1, total=1

x=0 → curr_cnt=0, total=1

x=1 → curr_cnt=1, total=2

returns 2

Submatrices found here:

(r0,c0) 1×1

(r0,c2) 1×1

res = 0+2 = 2

Inner Loop (endRow = 1)

Row1 = [1,1,0]

temp = [1&1, 0&1, 1&0]
    = [1,0,0]


Call subCount([1,0,0]):

x=1 → curr_cnt=1, total=1

x=0 → curr_cnt=0, total=1

x=0 → curr_cnt=0, total=1

returns 1

Submatrices found here:

(r0..1, c0) → 2×1
res = 2+1 = 3


Step 2 – Outer Loop (stRow = 1)

Reset temp = [1,1,1].

Inner Loop (endRow = 1)

Row1 = [1,1,0]

temp = [1&1, 1&1, 1&0]
    = [1,1,0]


Call subCount([1,1,0]):

x=1 → curr_cnt=1, total=1

x=1 → curr_cnt=2, total=3

x=0 → curr_cnt=0, total=3

returns 3

Submatrices found here:

(r1,c0) → 1×1

(r1,c1) → 1×1

(r1,c0..1) → 1×2

res = 3+3 = 6

Final Result = 6



All Submatrices Found

(r0,c0) → 1×1
(r0,c2) → 1×1
(r0..1,c0) → 2×1
(r1,c0) → 1×1
(r1,c1) → 1×1
(r1,c0..1) → 1×2


*/