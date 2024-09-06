/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;
        for(int i : nums){
            st.insert(i);
        }

        while(head != NULL && st.find(head->val)!=st.end()){ // check if the head value is present int the set and that head is not NULL (if head becomes NULL then we have nothing to check for)
            ListNode* temp =head; // store the head in a temp node
            head= head->next; // update the head to head->next;
            delete(temp); // delete the temp node having the old head

        }

        ListNode* curr = head;

        while(curr !=NULL && curr->next !=NULL){ // if curr is null then no point going further , if curr->next = NULL (it means we have reached the end or removed the node) we use && instead of || because we even if the curr->next becomes NULL there may be more nodes that may be present in the set so we need to go till the end of the list
           if(st.find(curr->next->val)!=st.end()){ // if the value of the next of curr is present in the node it means we need to remove it
             ListNode* temp = curr->next; // store the curr->next in a temp node
             curr->next = curr->next->next; // update the curr->next to curr->next->next
             delete(temp);  // delete the node containing the old curr->next;
           }
           else{ // if the curr->next value is not in the set 
            curr= curr->next; // update the curr to its next
           }

        }
            return head;    
    }
};
