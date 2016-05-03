/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(ListNode* head){
        if(head==NULL)
            return NULL;
        if(head->next==NULL){
            TreeNode* root=new TreeNode(head->val);
            return root;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;
        ListNode* pre=head;
        while(1){
            pre=slow;
            slow=slow->next;
            if(fast->next==NULL||fast->next->next==NULL){
                break;
            }
            fast=fast->next->next;
        }
        TreeNode* root=new TreeNode(slow->val);
        slow=slow->next;
        pre->next=NULL;
        root->left=buildTree(head);
        root->right=buildTree(slow);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head);
    }
};
