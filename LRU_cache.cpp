//Problem link: https://leetcode.com/problems/lru-cache/
class LRUCache {
public:
//using a hashmap and a DLL
//mpa stores {key,node address}
//initially have the head and the tail nodes in the DLL, and keep adding elements onto the DLL, as the capacity permits
//Keep inserting the keys,values right after the head in the order in which the request is made
//when we are eliminating nodes from the DLL, we remove the node which is closer to the tail
    class node{
        public:
            int key;
            int val;
            node* next;
            node* prev;
            node(int _key,int _val){
                key=_key;
                val=_val;
            }
    };
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    int size;
    unordered_map<int,node*> mp;
    LRUCache(int capacity) {  //initial configuration
        size=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void deletenode(node* oldnode){
        node* delprev=oldnode->prev;
        node* delnext=oldnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
        
    }
    void addnode(node* newnode){
        node* cur=head->next;
        head->next=newnode;
        newnode->prev=head;
        newnode->next=cur;
        cur->prev=newnode;
        
    }
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            node* curnode = mp[key];
            int res= curnode->val;
            mp.erase(key); //removing the old address
            //reorder process
            deletenode(curnode);
            addnode(curnode);
            mp[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node* curnode= mp[key];
            mp.erase(key);
            deletenode(curnode);
        }
        if(mp.size()==size){
            mp.erase(tail->prev->key); //removing the LRU node
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
