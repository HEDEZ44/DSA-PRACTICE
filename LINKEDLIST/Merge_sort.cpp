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
  ListNode* midNode(ListNode* node){
    if(node==NULL && node->next==NULL)
      return node;
    ListNode* fast=node;
    ListNode* slow=node;
    while(fast->next!=NULL && fast->next->next!=NULL){
      slow=slow->next;
      fast=fast->next->next;
    }
    return slow;
  }
  ListNode* merge(ListNode* l1, ListNode* l2){
    if(l1==NULL || l2==NULL) return l1!=NULL?l1:l2;
    
    ListNode* dummy=new ListNode(-1);
    ListNode* temp=dummy;
    ListNode* c1=l1, *c2=l2;
    while(c1!=NULL && c2!=NULL){
      if(c1->val<c2->val){
        temp->next=c1;
        c1=c1->next;
      }
      else{
        temp->next=c2;
        c2=c2->next;
      }
      temp=temp->next;
    }
    temp->next= c1!=NULL?c1:c2;
    return dummy->next;
  }
  
  ListNode* sortList(ListNode* head) {
    if(head==NULL || head->next==NULL) return head;
    ListNode* mid=midNode(head);
    ListNode* nHead=mid->next;
    mid->next=NULL;
    ListNode* l1=sortList(head);
    ListNode* l2=sortList(nHead);
    
    return merge(l1,l2);
    
    }
};