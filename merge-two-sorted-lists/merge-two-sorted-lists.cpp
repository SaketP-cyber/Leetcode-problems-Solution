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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       ListNode*head=new ListNode();
        ListNode*temp=head; 
        int x,y;
        while(l1 || l2){
            x=INT_MAX;
            y=INT_MAX;
            if (l1)
                x=l1->val;             
            if (l2)
                y=l2->val;          
            if (x>y){
                ListNode*node=new ListNode(y);
                temp->next=node;
                l2=l2->next;
            }
            else{
                ListNode*node=new ListNode(x);
                temp->next=node;
                l1=l1->next;
            }
            temp=temp->next;
            
        } 
        return head->next;
    }
};