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
    ListNode *solve(ListNode* a,int len1,ListNode* b,int len2){
        if(len1<len2)
            return solve(b,len2,a,len1);
        int temp=len1-len2;
        ListNode* t=a;
        while(temp--){
            t=t->next;
        }
        ListNode* ha=t;
        ListNode* hb=b;
        while(ha!=NULL){
            if(ha==hb)
                return ha;
            else{
                ha=ha->next;
                hb=hb->next;
            }
        }
        return NULL;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=0,len2=0;
        ListNode* temp;
        temp=headA;
        while(temp!=NULL){
            len1++;
            temp=temp->next;
        }
        temp=headB;
        while(temp!=NULL){
            len2++;
            temp=temp->next;
        }
        return solve(headA,len1,headB,len2);
    }
};
