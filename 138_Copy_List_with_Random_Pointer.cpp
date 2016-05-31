/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL)
            return NULL;
        RandomListNode* temp=head;
        RandomListNode* nextTemp=head;
        while(temp!=NULL){
            nextTemp=temp->next;
            temp->next=new RandomListNode(temp->label);
            temp->next->next=nextTemp;
            temp->next->random=temp->random;
            temp=nextTemp;
        }
        temp=head;
        while(temp!=NULL){
            if(temp->random!=NULL)
                temp->next->random=temp->random->next;
            temp=temp->next->next;
        }
        RandomListNode* newhead=head->next;
        RandomListNode* temp1=head;
        RandomListNode* temp2=newhead;
        while(temp1!=NULL){
            temp1->next=temp2->next;
            temp1=temp2->next;
            if(temp1!=NULL){
                temp2->next=temp1->next;
                temp2=temp1->next;
            }
        }
        return newhead;
        // return head;
    }
};
