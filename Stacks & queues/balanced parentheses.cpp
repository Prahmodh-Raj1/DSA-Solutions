#include<bits/stdc++.h>
using namespace std;
bool isvalid(string s){
	int n=s.size();
	stack<char> st;
	bool ans=true;     //initially assuming that string is balanced
	for(int i=0;i<n;i++){
		if(s[i]=='{' or s[i]=='[' or s[i]=='('){
			st.push(s[i]);
		}
		else if(s[i]==')'){
			if(!st.empty() && st.top()=='('){
				st.pop();
			}
			else{
				ans=false;
				break;
			}
		}
		else if(s[i]=='}'){
			if(!st.empty() &&st.top()=='{'){
				st.pop();
			}
			else{
				ans=false;
				break;
			}
		}else if(s[i]==']'){
			if(!st.empty() &&st.top()=='['){
				st.pop();
			}
			else{
				ans=false;
				break;
			}
		}
	}
	if(!st.empty()){
		return false;
	}
	return ans;
}
/*    SHORTER METHOD
int Solution::solve(string A) 
{
    stack<int> s;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]=='(')
        {
            s.push(i);
        }
        else
        {
            if(s.empty())
            {
                return 0;
            }
            s.pop();
        }
    }
    return s.empty();
    
}*/
int main(){
	string s="{([])}";
	if(isvalid(s)){
		cout<<"valid string"<<endl;
	}else{
		cout<<"invalid string"<<endl;
	}
	return 0;
}
