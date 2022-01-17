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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next;
        int count=0;
        ListNode* temp=curr;
        int t=1;
        while(temp->next!=NULL){
            temp=temp->next;
            t++;
        }
        cout<<t<<endl;
            
        if(t>=k){
        while(curr!=NULL && count<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        
        if(next!=NULL){
            head->next=reverseKGroup(next,k);
        }
        return prev;
        }
        else
            return curr;
        
    }
};