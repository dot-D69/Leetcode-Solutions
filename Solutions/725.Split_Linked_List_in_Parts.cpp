
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int L = 0;
        ListNode* curr = head;
        while(curr!= NULL){ // to calculate the length of the Linked List
            L++;
            curr=curr->next;
        }

        int BucketNodes = L/k; // it gives the minimum number of nodes that should be in eac partition
        int RemNodes = L%k;  // this gives us the extra nodes in the LL that we need to adjust

        vector<ListNode*> res(k,NULL); // intialize the res vector with k size and all of them as NULL (as we wil be sotring in this and it is said that we nedd k partition so res will be of size k)
        ListNode* prev = NULL; // create a prev to keep track of the lastNode which we require in order to break the connection between nodes else we won't be able to make partitions
        curr = head; // point the curr to head of the LL 
        for(int i=0; curr!=NULL && i<k;i++){ // we have to check that the curr is not null before proceeding 
            res[i]=curr;  // fill the intial of the res with curr then we seek further if we need to add more nodes and till when
            for(int count =1;count<=BucketNodes + (RemNodes > 0 ? 1 :0);count++){ 
                prev = curr; // move prev to curr 
                curr= curr->next; // move the curr to the next node
            }
            prev->next= NULL; // make prev NULL in order to break the LL and make partitions
            RemNodes--; // we decrease the number of rem/extra nodes so that it won't take any more nodes in the partitions
        }
        return res; // return the res array
    } 
};


//Time Complexity: O(K+L) //because we run the first for loop for i= 0 to k and we visit each node of the LL only once
// hence K+L 

//Explanation for(int count =1;count<=BucketNodes + (RemNodes > 0 ? 1 :0);count++)
// This particular line is very important for our partitions
// we start from count 1 and we check if the count is less than the number of bucketnodes becuase we don't want to add extra to a partition as it will violate the rule
// But we also have to make sure that the parts occuring earlier are greater in size than parts occuring later
// so we use remnodes,if the no of bucketnodes are 2 and if the num of remnodes are greater than 0 then we add 1 to the count
// why only one because it is said that two parts should have a size differing by more than one.
//so we add 1 extra node to each part until number of RemNodes is 0 after that only the specified number of nodes are added to each partition
// example, if the bucketnode is 2 and remnodes is 2 and k =4 then
// the first partition will have 3 elements {1,2,3} ,  the second partition will have 3 elements {4,5,6} and the rest two partition will have 2 elements {7,8}, {9,10}
// In this way the size difference is not more than one , The early occuring parts are greater in size than the parts occuring later


/*
    Dry Run for the input 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> NULL and k =4

Variables:
L = 10
BucketNodes = 2
RemNodes = 2

res = [NULL, NULL, NULL, NULL]

Iteration 1 (i = 0):
Part 1 gets BucketNodes + 1 = 3 nodes.
res[0] = 1 -> 2 -> 3 -> NULL
RemNodes = 1

Iteration 2 (i = 1):
Part 2 gets BucketNodes + 1 = 3 nodes.
res[1] = 4 -> 5 -> 6 -> NULL
RemNodes = 0

Iteration 3 (i = 2):
Part 3 gets BucketNodes = 2 nodes.
res[2] = 7 -> 8 -> NULL


Iteration 4 (i = 3):
Part 4 gets BucketNodes = 2 nodes.
res[3] = 9 -> 10 -> NULL

Final res Array:
res[0] = 1 -> 2 -> 3 -> NULL
res[1] = 4 -> 5 -> 6 -> NULL
res[2] = 7 -> 8 -> NULL
res[3] = 9 -> 10 -> NULL


*/
