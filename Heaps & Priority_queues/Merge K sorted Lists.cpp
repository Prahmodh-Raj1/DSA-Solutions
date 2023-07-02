//Problem link: https://leetcode.com/problems/merge-k-sorted-lists
//TC: O(NlogK) SC: O(K)
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
private:
struct comp{
    bool operator()(ListNode* l1,ListNode* l2){
        return l1->val > l2->val;
    }
};
    
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comp> pq;  //creating a min-PQ
        for(auto it:lists){
            if(it!=NULL) pq.push(it); //inserting the head pointers of all the linked lists
        }
        if(pq.empty()) return NULL;
        ListNode* ans = pq.top();  //head pointer to the final LL
        pq.pop();
        if(ans->next!=NULL) pq.push(ans->next); //if there exists a next node, we add that to PQ
        ListNode* nex = ans; //pointer used to create the final LL
        while(!pq.empty()){
            ListNode* node = pq.top();
            nex->next = node;  //attachinng the current min element to the LL and moving the pointer
            pq.pop();
            if(node->next!=NULL) pq.push(node->next);  //if nodes still exist in the LL, we add them to the PQ
            nex= nex->next;
        }
        return ans; //returning the head of the newly formed Linked list
    }
};
