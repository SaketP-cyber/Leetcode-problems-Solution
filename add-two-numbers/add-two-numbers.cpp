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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c=0;
        ListNode* head=new ListNode((l1->val+l2->val)%10);
        ListNode *temp=head;
        c=(l1->val+l2->val)/10;
        l1=l1->next;
        l2=l2->next;
        while(l1 || l2){
            if(l1 && l2){
                ListNode* node=new ListNode((l1->val+l2->val+c)%10);
                 c=(l1->val+l2->val+c)/10;
                temp->next=node;
                temp=node;
                l1=l1->next;
                l2=l2->next;
            }
            else if(l1){
                ListNode* node=new ListNode((l1->val+c)%10);
                c=(l1->val+c)/10;
                temp->next=node;
                temp=node;
                l1=l1->next;
            }
            else if(l2){
                ListNode* node=new ListNode((l2->val+c)%10);
                 c=(l2->val+c)/10;
                temp->next=node;
                temp=node;
                l2=l2->next;
            }
        }
        if(c){
            ListNode* node=new ListNode(c%10);
            temp->next=node;
            temp=node;
        }
        return head;
    }
};