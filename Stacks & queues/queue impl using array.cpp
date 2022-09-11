#include<bits/stdc++.h>
using namespace std;
class solve{
	int* que;
	int f;
	int r;
public:
	solve()
	{
	    que=new int[5];
		f=-1;
		r=-1;
	}
	void enqueue(int x){
		if(r>=4){
			cout<<"queue overflow"<<endl;
			return;
		}if(f==-1 && r==-1){
			f++;
			que[++r]=x;
			cout<<"inserted "<<x<<endl;
		}
		else{
			que[++r]=x;
			cout<<"inserted "<<x<<endl;
		}
	}
	void dequeue(){
     	if(f==-1 || f>r){
			cout<<"underflow"<<endl;
			return;
		}else{
			cout<<"popped ele is "<<que[f]<<endl;
			if(f==r){
				f=-1;
				r=-1;
			}else{
				f+=1;
			}
		}
	}
	void peek(){
		if(f==-1 || f>r){
			cout<<"queue empty"<<endl;
			return;
		}else{
			cout<<"top ele is "<<que[f]<<endl;
		}
	}
	void display(){
		if(f==-1){
			cout<<"empty"<<endl;
			return;
		}else{
			for(int i=f;i<r+1;i++){
				cout<<que[i]<<" ";
			}cout<<endl;
		}
	}
	bool empty(){
		return f==-1; 
	}
};
int main()
{
    int ch;
    solve qu; 
    while (1) {
        cout << "\n1.enqueue 2.dequeue 3.peek 4.display 5. empty \nEnter ur choice: "; cin >> ch;
        switch (ch) {
        case 1:
            cout << "enter the element: "; cin >> ch;
            qu.enqueue(ch);
            break;
        case 2:
            qu.dequeue();
            break;
        case 3:
            qu.peek();
            break;
        case 4:
        	qu.display();
            break;
        case 5:
        	qu.empty();
        	break;
        case 6:
        	return 0;
        }
    }
}
