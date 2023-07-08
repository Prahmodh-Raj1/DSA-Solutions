//Using two queues

#include<bits/stdc++.h>
using namespace std;
class stak{
	int n; //size of stack
	queue<int> q1;
	queue<int> q2;
	stak(){
		n=0;
	}
	void push(int val){          //first, push ele to q2, then bring all ele from q1 to q2, then swap the elements in q2 to q1 such that q2 is empty
		q2.push(val);
		n++; //size increased
		while(!q1.empty()){
			q2.push(q1.front());
			q1.pop();
		}
		//for swapping, we use a separate queue
		queue<int> temp=q1;
		q1=q2;
		q2=temp;
	}
	void pop(){
		q1.pop();
		n--;   //size decreased
	}
	void topp(){
		return q1.front();
	}
	int sizee(){
		return n;
	}
};

//for implementing stack in single queue
/* push(int x)
     q1.push(x);
     for(i=0;i<q.size()-1;i++){
	     q1.push(q1.top());
		 q1.pop();
	}
}
pop(){
  q1.pop();
}
top(){
  q1.top();
int main(){
	stak st;
	st.push(1);
	st.push(2);
	st.push(3);
	cout<<st.topp()<<endl;
	return 0;
}
