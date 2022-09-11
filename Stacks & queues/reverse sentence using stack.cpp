#include<iostream>
#include<stack>
using namespace std;
void reversesent(string s){
	stack<string> sta;
	string st="";
	for(int i=0;i<s.length();i++){
		string st="";
		while(s[i] != ' ' && i<s.length()){
			st+=s[i];
			i++;
		}
		sta.push(st);
	}
	while(!sta.empty()){
		cout<<sta.top()<<" ";
		sta.pop();
	}cout<<endl;
}
int main(){
	string s="Hey, how are you doing?";
	reversesent(s);
	return 0;
}

