// Iterative Method
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        if(!head || !head->next){
            return head;
        }

        ListNode* curr = head; // curr to keep store the head node
        ListNode* nextnode = head->next; // nextnode to store the next of the head node

        while(nextnode){ // while the nextnode is not null
            ListNode* temp  = new ListNode(__gcd(curr->val,nextnode->val)); // we get the gcd of the curr and nextnode
            //Add the gcd between the nodes
            curr->next = temp;  // next of the curr points to the temp 
            temp->next = nextnode; //  the next of the temp points to the next node;
            //curr----temp---nextnode

            // Move to the next nodes of the LL to find their GCD
            curr = nextnode;
            nextnode = nextnode->next;
        }
        return head;// return the head
    }
};
