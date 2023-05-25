#include<bits/stdc++.h>
using namespace std;
void buildnew(int ind,int low,int high,int arr[],int seg[],int flag){
    //if flag=1, we are doing an or, xor otherwise
    if(low==high){
        seg[ind]=arr[low];
        return;
    }
    int mid = (low+high)/2;
    buildnew(2*ind+1,low,mid,arr,seg,!flag);
    buildnew(2*ind+2,mid+1,high,arr,seg,!flag);
    if(flag){
        //if we are supposed to do an or
        seg[ind]=seg[2*ind +1] | seg[2*ind +2]; 
    }else{
        seg[ind]=seg[2*ind+1]^ seg[2*ind+2];
    }
}
void updatenew(int ind,int low,int high,int i,int val,int arr[],int seg[],int flag){
    if(low==high){
        seg[ind]=val;
        return;
    }
    int mid = (low+high)/2;
    if(i<=mid){
        updatenew(2*ind+1,low,mid,i,val,arr,seg,!flag);  //alternating the operatiuon to be performed
    }else updatenew(2*ind+2,mid+1,high,i,val,arr,seg,!flag);
    if(flag){
        //if we are supposed to do an or
        seg[ind]=seg[2*ind +1] | seg[2*ind +2]; 
    }else{
        seg[ind]=seg[2*ind+1]^ seg[2*ind+2];
    }
}
void solve3(){
    int n,q;
    cin>>n>>q;
    int ele = pow(2,n);
    int arr[ele];
    for(int i=0;i<ele;i++){
        cin>>arr[i];
    }
    int seg[4*ele];
    if( n & 1){
        buildnew(0,0,ele-1,arr,seg,1);  //start with an or
    }else{
        buildnew(0,0,ele-1,arr,seg,0);   //start with an xor
    }
    while(q--){
        int i,val;
        cin>>i>>val;
        i--;
        if( n & 1){
            updatenew(0,0,ele-1,i,val,arr,seg,1);
        }else{
            updatenew(0,0,ele-1,i,val,arr,seg,0);
        }
        cout<<seg[0]<<"\n";
    }
    
}
int main(){
	solve3();
	return 0;
}
