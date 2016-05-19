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
        ListNode* fi=head;
        ListNode* se=head->next;
        while(1){
            if(se->next==NULL||se->next->next==NULL)
                break;
            else
                se=se->next->next;
            fi=fi->next;
        }
        ListNode* temp=fi;
        fi=fi->next;
        temp->next=NULL;
        ListNode* l1=sortList(head);
        ListNode* l2=sortList(fi);
        ListNode* newHead=new ListNode(-1);
        temp=newHead;
        while(l1!=NULL||l2!=NULL){
            if(l2==NULL||(l1!=NULL&&l1->val<l2->val)){
                temp->next=l1;
                l1=l1->next;
            }else{
                temp->next=l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
        return newHead->next;
    }
};
