//Problem link: https://www.codingninjas.com/studio/problems/maximum-xor_973113?leftPanelTab=0
//TC : O(N*32) + O(M*32)

struct Node{
    Node* links[2];
    bool containsKey(int bit){
        return links[bit]!=NULL;
    }
    Node* get(int bit){
        return links[bit];
    }
    void put(int bit,Node* node){
        links[bit]=node;
    }
};
class Trie{
public:
    Node* root= new Node();
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i) & 1; //checking if the i'th bit is contained or not
            if(!node->containsKey(bit)){
                //currently not there, we need to put that bit
                node->put(bit, new Node());
            }
            node=node->get(bit);
        }
    }
    int getMax(int num){
        Node* node=root;
        //we need to start from the back of the binary representation now
        int maxvalue=0;
        for(int i=31;i>=0;i--){
            int bit = (num>>i) & 1;
            if(node->containsKey(1-bit)){
                //if it contains the opposite bit
                maxvalue=maxvalue | (1<<i);  //we can surely make this bit 1
                node=node->get(1-bit);
            }else{
                node=node->get(bit);  //if the opposite bit is not there
            }
        }
        return maxvalue;
    }
};
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    // Write your code here. 
    int maxval=0;
    Trie trie;
    for(auto it:arr1) trie.insert(it);
    for(auto it:arr2){
        maxval= max(maxval,trie.getMax(it));
    }
    return maxval;  
}
