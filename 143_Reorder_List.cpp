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
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return;
        //快慢指针分成两部分
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL){
            if(fast->next==NULL||fast->next->next==NULL)
                break;
            fast=fast->next->next;
            slow=slow->next;
        }
        //翻转slow后的节点
        ListNode* first=slow->next;
        ListNode* second=first->next;
        ListNode* hh=NULL;
        while(first!=NULL){
            first->next=hh;
            hh=first;
            first=second;
            if(second!=NULL&&second->next!=NULL)
                second=second->next;
            else
                second=NULL;
        }
        slow->next=hh;
        ListNode* temp=slow;
        slow=slow->next;
        temp->next=NULL;
        //归并
        ListNode* b=head->next;
        ListNode* e=slow;
        temp=head;
        while(e!=NULL){
            temp->next=e;
            e=e->next;
            temp=temp->next;
            temp->next=b;
            if(b!=NULL)
                b=b->next;
            if(temp!=NULL) temp=temp->next;
        }
    }
};
