//Problem link: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
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
    private ListNode findMiddleNode(ListNode head){
        ListNode slow =head;
        ListNode fast =  head;
        ListNode prevslow=null;
        while(fast!=null && fast.next!=null){
            prevslow=slow;
            slow=slow.next;
            
            fast=fast.next.next;
        }
        return prevslow;  //for an even length LL, we need to return the node that is to the left of the middle of the LL, so that we can reverse the rest and check for the given condition
    }
    private ListNode reverseLL(ListNode head){
        ListNode cur = head;
        ListNode prev=null;
        while(cur!=null){
            ListNode temp = cur.next;
            cur.next=prev;
            prev=cur;
            cur=temp;
        }
        return prev;
    }
    public int pairSum(ListNode head) {
        ListNode cur = head;
        ListNode mid = findMiddleNode(head);
        ListNode nex = mid.next;
        
        int maxi=0;
        if(head.next.next==null){
            return head.val + head.next.val;
        }
        ListNode last = reverseLL(nex);
        while(last!=null){
            int cursum = cur.val + last.val;
            maxi = Math.max(cursum,maxi);
            last=last.next;
            cur=cur.next;
        }
        return maxi;
    }
}
