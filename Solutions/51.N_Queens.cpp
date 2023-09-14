class Solution
{
public:
    bool follows(int n, int col, int row, vector<string> place)
    {
        int ROW = row;
        int COL = col;

        while (row >= 0 && col >= 0)
        { // for diagonally upward
            if (place[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        row = ROW;
        col = COL;
        while (col >= 0)
        { // horizontally backward
            if (place[row][col] == 'Q')
                return false;
            col--;
        }

        row = ROW;
        col = COL;
        while (row < n && col >= 0)
        { // diagonally downward
            if (place[row][col] == 'Q')
                return false;
            row++;
            col--;
        }

        return true;
    }

    void position(int n, int col, vector<string> &place, vector<vector<string>> &result)
    {
        // Base case
        if (col == n)
        {
            result.push_back(place);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (follows(n, col, row, place))
            {
                place[row][col] = 'Q';
                position(n, col + 1, place, result);
                place[row][col] = '.'; // Backtrack: Reset the cell
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> result;
        vector<string> place(n, string(n, '.'));
        position(n, 0, place, result);

        return result;
    }
};



