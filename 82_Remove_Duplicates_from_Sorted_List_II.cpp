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
    ListNode* deleteDuplicates(ListNode* head) {
        //add a new head
        ListNode *hh=new ListNode(0);
        hh->next=head;
        ListNode *f,*s;
        f=hh;
        while (f!=NULL&&f->next!=NULL) {
            s=f->next;
            if(s->next!=NULL&&s->val==s->next->val){
                while (s->next!=NULL&&s->val==s->next->val) {
                    s=s->next;
                }
                f->next=s->next;
            }else{
                f=f->next;
            }
        }
        return hh->next;
    }
};
