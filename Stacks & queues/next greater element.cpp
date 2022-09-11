#include<bits/stdc++.h>
using namespace std;
//brute force
/*
int func(int temp,int arr[],int i){
	for(int j=i+1;j<sizeof(arr);j++){
		if(arr[j]>temp){
			return arr[j];
		}
	}
	for(int j=0;j<i;j++){
		if(arr[j]>temp){
			return arr[j];
		}
	}
	return -1;
}
int main(){
	int arr[11]={2,10,4,2,1,2,6,1,7,2,9};
	for(int i=0;i<sizeof(arr);i++){
		int temp=arr[i];
		cout<<func(temp,arr,i)<<endl;
	}
	return 0;
}
int solve(int arr[]){
	stack<int> st;
	for(int i=sizeof(arr)-1;i>=0;i--){
		int next=-5
		if(st.empty()){
			st.push(arr[i]);
		}else{
			
		}
	}
}*/
int main(){
	int arr[11]={2,10,4,2,1,2,6,1,7,2,9}; //2n-1 is circular array code, for the normal array use n-1
	int nge[11];
	int n=sizeof(arr);         //i%n is used to access the replication of the array starting from first index again 
	stack<int> st;
	for(int i=0;i<=(2*n-1);i++){        //replicating the elements in thr array, and thereby creating an imaginary array with the same elements in the same order
		while(!st.empty() && st.top()<=arr[i%n]){ //removing all smaller elements than arr[i] to get next greater element
			st.pop();
		}
		if(i<n){
			if(st.empty()==false){
				nge[i]=st.top();
			}
			else{
				nge[i]=-1;
			}
		}st.push(arr[i%n]);
	}
	return 0;

}
