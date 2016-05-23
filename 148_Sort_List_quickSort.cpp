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
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        if(head->next->next==NULL){
            if((head->val)>(head->next->val))
                swap(head->val,head->next->val);
            return head;
        }
        ListNode* flag=head;
        ListNode* temp=head->next;
        ListNode* before=head;
        ListNode* newhead=head;
        while(temp!=NULL){
            if(temp->val<flag->val){
                before->next=temp->next;
                temp->next=newhead;
                newhead=temp;
                temp=before->next;
            }else{
                before=temp;
                temp=before->next;
            }
        }
        bool hasbegin=false;
        if(flag!=newhead){
            hasbegin=true;
            temp=newhead;
            while(temp->next!=flag)
                temp=temp->next;
            temp->next=NULL;
            newhead=sortList(newhead);
            temp=newhead;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=flag;
        }
        if(flag->next!=NULL){
            temp=flag->next;
            flag->next=NULL;
            temp=sortList(temp);
            flag->next=temp;
            if(!hasbegin)
                newhead=flag;
        }
        return newhead;
    }
};
