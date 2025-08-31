class Solution {
public:
    
    bool isValid(vector<vector<char>>& board,int row,int col,char d){
        //Row Validity
        for(int i=0;i<9;i++){
            if(board[row][i] ==d) return false;
        }

        //col validity 
        for(int i=0;i<9;i++){
            if(board[i][col]==d) return false;
        }

        //3*3 Box validity
        int start_i =  row/3 *3;
        int start_j = col/3 *3;

        for(int k=0;k<3;k++){
            for(int l=0;l<3;l++){
                if(board[start_i+k][start_j+l] == d) return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char d ='1';d<='9';d++){
                        if(isValid(board,i,j,d)){
                            board[i][j] = d; // Do
                            if(solve(board) ==true) return true ; // Explore
                            board[i][j] = '.'; // Undo
                        }
                    }
                    return false;
                }

            }
        }
        return true; // THIS MEANS WE DID NOT ENCOUNTER ANY EMPTY CELLS "." , Since the board was already filled, so we just return 
        //If the board was not already filled we would have returned a true or a false and would have never cam to this in the code
    }


    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

/*

Let's just visualise how we solve sudoku actually:

First we find an empty cell and fill it with a number say 3 (given that the number 3 is not repeated in the row or col or the box we are filling the empty cell in)

Then we move to the next empty cell and do the whole thing again

Now it is possible that in future when we have filled some of the cells , we go to fill the an empty cell and then we realise that the cell we filled with number 3 in the starting is wrong

So now we have to redo the whole suduko with another number , and empty all the celss we have filled tiil now ( exhaussting i know but that is how you solve a sudoku)

Basically we are : DO --> Explore -->UNDO
This is Backtracking

In this program also we are doing the same thing


First we have a solve function:
  i.) It iterates over the whole 9*9 grid

  ii.) if it finds an empty cell (board[i][j]=='.')
     
      Then we have to check if the number we are about to fill in the empty is valid or not(means it should not be present in the row or the col the box we arwe about fill cell in is)

    iii.) If the number is valid we then fill the cell with the number (Here we have updated our board )   {THIS IS OUR "DO"}
      
   iv.)  Then we pass the updated board to the solve function to look for other empty cells and do the whol process again   {THIS IS OUR "EXLORE"}
    If while the solve function is being called recursivelt and it returns true that means we have silved the whole sudoku so we just return from here

    v.) If not it means in the future somewhere we were not able to solve because putting the board[i][j] == d(is not helping us solve)
    So we board[i][j] = '.' {UNDO}
    

    //If after doing the whole thins we are not able to return true, means it is not being solved , so we return false;

    At the end of solve function we return true (It shows that the whole grid was already filled)




    NOW COMING TO THE isValid function:

    We just have to check 3 things

  1.)   //Each of the digits 1-9 must occur exactly once in each row.
        for(int i=0;i<9;i++){
            if(board[row][i] ==d) return false;
        }
  2.)   //Each of the digits 1-9 must occur exactly once in each column. 
        for(int i=0;i<9;i++){
            if(board[i][col]==d) return false;
        }
    
  3.) //Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
    
        To check this first we need to find the box we are in and in order to that  we need to find the starting row and col a-of that box

        How can we dop that, suppose we are at index gird[i][j] [4][7] (Now ot find the box this cell is in ) we do:

        start_i = i/3 *3 ---> 4/3 *3 ---> 1*3 = 3
        start_j = j/3*3 ---> 7/3 *3  ---> 2*3 = 6

        so we get that our box starts at (3,6) Now we know where the box is at 
        Now from 3,6 we just need to look 2 cells to it's right and 2 cells to it's bottom( as we are at the starting so the box can only be in the righ and bottom direction and since the box is given 3*3 so we only need to traverse two more cells in both direction)

         for(int k=0;k<3;k++){
            for(int l=0;l<3;l++){
                if(board[start_i+k][start_j+l] == d) return false;
            }
        }


        If none of them return false, then we return true, indicating that the given number we are trying to insert in grid is valid



*/





























