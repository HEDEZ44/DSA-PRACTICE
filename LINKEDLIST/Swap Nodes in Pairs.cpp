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
  
    ListNode* swapPairs(ListNode* head) {
    if(head==NULL || head->next==NULL)
      return head;
    
    ListNode* prev=head;
    ListNode* curr=head->next;
    ListNode* nxt=curr->next;
    prev->next=swapPairs(nxt);
    curr->next=prev;
    return curr;
    
      
        
    }
};