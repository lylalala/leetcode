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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* myhead;
        myhead->next=head;
        ListNode* h=myhead;
        for(int i=0;i<m-1;i++)
            h=h->next;
        ListNode* first=h->next;
        ListNode* second;//=first->next;
        ListNode* substr_h;
        ListNode* substr_t=first;
        for(int i=0;i<=n-m;i++){
            second=first->next;
            first->next=substr_h;
            substr_h=first;
            first=second;
        }
        h->next=substr_h;
        substr_t->next=second;
        return myhead->next;
    }
};
