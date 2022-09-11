#include<bits/stdc++.h>
using namespace std;
//reverse the string first and convert opening bracket to closing and vice versa, we traverse from left to right
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
string infpref(string s){
	stack<char> st;
	string res;
	reverse(s.begin(),s.end());
	for(int i=0;i<s.length();i++){
		if(s[i]>='a' && s[i]<='z'){
		    res+=s[i];	
		}else if(s[i]>='A' && s[i]<='Z'){
			res+=s[i];
		}else if(s[i]==')'){
			st.push(s[i]);
		}else if(s[i]=='('){   //putting closing to opening bracket and vice versa since the string has been reversed
			while(!st.empty() && st.top()!=')'){
				res+=st.top();
				st.pop();
			}
			if(!st.empty()){
				st.pop();
			}
		}
		else{ //operator turns up
		    while(!st.empty() && prec(st.top())>=prec(s[i])){
		    	res+=st.top();
		    	st.pop();
			}
			st.push(s[i]);
		}
	}
	while(!st.empty()){
		res+=st.top();
		st.pop();
	}
	reverse(res.begin(),res.end());  //reversing the answer back again
	return res;
}
int main(){
	cout<<infpref("(a-b/c)*(a/k-l)")<<endl;
	return 0;
}
