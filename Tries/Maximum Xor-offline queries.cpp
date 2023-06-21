//Problem link: 
//TC: O(QLogQ) O(Q*32 +N)
//The trie needs to contain the elements lesser than or equal to a[i], then we can easily make out
//the max value of the xor values
//use offline queries to sort the queries in the ascending order of ai
//Maintain an array to store the answers of the queries in the array in the order of queries
//by maintaining the query no while sorting
//Sort the array to pick the values that are lesser than or equal to ai
//sorting the queries to ensure that the values are inserted into the trie smoothly
#include<bits/stdc++.h>
struct Node {
    Node *links[2]; 
 
    bool containsKey(int ind) {
        return (links[ind] != NULL); 
    }
    Node* get(int ind) {
        return links[ind]; 
    }
    void put(int ind, Node* node) {
        links[ind] = node; 
    }
}; 
class Trie {
    private: Node* root; 
public:
    Trie() {
        root = new Node(); 
    }
    
    public: 
    void insert(int num) {
        Node* node = root;
        // cout << num << endl; 
        for(int i = 31;i>=0;i--) {
            int bit = (num >> i) & 1; 
            if(!node->containsKey(bit)) {
                node->put(bit, new Node()); 
            }
            node = node->get(bit); 
        }
    }
    public:
    int findMax(int num) {
        Node* node = root; 
        int maxNum = 0; 
        for(int i = 31;i>=0;i--) {
            int bit = (num >> i) & 1; 
            if(node->containsKey(!bit)) {
                maxNum = maxNum | (1<<i); 
                node = node->get(!bit); 
            }
            else {
                node = node->get(bit); 
            }
        }
        return maxNum; 
    }
};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	vector<int> ans(queries.size(), 0); 
    vector<pair<int, pair<int,int>>> offlineQueries; 
    sort(arr.begin(), arr.end()); 
    int index = 0;
    for(auto &it: queries) {
        offlineQueries.push_back({it[1],{it[0], index++}}); 
    }
    sort(offlineQueries.begin(), offlineQueries.end()); 
    int i = 0; 
    int n = arr.size(); 
    Trie trie; 
    
    for(auto &it : offlineQueries) {
        while(i < n && arr[i] <= it.first) {
            trie.insert(arr[i]); 
            i++; 
        }
        if(i!=0) ans[it.second.second] = trie.findMax(it.second.first); 
        else ans[it.second.second] = -1;  //nothing has been inserted
    }
    return ans; 
}
