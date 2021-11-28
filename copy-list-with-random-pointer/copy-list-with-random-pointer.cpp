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
        map<Node*,Node*>m1;
        Node *temp=head;
        while(temp){
            Node *node=new Node(temp->val);
            m1[temp]=node;
            temp=temp->next;
        }
        temp=head;
        while(temp){
            Node *nxt=temp->next;
            m1[temp]->next=m1[nxt];
            Node *rmd=temp->random;
            m1[temp]->random=m1[rmd];
            temp=temp->next;
        }
        return m1[head];
    }
};