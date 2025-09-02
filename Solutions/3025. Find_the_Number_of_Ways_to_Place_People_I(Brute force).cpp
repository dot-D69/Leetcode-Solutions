class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int count =0; // to count the number of valid pairs;

        for(int i=0;i<n;i++){
            // This is Point A
            int xa = points[i][0];  //X co-ordinate of point A
            int ya = points[i][1];  //y co-ordinate of point A

            for(int j=0;j<n;j++){
                if(i==j) continue; //We don't want A and B points to be equal 
                //It checks if k is equal to or i , if we don't then we make take up the sam epair of point as A and we don't want that  (A and B should be different only then we can compare them with the given rules)

                //This is point B
                int xb = points[j][0];  //x co-ordinate of point B
                int yb = points[j][1]; //y co-ordinate of point B

// Now to check the first condition whther or not A is Upper left of B
//It is only possible when the x of a is less than xof b and Y of a is greater than y of b  {xb>xa && ya>yb}
//Alos thorugh the third example it becomes clear to us that we don't need them to be strictly upper left (A just should not be  at right ) so we can use (xb>=xa  && ya>=yb)  This ensure the upper left Constraint as it should be

                if(xb>=xa && ya>=yb){
                    bool valid = true; //We keep a vlaid flag so that after the second check it becomes invalid so we an update it, right now it's valid

                    //Now we the third point form the points arr to check it is between A or B
                    for(int k=0;k<n;k++){
                        if(k==i || k==j) continue; //We cannot take same Point As Aor b , else then how will we check the if thereis any point in between or not,

                        //This the Third point say c
                        int xc = points[k][0]; //x co-ordinate of point C
                        int yc = points[k][1]; //y co-ordinate of point C

//So till now we have gotten our A and B points pair and also checked whther or not A satisfy the upperLeft condition as mentioned
//We  have also find our third point for which we will check if it is between A and B, Till now the valid is true because the pair passd the first check

//Now to check if the Point C is between A and B or not ---> if a point is between two it is generally denaoted as:
// xa<=xc<=xb  and yb<=yc<=ya    {yb<yc and ya>yc  since ya >= yb}
// So using the baove formula we do: xc>=xa && xc<=xb && yc<=ya && yc>=yb )===> If this condition is met it means there is point between Aand B so we make the valid flag as false

                        if(xc>=xa && xc<=xb && yc<=ya && yc>=yb ){
                            valid = false;
                        }
                    }
//After we have checked all the case and gotten all the points A and B we then check if valid is true --> it means the pair is valid and increase the count
                    if(valid){
                        count++;
                    }
                }

            }

        }
        return count;
    }
};

// Time Complexity: O(n^3) where n is the number of points
// Space Complexity: O(1) since we are using only a constant amount of extra space