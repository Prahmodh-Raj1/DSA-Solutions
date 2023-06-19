//problem link: https://www.codingninjas.com/codestudio/problems/complete-string_8230849?leftPanelTab=1
//TC: O(N)*O(len of each word on avg) + O(N*len) - to check if it's a complete string

#include <bits/stdc++.h>
struct Node{
    Node *links[26];
    bool flag=false;
    bool containsKey(char ch){
        return links[ch-'a'];
    }
    Node *get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    void setEnd(){
        flag=true; //reached the end of the string
    }
    bool isEnd(){
        return flag; //have we reached the end of the string
    }

};
class Trie{
    Node *root = new Node();
    
    public:
    Trie(){
        root=new Node();
    }
    void insert(string word){
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    bool checkIfPrefixExists(string word){
        bool fl=true;
        Node *node=root;
        for(int i=0;i<word.length();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
                if(!node->isEnd()) return false; //if the current prefix is not there, we return a false

            }else return false;
        }
        return true;
    }

};
string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie trie;
    for(auto it:a) trie.insert(it);
    string longest="";
    for(auto it:a){
        if(trie.checkIfPrefixExists(it)){
            if(it.length()>longest.length()){
                longest=it;
            }
            else if(it.length()==longest.length() and it<longest){  //checking the lexicographically smallest string
                longest=it;
            }
        }
    }
    if(longest=="") return "None";
    return longest;
}
