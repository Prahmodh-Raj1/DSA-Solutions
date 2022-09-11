#include<bits/stdc++.h>
using namespace std;
int prefix(string s){
	stack<int> st;
	for(int i=s.length() - 1;i>=0;i--){ //since operators come be4 the operands, we start from end of string
		if(s[i]>='0' && s[i]<='9'){
		
			st.push(s[i]-'0');     //pushing the operand into stack
		}
		else{          //if it is operator, this part of loop gets executed
			int op1=st.top();      //op1 and op2 denote operands that need to be removed from stack
			st.pop();
			int op2=st.top();
			st.pop();
			switch(s[i]){
				case '+':
					st.push(op1+op2);
					break;
				case '-':
					st.push(op1-op2);
					break;
				case '*':
					st.push(op1*op2);
					break;
				case '/':
					st.push(op1/op2);
					break;
				case '^':
					st.push(pow(op1,op2));
					break;
			}
		}
	}
	return st.top();
}
int main(){
	cout<<prefix("-+7*45+20")<<endl;
	return 0;
}
