class Solution {
public:

    bool check(ListNode* head, TreeNode* root){
        
        if(head == NULL) { // if the head reaches Null it means that we have traversed the whole linked list that means we found match for each node only that way we will move onto the next node, head ==NULL means we found everynode in the tree
            return true;  
        }
        if(root == NULL){ // if we traverse the whole tree and do not find all the nodes or then we will reach the end of the tree which means root = null so it means we did not find all the nodes 
            return false;
        }

        if(root->val != head->val) { // if root val is not same as the value of the head then return false and serch in the left or right of the tree
            return false;
        }

        return check(head->next, root->left) || check(head->next,root->right);// recursive calls to search for val of LL
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root == NULL) return false;// base case 

        return check(head, root) || isSubPath(head,root->left) || isSubPath(head,root->right);// recursive calls
        // check is used to find the nodes in tree 
        // if not find the we search the left of the tree
        // and also the right of the tree in order to get a match

        // we use or (||) so that even if get true from the left or  right of the tree so it return true only
    }
};
