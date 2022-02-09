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
      Node* curr=head;
      
      while(curr!=NULL){
        Node* copy=new Node(curr->val);
        Node* next=curr->next;
        curr->next=copy;
        copy->next=next;
        curr=next;
      }
      
      curr=head;
      while(curr!=NULL){
        Node* rand=curr->random;
        if(rand!=NULL){
          curr->next->random=rand->next;
        }
        curr=curr->next->next;
      }
      curr=head;
      Node* dummy=new Node(-1);
      Node* prev=dummy;
      while(curr!=NULL){
        prev->next=curr->next;
        curr->next=curr->next->next;
        
        prev=prev->next;
        curr=curr->next;
      }
      return dummy->next;
      
      
     
        
    }
};