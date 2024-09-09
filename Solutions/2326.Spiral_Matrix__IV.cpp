class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int> >res(m,vector<int>(n,-1)); // Initialize a 2-D matrix with 
        int id =0;
        int top =0;
        int down = m-1;
        int  left =0;
        int right = n-1;

        while(top<=down && left<=right){
            if(id ==0){ //Left to right
            for(int i=left;head != NULL &&i<=right;i++){
                res[top][i] = head->val;
                head = head->next;
            }
            top++; //Move the top as the top row is filled as we want to move in a spiral manner for the next iteration
            }

            if(id==1){ // top to down
                for(int i=top;head != NULL &&i<=down;i++){
                    res[i][right] = head->val;
                    head= head->next;
                }
                right--; // The right column is completely filled by now so we move the  right as we want to move in a spiral manner
            }

            if(id == 2){ // right to left
                for(int i=right; head!=NULL && i>=left;i--){
                    res[down][i] = head->val;
                    head = head->next;
                }
                down--; // The down row is also filled so we move it as we want to be moving in a spiral matter
            }

            if(id==3){ // down to top;
                for(int i = down; head != NULL && i>=top ; i--){
                    res[i][left]= head->val;
                    head = head-> next;
                }
                left++;
            }

            id = (id+1)%4; // this will work for id =0,1,2,3 and then once again it wiil set id as 0 
        }
        return res;
        
    }
};

/*

    To go in a spiral manner we will go from left-> right, top->down, right->left, down->top
    and this pattern will keep repeating to form a spiral

    Since the pattern will keep repeating we give an id to each iteration i.e. 
    id =0 --> left to right
    id =1 --> top to down
    id =2 --> right to left
    id = 3 --> down to top

    Then we again start from id =0 and go till id = 3  until our pattern is complete (top<=down &&left<=right) this condition  checks that the top never crosses the down else our matrix will be distorted

    //We initialize the array with -1 so when we run out of LinkedList we do not have to fill explicitly any values

    // id = 0 left to right 
    we keep the top row fixed and go from left to right using a loop 
    insert the head->val 
    then move the head to  its next
    It goes on till we reach the right then  we exit the loop
    Once we are out of the loop it means we have filled our top row so we move the top = top++;
    Why because we want to fill the complete matrix in a Spiral manner so we need to move the top in for 
    next Iteration 


    // id = 1 top to down 
    we keep the right column fixed and go from top to down using a loop 
    insert the head->val 
    then move the head to  its next
    It goes on till we reach down, and then  we exit the loop
    Once we are out of the loop it means we have filled our right column so we move the right = right--;
    Why because we want to fill the complete matrix in a Spiral manner so we need to move the right for 
    next Iteration 

    //Similarly we do for all the id = 2,3

    we use id = (id+1)%4 to loop the value of id between 0 ,1,2,3 then again 0,1,2,3 so on

*/
