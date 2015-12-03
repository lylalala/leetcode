//boring and description-unclear
//use three points: point to newHead, newTail and oldTail respectively



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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL||k==0)
            return head;
        
        //---------------------------
        //i think it is not a good problem. it doesn't tell us how to deal with it if "k" is bigger than array's length
        int howmany=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            howmany++;
        }
        int lala=k%howmany;
        if(lala==0)
            return head;
        //----------------------------
        
        
        ListNode* newTail=head;
        ListNode* newHead=head->next;
        ListNode* findOldTail=head->next;
        for(int i=0;i<lala-1;i++){
            findOldTail=findOldTail->next;
            if(findOldTail==NULL)
                return head;
        }
        while(1){
            if(findOldTail->next==NULL) break;
            findOldTail=findOldTail->next;
            newTail=newTail->next;
            newHead=newHead->next;
        }
        findOldTail->next=head;
        newTail->next=NULL;
        return newHead;
    }
};

