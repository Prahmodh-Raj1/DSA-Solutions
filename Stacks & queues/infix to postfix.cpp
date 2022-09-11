#include<bits/stdc++.h>
using namespace std;
int prec(char c){
	if(c=='^'){
		return 3;
	}else if(c=='*' || c=='/'){
		return 2;
	}else if(c=='+' || c=='-'){
		return 1;
	}else{
		return -1;     //will be returned when opening bracket comes(not an operator)
	}
}
string infix(string s){
	stack<char> st;
	string res;          //final result
	for(int i=0;i<s.length();i++){
		if(s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'){    //chking if its an operand or not
			res+=s[i];
		}else if(s[i]=='('){
			st.push(s[i]);
		}else if(s[i]==')'){
			while(!st.empty() && st.top()!='(' ){
				res+=st.top();
				st.pop();
			}
			if(!st.empty()){
				st.pop();   //removes opening bracket
			}
		}
		else{    //when operator comes up
			while(!st.empty() && prec(st.top())>=prec(s[i])){
				res+=st.top();
				st.pop();
			}
			st.push(s[i]);    //pushing current operator
		}
	}
	while(!st.empty()){
		res+=st.top();
		st.pop();
	}
	return res;
}
int main(){
	cout<<infix("(a-b/c)*(a/k-l)")<<endl;
	return 0;	
}
