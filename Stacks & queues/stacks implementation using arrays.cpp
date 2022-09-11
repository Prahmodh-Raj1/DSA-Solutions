#include<iostream>
#include<stdlib.h>
#define n 5
using namespace std;
class stack{
	int* stk;     //dynamic memory allocation, by reference
	int top;
public:
    stack()       //creating constructor
    {
    	stk=new int[n];
        top = -1;
    }
    void push(int x)
    {
        if (top >= 4) {
            cout << "stack overflow";
            return;
        }
        stk[++top] = x;    //value of top is incremented first
        cout << "inserted " << x;
    }
    void pop()
    {
        if (top==-1) {
            cout << "stack underflow";
            return;
        }
        cout << "deleted " << stk[top];
        top--;
    }
    void display()
    {
        if (top < 0) {
            cout << " stack empty"; return; } for (int i = top; i >= 0; i--)
            cout << stk[i] << " ";
    }
    int topp(){       //for printing the top most element in stack
        if(top==-1){
        	cout<<"stack empty"<<endl;
        	return -1;
		}
    	cout<<stk[top]<<endl;
	}
    bool empty(){
    	return top==-1;    //returns a boolean value after checking whether top=-1, if stack is empty it returns 1(true)
	}
};


int main()
{
    int ch;
    stack st;  //creating a stack class of the name st
    while (1) {
        cout << "\n1.push 2.pop 3.display 4.topp 5.isempty  6.exit\nEnter ur choice: "; cin >> ch;
        switch (ch) {
        case 1:
            cout << "enter the element: "; cin >> ch;
            st.push(ch);
            break;
        case 2:
            st.pop();
            break;
        case 3:
            st.display();
            break;
        case 4:
            st.topp();
            break;
        case 5:
        	cout<<st.empty()<<endl;
        	break;
        case 6:
        	return 0;
        }
    }
}

