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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      if(left>=right)
        return head;
        
      ListNode* dummy = new ListNode(0);
      dummy->next=head;
      ListNode* pre=dummy;
      ListNode* curr;
      for(int i=0;i<left-1;i++){
        pre=pre->next;
      }
      curr=pre->next;
      for(int j=0;j<right-left;j++){
        ListNode* temp=pre->next;
        pre->next=curr->next;
        curr->next=curr->next->next;
        pre->next->next=temp;
      }
      return dummy->next;
      
    }
};