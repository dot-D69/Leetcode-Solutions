class Solution {
public:

    bool magicGrid(vector<vector<int>>& grid,int r, int c){
        unordered_set<int> st;
       
        // checking all elements are in range of 1 to 9 and are non repeating
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int num = grid[r+i][c+j];
                if(num <1 ||  num>9 || st.count(num)){
                    return false;
                }
                else{
                    st.insert(num);
                }
            }
        }

        int SUM = grid[r][c]+grid[r][c+1]+grid[r][c+2];
        // check the rows sum and cols sum
        for(int i=0;i<3;i++){
            if(grid[r+i][c]+grid[r+i][c+1]+grid[r+i][c+2] !=SUM ){  // This calculates sum of all the rows  if i=0 r=0 c changes to calculate sum of all ele of r=0 , then i=1 so r=1 again same 
                return false;
            }

            if(grid[r][c+i]+grid[r+1][c+i]+grid[r+2][c+i] != SUM){ // Calculate sum of the cols if  i=0 c=0 r changes and gets all ele for c=0 , similarily for i=1 c=1 it repeats
                    return false;
            }
        }

        //Diagonal sum
        if(grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2] != SUM){
            return false;
        }

        //Antidiagonal sum
        if(grid[r+2][c]+grid[r+1][c+1]+grid[r][c+2] != SUM){
            return false;
        }

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int count=0;
        for(int i=0;i<=rows-3;i++){  // for a 3*3 grid if rows =4 so we can only form a 3*3 grid if we start form rows=4-3 =1
            for(int j=0;j<=cols-3;j++){ // for a 3*3 grid if cols =3 we can form a 3*3 grid only if we start form cols =3-3=0
                if(magicGrid(grid,i,j)){
                    count++;
                }
            }
        }
        return count;
    }
};
