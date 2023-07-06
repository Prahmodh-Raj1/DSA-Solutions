//Problem link: https://leetcode.com/problems/intersection-of-two-linked-lists/
//TC: O(M+N) SC: O(1)
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode head1 = headA;
        ListNode head2 = headB;
        int cnt1=0;
        int cnt2=0;
        while(head1!=null){
            head1=head1.next;
            cnt1++;
        }
        while(head2!=null){
            head2=head2.next;
            cnt2++;
        }
        int dif=cnt1-cnt2;
        head1=headA;
        head2=headB;
        if(dif>=0){
            //LL1 has more nodes
            while(dif>0){
                head1=head1.next;
                dif--;
            }
        }else{
            //LL2 has more nodes
            while(dif<0){
                head2=head2.next;
                dif++;
            }
        }
        ListNode ans=null;
        while(head1!=null && head2!=null){
            if(head1==head2){
                ans=head1;
                break;
            }
            head1=head1.next;
            head2=head2.next;
        }
        return ans;

    }
}
