//Problem link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
//TC :O(N) SC:O(1)

class Solution {
public:
    ListNode* middle(ListNode* head){
        if(head->next==NULL) return head;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL and fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* mid=middle(head);
        if(head==mid){
            return NULL;
        }
        ListNode* temp=head;
        while(temp->next!=mid){
            temp=temp->next;
        }
        ListNode* del=temp->next;
        temp->next=del->next;
        del->next=NULL;
        return head;
    }
};
