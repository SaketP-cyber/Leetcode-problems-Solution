/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)return head;
      int len=0;
        ListNode *temp=head;
        while(temp){
            temp=temp->next;
            len++;
        }
        //cout<<len;
        if(k%len==0)return head;
        temp=head;
        for(int i=1;i<(len-(k%len))%len;i++){
            temp=temp->next;
        }
        ListNode *newHead=temp->next;
        temp->next=NULL;
        ListNode *t1=newHead;
        while(t1->next){
            t1=t1->next;
        }
        t1->next=head;
        return newHead;
    }
};