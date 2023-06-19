//Problem link: https://www.codingninjas.com/studio/problems/count-distinct-substrings_985292?leftPanelTab=1 
//TC: O(N^2)

struct Node{
    Node *links[26];
    bool containsKey(char ch){
        return links[ch-'a'];
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    Node* put(char ch,Node* node){
        links[ch-'a']=node;
    }
};
//no need of a trie class, as we just need the number(count of substrings)
int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    int cnt=0;
    Node* root= new Node();
    for(int i=0;i<s.size();i++){
        Node* node=root;
        for(int j=i;j<s.size();j++){
            if(!node->containsKey(s[j])){
                cnt++; //incrementing the counter whenever we add a new node to the trie
                node->put(s[j], new Node());
            }
            node=node->get(s[j]);
        }
        
    }
    return cnt+1;

}
