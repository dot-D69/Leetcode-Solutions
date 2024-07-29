//Brute Force

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int>s;
        ListNode* curr=head;
        while(curr){
            s.push(curr->val);
            curr=curr->next;
        }
        curr=head;
        while(curr && curr->val ==s.top()){
            curr=curr->next;
            s.pop();
        }
        return curr==NULL;
        
    }
};

// Time Complexity : O(n)
//Space Complexity : O(n)

//we use stack push all the elements of the ll into the stack
// Then we start comparing the ll with the top of stack if it matches we pop the element from the stack and move to the next element of LL
// atlast we will return the check of curr == NULL , if all the elements were (i.e Palindrome ) so the stack will be NULL elese it will not be NULL
