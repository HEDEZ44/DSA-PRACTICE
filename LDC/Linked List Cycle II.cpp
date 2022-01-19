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
      
      if(head==NULL)
          return head;
      
      
      vector<ListNode*> v;
      ListNode* curr=head;
      
      v.push_back(curr);
      
      int pos=0;
      while(curr->next!=NULL && find(v.begin(), v.end(),curr->next)==v.end()){
        
        
        v.push_back(curr->next);
        curr=curr->next;
      }
      
      if(curr->next!=NULL){
        pos=find(v.begin(),v.end(),curr->next)-v.begin();
        return v[pos];
      }
      return NULL;
      
        
      
      
    }
};