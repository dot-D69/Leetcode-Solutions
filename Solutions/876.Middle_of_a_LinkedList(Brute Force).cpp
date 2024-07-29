// Brute Force
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* curr =head;
        int cnt=0;
        while(curr){
            cnt++;
            curr=curr->next;
        }
        int mid = cnt/2+1;
        curr =head;
        for(int i=1;i<mid;i++){
            curr=curr->next;
        }
        return curr;
        
    }
};

// first we iterate through the whole length of the LL to find its length usin counter;
// Once we have traversed the whole List ,We can find the Mid using count/2 +1
// Now we have our mid, reset the curr to head and traverse the List only till mid.
// At mid our curr will be pointing to the middle element of the List.
