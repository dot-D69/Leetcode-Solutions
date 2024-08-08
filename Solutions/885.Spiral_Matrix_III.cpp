class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> Directions = {{0,1},{1,0},{0,-1},{-1,0}}; // {East,South,West,North}
        vector<vector<int>> res; // To store the result
        int steps=0; // to keep the count of steps
        int d = 0; // intial direction is 0 as the first move will be towards East
        res.push_back({rStart,cStart}); // The Starting cell will be pushed to the res as it is the starting point
        
        while(res.size()<rows*cols){

            if(d==0 || d==2) steps++; // If the direction is East or West Increase the step count

            for(int i=0;i<steps;i++){
                rStart+=Directions[d][0]; // it adds the x co-ordinate to rstart (i.e (x,y)->(x+dir[0] ,y))
                cStart+=Directions[d][1]; // it adds the y co-ordinate to cstart (i.e (x,y)->(x, y+dir[0]))

                if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols){ //it checks if it has not run out of bound 
                res.push_back({rStart,cStart});
                }
            }
            d=(d+1)%4; // To reset the direction to East (as E->S->W->N) as for spiral it will keep counting
        }
        return res;
    }
};
