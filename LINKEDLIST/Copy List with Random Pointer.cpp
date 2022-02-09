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
      unordered_map<Node*,Node*>mp;
      
      Node* dummy= new Node(-1);
      Node* prev=dummy;
      Node* curr=head;
      while(curr!=NULL){
        Node* node= new Node(curr->val);
        prev->next=node;
        mp.insert({curr,node});
        prev=prev->next;
        curr=curr->next;
      }
      
      Node* nHead=dummy->next;
      
      Node* c1=head;
      Node* c2=nHead;
      while(c1!=NULL){
        if(c1->random==NULL)
          c2->random=NULL;
        else
          c2->random=mp[c1->random]; 
        c1=c1->next;
        c2=c2->next;
      }
      return nHead;
      
        
    }
};