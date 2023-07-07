//Problem link: https://leetcode.com/problems/odd-even-linked-list
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
    public ListNode oddEvenList(ListNode head) {
        
        if(head==null){
            return head;
        }
        ListNode oddcur = head;
        ListNode evencur = head.next;
        ListNode evenhead = evencur;
        while(evencur!=null && evencur.next!=null){
            oddcur.next = oddcur.next.next;
            evencur.next = evencur.next.next;
            oddcur = oddcur.next;
            evencur = evencur.next;
        }
        oddcur.next = evenhead;
        return head;
        
    }
}
