//Problem link: 
//TC: O(N) SC: O(1)
//Brute force
int getNthFromLast(Node head, int n)
    {
    	// Your code here	
    	Node cur = head;
    	int cnt=0;
    	while(cur!=null){
    	    cnt++;
    	    cur=cur.next;
    	}
    	cur=head;
    	int now = cnt-n+1;
    	cnt=0;
    	int ans=-1;
    	while(cur!=null){
    	    cnt++;
    	    if(cnt==now){
    	        ans=cur.data;
    	        break;
    	    }
    	    cur=cur.next;
    	}
    	return ans;
    }
//Optimal:
int getNthFromLast(Node head, int n)
    {
    	// Your code here	
    	Node cur = head;
    	Node ref = head;
    	
    	while(n>0){
    	    if(ref==null){
    	        return -1;
    	    }
    	    n--;
    	    ref=ref.next;
    	}
    	while(ref!=null){
    	    cur=cur.next;
    	    ref=ref.next;
    	}
    	if(cur!=null){
    	    return cur.data;
    	}
    	return -1;
    	
    	
    }
