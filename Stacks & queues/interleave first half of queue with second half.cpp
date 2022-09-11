/*procedure:
1)push the first n/2 elements from queue to stack(auxillary space)
2)push  the elements in the stack back into the queue
3)Pop the first half of the elements in the queue and push them back into the queue
4)Then push n/2 elements from the queue to the stack back again(the first half)
5)Answer is generated finally by getting back all elements back in the queue and printing them 

EG: 11 12 13 14 15 16 17 18 19 20
o/p:11 16 12 17 13 18 14 19 15 20

eg:1 2 3 4
o/p:1 3 2 4

TC: O(N)     SC: O(N)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	int n=4;
	stack<int> s;
	for(int i=0;i<n/2;i++){      //executing step 1
		s.push(q.front());
		q.pop();
	}
	while(!s.empty()){           //executing step 2
		q.push(s.top());
		s.pop();
	}
	for(int i=0;i<n/2;i++){       //executing step 3
		q.push(q.front());
		q.pop();
	}
	for(int i=0;i<n/2;i++){       //step 4
		s.push(q.front());
		q.pop();
	}
	while(!s.empty()){
		q.push(s.top());
		s.pop();
		q.push(q.front());
		q.pop();
	}
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	return 0;
}
