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
    void insertNode(ListNode*& head,ListNode* point){
        if(head==NULL){
            head=point;
            point->next=NULL;
            return;
        }
        if(point->val<=head->val){
            point->next=head;
            head=point;
            return;
        }
        ListNode* f=head;
        ListNode* s=head->next;
        while(f!=NULL){
            if(f->val<=point->val&&(s==NULL||point->val<=s->val)){
                f->next=point;
                point->next=s;
                break;
            }
            f=f->next;
            if(s!=NULL) s=s->next;
        }
    }
    ListNode* insertionSortList(ListNode* head) {
        ListNode* newhead=NULL;
        while(head!=NULL){
            ListNode* temp=head;
            head=head->next;
            insertNode(newhead,temp);
        }
        return newhead;
    }
};
