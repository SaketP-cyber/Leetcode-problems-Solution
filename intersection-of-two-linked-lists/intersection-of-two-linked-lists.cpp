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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=0,l2=0;
        ListNode *t1=headA,*t2=headB;
        while(t1){
            t1=t1->next;
            l1++;
        }
        while(t2){
            t2=t2->next;
            l2++;
        }
        if(l1<l2){
            ListNode *temp=headB;
            while(l2!=l1){
                temp=temp->next;
                l2--;
            }
            t1=headA;
            t2=temp;
            while(t1!=t2){
                t1=t1->next;
                t2=t2->next;
            }
            return t1;
        }
          else{
            ListNode *temp=headA;
            while(l2!=l1){
                temp=temp->next;
                l1--;
            }
            t1=headB;
            t2=temp;
            while(t1!=t2){
                t1=t1->next;
                t2=t2->next;
            }
            return t1;
        }
    }
};