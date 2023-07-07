//problem link: https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1
//TC: O(N) SC:O(1)
public static Node reverseDLL(Node  head)
{
    //Your code here
    Node cur = head;
    Node prev=null;
    while(cur!=null){
        prev = cur.prev;
        cur.prev=cur.next;
        cur.next=prev;
        cur=cur.prev;
    }
    if(prev!=null) head=prev.prev;
    return head;
}
