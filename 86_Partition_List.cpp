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
    ListNode* partition(ListNode* head, int x) {
        ListNode* hh=new ListNode(0);
        hh->next=head;
        ListNode* h2=new ListNode(0);
        ListNode* temp=hh;
        ListNode* temp2=h2;
        while(temp->next!=NULL){
            if(temp->next->val<x)
                temp=temp->next;
            else{
                temp2->next=temp->next;
                temp2=temp2->next;
                temp->next=temp->next->next;
            }
        }
        temp2->next=NULL;
        temp->next=h2->next;
        return hh->next;
    }
};
