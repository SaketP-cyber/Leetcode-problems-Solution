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

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)return head;
        int l=0;
        ListNode *temp=head;
        while(l!=k && temp){
            temp=temp->next;
            l++;
        }
        if(l!=k){
            return head;
        }
        ListNode* pre=NULL,*curr=head;
        int kk=k;
        while(curr && kk){
            ListNode* nxt=curr->next;
            curr->next=pre;
            pre=curr;
            curr=nxt;
            kk--;
        }
        //temp=head;
        // ListNode *root=head;
        head->next=reverseKGroup(curr,k);
        return pre;
    }
};