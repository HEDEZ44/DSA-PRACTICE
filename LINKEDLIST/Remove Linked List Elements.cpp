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
    ListNode* removeElements(ListNode* head, int val) {
        
      if(head==NULL)
        return head;
      
      ListNode* temp= new ListNode(-1);
      ListNode* dummy=temp;
      ListNode* curr=head;
      while(curr!=NULL){
        if(curr->val!=val){
          temp->next=curr;
          temp=temp->next;
        }
        curr=curr->next;
      }
      temp->next=NULL;
      return dummy->next;
    }
};