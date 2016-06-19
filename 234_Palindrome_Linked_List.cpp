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
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL) return true;
        bool flag=false;
        ListNode* first=head;
        ListNode* second=head->next;
        while(1){
            if(second->next==NULL) break;
            if(second->next->next==NULL){
                flag=true;
                break;
            }
            second=second->next->next;
            first=first->next;
        }
        ListNode* head2=flag?first->next->next:first->next;
        first->next=NULL;
        ListNode* head1;
        if(head->next==NULL) head1=head;
        else{
            ListNode* a=head;
            ListNode* b=head->next;
            ListNode* c;
            while(b!=NULL){
                c=b->next;
                b->next=a;
                a=b;
                b=c;
            }
            head1=a;
            head->next=NULL;
        }
        while(head1!=NULL){
            if(head1->val!=head2->val) return false;
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
};
