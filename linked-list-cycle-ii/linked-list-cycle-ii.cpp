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
    ListNode *detectCycle(ListNode *head) {
         if (head == NULL || head->next == NULL)
        return NULL;
        ListNode *s=head,*f=head;
       bool flag=0;
        while(f && f->next && s){
            s=s->next;
            f=f->next->next;
            if(s==f){
                s=head;
                while(s!=f){
                    s=s->next;
                    f=f->next;
                }
                flag=true;
                break;
            }
        }
        if(flag){
            return s;
        }
        return NULL;
    }
};