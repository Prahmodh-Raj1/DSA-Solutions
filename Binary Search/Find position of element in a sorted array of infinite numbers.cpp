//Prob link: https://www.geeksforgeeks.org/find-position-element-sorted-array-infinite-numbers/
#include<iostream>
using namespace std;
int binarysearch(int a[],int key,int low,int high){
	while(low<=high){
		int mid = (low+high)/2;
		if(a[mid]==key){
			return mid;
		}
		else if(a[mid]>key) low=mid+1;
		else high = mid-1;
	}
	return -1;

}
int searchinfinit(int a[],int n){
	int low=0;
	int high=1;  //start with a window of size 2
	while(a[high]<key){  //checking the window range and increasing it if necessary
		low=high+1;
		high=2*high;
	}
	return binarysearch(a,key,low,high); //calling the main binarysearch function
}
int main(){
	//TC: LOG N + LOGN
}
