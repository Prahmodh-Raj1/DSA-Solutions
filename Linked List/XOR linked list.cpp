//Problem link: https://practice.geeksforgeeks.org/problems/xor-linked-list/1
//TC: O(N) SC: O(1)
/*
Structure of linked list is as
struct Node
{
    int data;
    struct Node* npx;

    Node(int x){
        data = x;
        npx = NULL;
    }
};

Utility function to get XOR of two Struct Node pointer
use this function to get XOR of two pointers
struct Node* XOR (struct Node *a, struct Node *b)
{
    return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}
*/

// function should insert the data to the front of the list
struct Node *insert(struct Node *head, int data) {
    // Code here
    struct Node* node = new Node(data);
    node->npx = head;
    if(head!=NULL){
        head->npx = XOR(node,head->npx);
    }
    head=node;
    return head;
    
}

vector<int> printList(struct Node *head) {
    // Code here
    struct Node* cur = head;
    struct Node* prev=NULL;
    struct Node* next;
    vector<int> v;
    while(cur){
        v.push_back(cur->data);
        next = XOR(prev,cur->npx);
        prev=cur;
        cur=next;
    }
    return v;
}

//Reference and explanation: https://www.geeksforgeeks.org/xor-linked-list-a-memory-efficient-doubly-linked-list-set-1/
