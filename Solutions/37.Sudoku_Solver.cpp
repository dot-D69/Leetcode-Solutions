class Solution
{
public:
    bool follows(vector<vector<char>> &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == c)
                return false;

            if (board[i][col] == c)
                return false;

            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        Solve(board);
    }

    bool Solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                if (board[i][j] == '.')
                {

                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (follows(board, i, j, c))
                        {
                            board[i][j] = c;
                            if (Solve(board) == true)
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};

/*
EXPLANATION:

The idea is to use backtracking. We first assign values to the cells which are empty. We check if the value is valid or not. If it is valid, we continue with the next cell. If it is not valid, we try a different value. If all the values are exhausted, we return false.



we star from col = 0, row = 0 and check if the cell is empty or not. If it is empty, we try to fill it with a value from 1 to 9. If the value is valid, we continue with the next cell. If the value is not valid, we try a different value. If all the values are exhausted, we return false.

To check for validity use the function follows (vector<vector<char>>& board,int row,int col,int c)  we run a loop from 0 to 8 
    i.) first we check if the any value from 1 to 9 is present in the row or not. If it is present, we return false. we get the c as parameter which is the value we are trying to fill in the cell.
    ii.) second we check if the any value from 1 to 9 is present in the column or not. If it is present, we return false.
    iii.) third we check if the any value from 1 to 9 is present in the 3*3 matrix or not. If it is present, we return false. to find that we use formula board[3*(row/3)+i/3][3*(col/3)+i%3] where i runs from 0 to 8.


After checking for validity we return to SOlve function 
    if the Follows function returned  true, so we fill the cell with the value and call the Solve function again.
    Which then recursively calls and check for each empty if there are any valid values or not. If there are no valid values, it returns false and we backtrack and try a different value.



    we start from col = 0, row = 0 and check if the cell is empty or not. If it is empty, we try to fill it with a value from 1 to 9. If the value is valid, we continue with the next cell. If the value is not valid, we try a different value. If all the values are exhausted, we return false.

    we try to fill the cell with 1, we check if it is valid or not. If it is valid, we continue with the next cell. If it is not valid, we try a different value. If all the values are exhausted, we return false.


The time complexity of the above algorithm is O(9^(n*n)). In the worst case we have 9 choices for each of the n*n cells.
The space complexity of the above algorithm is O(n*n). This is the space required for the recursion stack.

*/