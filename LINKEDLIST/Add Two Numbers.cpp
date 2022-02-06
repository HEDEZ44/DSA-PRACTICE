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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      
      ListNode* ans= new ListNode(-1);
      ListNode* k=ans;
      ListNode* temp1=l1;
      ListNode* temp2=l2;
      int e=0;
      while(temp1!=NULL || temp2!=NULL || e!=0){
        int sum= (temp1!=NULL?temp1->val:0) + (temp2!=NULL?temp2->val:0) + e;
        e=sum/10;
        ListNode* node =new ListNode(sum%10);
        ans->next=node;
        ans=ans->next;
        temp1=temp1!=NULL?temp1->next:NULL;
        temp2=temp2!=NULL?temp2->next:NULL;
        
      }
      ans->next=NULL;
      return k->next;
        
    }
};