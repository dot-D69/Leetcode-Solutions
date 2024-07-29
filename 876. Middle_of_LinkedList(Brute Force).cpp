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

