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
    bool hasCycle(ListNode *head) {
        if(head==NULL||head->next==NULL)
            return false;
        ListNode* first;
        ListNode* second;
        first=head;
        second=head->next;
        while(1){
            if(first==second)
                return true;
            first=first->next;
            if(second==NULL||second->next==NULL||second->next->next==NULL){
                return false;
            }
            second=second->next->next;
        }
        return true;
    }
};
