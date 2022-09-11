Q.Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.


#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int func(){
	/*
	string s="leetcode";
	unordered_map<char,int> mp;
	if(s.empty()){
		return -1;
	}
	else if(s.length()==1){
		return 0;
	}
	for(int i=0;i<s.length();i++){
		int c=count(s.begin(),s.end(),s[i]);
		mp[s[i]]=c;
		if(mp[s[i]]==1){
			return i;
		}
	}
	return -1;
}*/
    vector _v(27,0);
    string s="leetcode";
    for(int i = 0; i< s.length(); ++i)
    {
        int val= s[i]-'a';
        //cout<< val << endl;
        _v[val]++;
     }

    for(int i = 0; i< s.length(); ++i)
    {
        int val= s[i]-'a';
        if(_v[val]==1) return i;
    }
    return -1;
}

int main(){
	int ans=func();
	cout<<"index is "<<ans<<endl;
	return 0;
}
