//Circular array:
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

//Non-circular array:
vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long> ans(n,-1);
        stack<long long> st;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and st.top()<=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }else{
                ans[i]=-1;
            }
            st.push(arr[i]);
        }
        return ans;
    }

/*intuition:
 Let’s say we are checking for an element at index i. We keep popping from the stack until the element at the top of the stack is smaller than A[i]. The main intuition behind popping them is that these elements can never
be the NGE for any element present at the left of A[i] because A[i] is greater than these elements. Now, if the top element of S is greater than A[i] then this
is NGE of A[i] and we will assign it to res[i], where res is the resultant array. If the stack becomes empty then it implies that no element at the right of A[i] 
is greater than it and we assign -1. At last, we push A[i] in S.*/
