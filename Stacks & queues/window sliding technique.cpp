#include<bits/stdc++.h>
//Given an array of integers of size ‘n’.
//Our aim is to calculate the maximum sum of ‘k’ 
//consecutive elements in the array.
//
//Input  : arr[] = {100, 200, 300, 400}
  //       k = 2
//Output : 700

using namespace std;
int main(){
	//Brute force approach
/*	int n=4;
	int arr[n]={100,200,300,400};
	int k=2;
	int maxs=INT_MIN;
	for(int i=0;i<7-k+1;i++){
		int cursum=0;
		for(int j=0;j<k;j++){
			cursum+=arr[i+j];
		}
		maxs=max(cursum,maxs);
	}
	cout<<"max consecutive sum is "<<maxs<<endl; */
	return 0;
	
}

//Given an array of integers of size ‘n’.
//Our aim is to calculate the maximum element of ‘k’ 
//consecutive elements in the array.
/* Brute force
for(int i=0;i<n-k+1;i++){
   int maxi=arr[i];
   for(int j=i;j<i+k-1;j++){
       maxi=max(a[j],maxi);
    }
    cout<<maxi<<endl;
}
optimised solution is using deque
