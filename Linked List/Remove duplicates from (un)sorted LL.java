//Problem link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
//TC: O(N) SC: O(1)
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode cur = head;
        while(cur!=null){
            while(cur.next!=null && cur.val==cur.next.val){
                cur.next = cur.next.next;
            }
            cur=cur.next;
        }
        return head;
    }
    
}

//Remove duplicates from unsorted LL
//TC: O(N) SC: O(N)
class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node* removeDuplicates( Node *head) 
    {
     // your code goes here
        Node* cur=head;
        Node* prev=NULL;
        unordered_map<int,int> mp;
        while(cur!=NULL){
            if(mp.find(cur->data)!=mp.end()){
                prev->next=cur->next;
                delete(cur);
                
            }else{
                mp[cur->data]=1;
                prev=cur;
                //cur=cur->next;
            }
            cur=prev->next;
        }
        return head;
    }
};
