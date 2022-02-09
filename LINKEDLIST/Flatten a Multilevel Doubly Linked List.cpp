/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
      
      for(Node* p=head;p;p=p->next){
        
        if(p->child){
          Node* nxt=p->next;
          p->next=p->child;
          p->child=NULL;
          p->next->prev=p;
          Node* h=p->next;
          while(h->next) h=h->next;
          h->next=nxt;
          if(nxt) nxt->prev=h; 
        }
        
      }
      return head;
        
    }
};