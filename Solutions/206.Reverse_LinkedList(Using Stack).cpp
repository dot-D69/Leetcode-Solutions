class Solution {
public:
    stack<int> s;
    ListNode* reverseList(ListNode* head) {
        
        ListNode* curr=head;
        while(curr){
            s.push(curr->val);
            curr=curr->next;
        }

        curr=head;
        while(curr){
            curr->val = s.top();
            s.pop();
            curr=curr->next;
        }
        return head;
        
    }
};

// Pretty basic approach just use stack to store the value of linkedlist 
// Then change the value of the curr node by using th s.top() (as stack is a LIFO data Strcture)
