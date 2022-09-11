#include<iostream>
#include<stack>
using namespace std;
void insertatbot(stack<int> &st,int ele){
	if(st.empty()){
		st.push(ele);
		return;
	}
	int topele=st.top();
	st.pop();
	insertatbot(st,ele);
	st.push(topele);
}
void reverse(stack<int> &st){   //calling by reference since the stack would be modified
    if(st.empty()){
    	return;
	}
    int ele=st.top();
    st.pop();
    reverse(st);
    insertatbot(st,ele);
}
int main(){
	stack<int> st;
	st.push(1);
	st.push(2);
	reverse(st);
	while(!st.empty()){      //to chk if stack has been reversed or not
		cout<<st.top()<<endl;
		st.pop();
	}cout<<endl;
	return 0;
}
