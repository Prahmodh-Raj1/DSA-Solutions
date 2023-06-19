//Problem link: https://www.codingninjas.com/codestudio/problems/implement-trie_1387095
struct Node{
    Node *links[26];
    bool flag=false;
    int endwith=0;
    int countpref=0;
//on the flow, for every word's trie, we increase the count prefix and for every word that we are ending at, we increment the endwith for that particular trie
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    Node *get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    void increaseend(){
        endwith++;
    }
    void increaseCountPrefix(){
        countpref++;
    }
    void deleteEnd(){
        endwith--;
    }
    void decreaseCountPrefix(){
        countpref--;
    }
    int getEnd(){
        return endwith;
    }
    int getPrefix(){
        return countpref;
    }

}
#include <bits/stdc++.h> 
class Trie{
private:
    Node* root= new Node();

    public:

    Trie(){
        // Write your code here.
        root= new Node();  //for every object ,we are creating a new trie

    }

    void insert(string &word){
        // Write your code here.
        Node *node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){  //if the node doesn't contain the char, its not there
                node->put(word[i],new Node()); //creating a reference trie
            }
            node=node->get(word[i]);  //moving the pointer
            node->increaseCountPrefix();  //incrementing the prefix
        }
        node->increaseend;  //after completing adding the word
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);  //moving the pointer
            }else{  //if we can't find the entire word
                return 0;
            }
        }
        return node->getEnd();  //no.of words ending with the given word

    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
            }else return 0;  
        }
        return node->getPrefix();  //currently how many are there with that particular prefix
    }

    void erase(string &word){
        // Write your code here
        //we assume the word exists since we've been asked to erase it.
        Node* node= root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
                node->decreaseCountPrefix();  //decrementing the count of the prefix
            }else return;
        }
        node->deleteEnd();
    }
};
