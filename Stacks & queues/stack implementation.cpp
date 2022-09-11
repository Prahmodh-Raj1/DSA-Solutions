#include<iostream>
#define size 6
using namespace std;
int main(){
	int s;
	cout<<"Enter size of array";
	cin>>s;
	int arr[s];
	for(int i=0;i<s;i++){
		arr[i]=0;
	}
	//int* arpt=&arr;
	int top=-1;
	//int* tpt=&top;
	while(true){
		cout<<" 1.push  2.pop  3.peek  4.display"<<endl;
		int c;
		cout<<"enter choice ";
		cin>>c;
		if(c==1){
			push(arr,top);
		}else if(c==2){
			pop(arr,top);
		}else if(c==3){
			peek(arr,top);
		}else if(c==4){
			display(arr,top);
		}else if(c==5){
			break;
		}
	}
	return 0;
}
void push(arr,top){
	if(top==s-1){
		cout<<"overflow"<<endl;
	}else{
		if(top==-1){
			top=0;
		}
		else{
			top+=1;
		}
	}
	cout<<"enter the element ";
	cin>>arr[top];
}
void pop(arr,top){
	if (top==-1){
		cout<<"underflow"<<endl;
	}
	else{
		cout<<"the popped element is "<<arr[top]<<endl;
		if (top==0){
			top=-1;
		}else{
			top-=1;
		}
	}
}
void peek(arr,top){
	if(top==-1){
		cout<<"stack gaali hai "<<endl;
	}
	else{
		cout<<"top ele is "<<arr[top]<<endl;
	}
}
void display(arr,top){
	if(top==-1){
		cout<<"enpty "<<endl;
	}
	else{
		for(int i=0;i<=top;i++){
			cout<<arr[i]<<" ";
		}
	}
}
