/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *temp=head;
        while(temp){
            Node *t1=temp->next;
            Node *node=new Node(temp->val);
            temp->next=node;
            node->next=t1;
            temp=t1;
        }
        temp=head;
        while(temp)
        {
            Node *t1=temp->next->next;
            if(temp->random!=NULL){
                temp->next->random=temp->random->next;
            }
            temp=t1;
        }
        Node *newHead=new Node(0);
        temp=head;
        Node *itr=newHead;
        while(temp){
            Node *t1=temp->next->next;
            itr->next=temp->next;
            temp->next=t1;
            itr=itr->next;
            temp=t1;
        }
        return newHead->next;
        }
};