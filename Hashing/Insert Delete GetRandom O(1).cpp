//Problem link: https://leetcode.com/problems/insert-delete-getrandom-o1/
//TC: O(1) SC: O(2*N)
/*Description
Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called).
Each element must have the same probability of being returned.*/
class RandomizedSet {
private:
    unordered_map<int,int> mp;
    vector<int> vals;
public:
    
    RandomizedSet() {
            
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }
        
        vals.push_back(val);
        mp[val]=vals.size()-1; //keeping track of the last index in vector
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)!=mp.end()){
          //trick to remove an element in O(1) from a vector
          //If the element you are trying to remove is the last element in the vector, remove it, done, ELSE,
Read the last element of the vector and write it over the element-to-be-removed. (swap is O(1))
Now remove the last element of the vector. (C++ pop_back() in a vector is O(1))*/
Refer problem : https://leetcode.com/problems/insert-delete-getrandom-o1/
            int last = vals.back();  
            mp[last]=mp[val];
            vals[mp[val]]=last;
            mp.erase(val);
            vals.pop_back();
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return vals[rand() % vals.size()];  //a vector is essentially used to return random values
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
