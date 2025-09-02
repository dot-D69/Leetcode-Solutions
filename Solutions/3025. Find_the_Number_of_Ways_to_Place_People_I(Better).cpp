class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int  n = points.size();
        int count =0;

//Since we were checking for the xb>=xa and ya>=yb in the points to check if we A is upper left,
//  we used have to go through the whole array just to check this
//If we sort the points based on x then we can just get the points in an order where the next point will always be on right since it is sorted 
// xb has to be greater than xa so  if i take my A point at index = 2 , so i don't have to check index 0 and 1 since the greater xb will always be on right as the array is sorted.


// Now there is a corner case also where if xa == xb then we nedd to sort based on y in descending order (The corner case is dicuseed in the last check there )

        auto lambda = [](vector<int> point1, vector<int> point2 ){ //The lamabda is for the corner case where if x are eqaul then we sort on basis of Y
                    if(point1[0]==point2[0]){
                        return point1[1] > point2[1];
                    }
                    return point1[0]<point2[0];
                };
        sort(points.begin(),points.end(),lambda); // sorting so that we can get the Point B always at right in that manner we won't have to visit every index of the array

        for(int i=0;i<n;i++){
            //Point A
            int xa = points[i][0];  //X co-ordinate of point A
            int ya = points[i][1];  //y co-ordinate of point A

//Now we till now saw how sorting makes it easier to find the next point B in arraay
//Now for how to check the second constraint that there should be no points between A and B
// Previously we wwere runnig a loop to solve this , which was increasing the Time complexity
// So now if we want to check if there is a point or not then Imagine that A is point and then the point B has the highest of u
// In order to actually see it we will have to visualise or draw it
// But if compare the y of our B point with the max y of all points , if the yb is highest it means there is no points in between
// Key idea: 
// - As we scan points to the right of A (because of sorting by x), we maintain `MaxY` = 
//   the largest y-coordinate we have seen so far among candidate B points.
// - For a new point B at (xb, yb):
//      • If yb <= ya (it’s below or equal to A), then it can potentially form a valid pair.
//      • If yb > MaxY, that means B is the highest point we’ve seen so far at this stage.
//        Therefore, no previously considered point can "block" the view from A to B.
//        So (A, B) is a valid pair, and we update MaxY = yb.
// - If yb <= MaxY, then B is "covered" by some earlier point, so (A, B) is invalid.
//
// This way, `MaxY` helps us quickly rule out points that are blocked without checking all of them.
// Initialize MaxY = INT_MIN before scanning to the right of A.
// So We use MaxY intialized as INT_MIN inorder to store the max of all y 
            int MaxY = INT_MIN; 

            for(int j=i+1;j<n;j++) { // Since the next point b will always be at right so j= i+1
               
                // Point B
                int xb = points[j][0];  //x co-ordinate of point B
                int yb = points[j][1]; //y co-ordinate of point B  

                if(yb>ya) continue; //We use this just in case as by sorting we are only solvnig the part where xb>xa , if there is such a point in which xb>xa but ya is not greater than yb then it won't be valid point as A would not be upper left to it,    See we do this because even though we are using sorting it is only to make the traversal less when finding the B point, the formula for to be upper left is still xb>=xa and ya>=yb, so if y>ya then it violates this and A is not upperlef to f this point B so we jsut skip and move to another point


                //As mentioned above it checks for the second constraint of no point lies between A and B, if yb>MaxY, then no point lies b/wA and B, so the pair a and B become valid as they passed both checks so we just increase the count and update MaxY
                if(yb>MaxY){
                    count++;
                    MaxY=yb;
                }
            
            }
        }

        return count; //return the total count;
    }
};

//This take O(n^2)better than Brute force


/*

corner Case:

suppose = [(0,0) (0,3)] // this is sorted as we have done in the code

so i =0 A= (0,0)

j will satrt from i+1 so j = 1 , B = (0,3)

does A and B satisy the criteria xb>=xa ---> yes   and ya>=yb ----> no
So this is not out pair


Then we move forward

i= 1 , A= (0,3) , now the array ends.

So does this means we dont; have an answer?
wrong

if we take A=(0,3) and B=(0,0) then it will satisfy the criteria xb>=xa ---> yes   and ya>=yb ----> yes

So now we have answer , the correct answer


So we don't give wrong answer consider all the possibilites is why we ave sorted according to Y.


*/