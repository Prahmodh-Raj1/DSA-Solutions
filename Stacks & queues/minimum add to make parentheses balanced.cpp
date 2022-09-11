#include<bits/stdc++.h>
using namespace std;

int func(string s){

        stack<char> sta;
        for(int i=0;i<s.length();i++){
                if(s[i]=='('){
                    sta.push(s[i]);
                }
                else if(s[i]==')'){
                    if (sta.top()=='('){
                        sta.pop();
                    }else{
                        sta.push(s[i]);
                    }
                }
        }
        int adda=sta.size();
            

        return adda;
    }
int main(){
	string s="()))((";
	int rem=func(s);
	cout<<"anser "<<rem<<endl;
	return 0;
}
