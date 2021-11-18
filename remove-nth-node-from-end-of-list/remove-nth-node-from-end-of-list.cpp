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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *t=head;
        int l=0;
        while(t){
            t=t->next;
            l++;
        }
        if(l==1)return NULL;
        if(l-n==0){
            return head->next;
        }
        int i=1;
        t=head;
        while (i!=l-n && t){
            t=t->next;
            i++;
        }
        t->next=t->next->next;
        return head;
    }
};