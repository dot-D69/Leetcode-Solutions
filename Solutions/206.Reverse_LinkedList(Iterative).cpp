// Iterative Approach
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode*  curr= head;
        ListNode* temp;
        ListNode* prev=nullptr;
        while(curr){
            temp = curr->next; // so now temp has the value of next pointer of head (curr =1 , temp=2)
            curr->next=prev; // This breaks the link between 1 and 2 by pointing the next pointer of 1  to null
            prev = curr; // we make the prev as curr now prev points to 1 and 1 points to null
            curr =temp; // move to the next node;
        }
        return prev;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)

//The Working of  the code is like this:
/*
1st iteration:
prev->null
curr->1

temp = curr->next (temp =2)
curr->next = prev (null) i.e 1->null
prev =curr (prev->1->null)
curr = temp (curr =2)

2nd iteration

curr =2;
temp =3;
curr->next =prev (2->1 ) as prev was 1
prev = curr  (prev->2->1->null)
curr = temp ( curr =3)

3rd Iteration

curr =3
temp =4
curr->next = prev ( 3->2) as prev was pointing to 2
prev = curr ( prev->3->2->1->null)
curr =temp (curr =4)

4th Iteration

curr=4
temp =5
curr->next = prev ( 4->3) as prev was poiting to 3
prev = curr ( prev->4->3->2->1->null)
curr = temp (curr =5)


5th Iteration:

curr=5
temp = null;
curr->next = prev (5-> 4) as prev was pointing to 4
prev = curr (prev->5->4->3->2->1)
curr =temp (curr=null)
*/
