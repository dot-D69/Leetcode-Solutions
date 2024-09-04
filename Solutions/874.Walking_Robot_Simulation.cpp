class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obst;
        for(vector<int> it: obstacles){
            string key = to_string(it[0])+"_"+to_string(it[1]);
            obst.insert(key);
        }


        int x=0;
        int y=0;
        int maxED=0;

        pair<int,int> dir ={0,1}; //pointing to North

        for(int i=0;i<commands.size();i++){
            if(commands[i]==-1){ // Then rotate 90 degree right;
                dir = {dir.second,-dir.first}; // (x,y) -->(y,-x)
            }
            else if(commands[i]==-2){ // Then rotate 90 degress left;  
                dir = {-dir.second,dir.first}; // (x,y) -->(-y,x)
            }
            else{
                //Move in the direction step by step 
                for(int step=0;step<commands[i];step++){
                    int X= x + dir.first;
                    int Y = y + dir.second;
                    string Key = to_string(X) +"_"+ to_string(Y);

                    if(obst.find(Key)!=obst.end()){
                        break;
                    }
                    x=X;
                    y=Y; 
                }
            }
            maxED = max(maxED,x*x+y*y);
        }


        return maxED;
    }
};


//ROTATING 90 DEGREE LEFT
/* N->(0,1)
   E->(1,0)
   S->(0,-1)
   W->(-1,0)

    IF IT FACING NORTH THEN (0,1) IF ROTATES 90 DEGREE LEFT THEN IT FACES WEST (-1,0)  [x=0 y=-1 --- x=-1 y=0]
    IF IT FACING EAST  THEN (1,0) IF ROTATES 90 DEGREE LEFT THEN IT FACES NORTH (0,1) [x=1 y=0 --- x=0 y=1]
    IF IT FACING SOUTH  THEN (0,-1) IF ROTATES 90 DEGREE EAST THEN IT FACES NORTH (1,0) [x=0 y=-1 ---- x=1 y=0]

    from the above movements we observe that whenever we are rotating to left , if the curr pos is (x,y) so after rotating the new pos is (-y,x)
    i.e. if pos was (0,1) after rotating (-1,0) , if pos was (1,0) after rotating (0,1) , if pos was (0,-1) after rotating (1,0)


    SIMILARLY FOR ROTATING 90 DEGREE RIGHT  (x,y) ---> (y,-x)
    IF IT IS FACING SOUTH (0,-1) THEN AFTER ROTATING IT FACES WEST (-1,0) [(x,y) ---> (y,-x)]
    IF IT IS FACING EAST (1,0) THEN AFTER ROTATING IT FACES SOUTH (0,-1) [(x,y) ---> (y,-x)]
    IF IT IS FACING NORTH (0,1) THEN AFTER ROTATING IT FACES EAST (1,0) [(x,y) ---> (y,-x)]
*/

// IN THE STARTING THE ROBOT IS FACING NORTH SO OUR INTIAL DIRECRTION WILL BE (0,1), FROM HERE WE WILL SEE IF MOVES LEFT RIGHT OR AHEAD

// We store the direction in set as it is easier to retrieve and compare , we store the obstacle in a string format to facilitate comparison

// e.g if obstacle ({2,4}) we store it in string "2_4" to aovid confusion, if we stored it like "24" then it would be dififcult to identitfy the x and y co-ordinates

// Once we have our obstacle and rotation sorted then it becomes a really easy question

// Flow of the solution:
/*
    We will start to go through each of the elements of command array:
    if command[i] == -1 then we will rotate right according to the above logic
    if command[i] == -2 then we will rotate left according to the above logic

    if command[i] = k , then we need to move step by step
    // so we run a loop that start from 0 to k
    // each time we add x and y coordinates to the prev x,y 
    // convert the new x and y to string and like "x_y"
    // then compare them to the string we made of the obstacle in our set
    // if the string matches the setring in the set then we break from the loop i.e. do not move the next step
    // if not then at the end  we make our x and y as the new x and new y and exit the loop

    // We also constantly calculate the max ED that we obtain at the last i.e. the x and y that we get  from the previous loop in which we were moving step by step

    // at last we return the maxED
*/
