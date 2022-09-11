#include<bits/stdc++.h>
using namespace std;
class queuew{
	stack<int> s1;
//	stack<int> s2;
public:
	void push(int x){
		s1.push(x);
	}
	int pop(){
		if(s1.empty()){// and s2.empty()){
			cout<<"Queue khali hai"<<endl;
			return -1;
		}
	//	if(s2.empty()){
	//		while(!s1.empty()){
	//			s2.push(s1.top());
	//			s1.pop();
	//		}
	//	}
	   // when there's only one element
		int x=s1.top();
		s1.pop();
		if(s1.empty()){
			cout<<"popped ele is "<<x<<endl;
			return x;
		}
		//recursive popping
		int item=pop();
		s1.push(x);
		cout<<"popped ele is "<<item<<endl;
		return item;
	}
	bool empty(){
		if(s1.empty()){
			return true;
		}else{
			return false;
		}
	}
};
int main(){
	queuew q;
	q.push(1);
	q.push(2);
	q.pop();
	q.push(3);
	q.pop();
	q.pop();
	cout<<q.empty()<<endl;;
	return 0;
}
