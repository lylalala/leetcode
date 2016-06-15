/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        if(node->next->next==NULL){
            delete node->next;
            node->next=NULL;
        }else{
            ListNode* temp=node->next;
            node->next=temp->next;
            delete temp;
        }
    }
};
