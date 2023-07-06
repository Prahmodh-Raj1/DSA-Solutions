//Problem link: https://leetcode.com/problems/reverse-linked-list/description/
//TC: O(N) SC: O(1)
class Solution {
    public ListNode reverseList(ListNode head) {
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
}

//Recursively:
public node reverse(node head){
 if(head==null or head.next==null){
  return head;
 }
 node* newhead=reverse(head.next);
 node* headnext=head.next;
 headnext.next=head;
 head.next=null;
 return newhead;
}
