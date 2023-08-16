//Prob link: https://leetcode.com/problems/partition-list
//TC: O(N) SC: O(1)
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* templl1 = new ListNode(0);
        ListNode* templl2 = new ListNode(0);
        ListNode* lessx = templl1;
        ListNode* greaterX=templl2;
        while(head!=NULL){
            if(head->val<x){
                lessx->next = head;
                lessx = lessx->next;
            }else{
                greaterX->next = head;
                greaterX = greaterX->next;
            }
            head=head->next;
        }
        greaterX->next = NULL;
        lessx->next = templl2->next;
        return templl1->next;

    }
};
