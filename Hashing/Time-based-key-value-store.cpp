//Problem link: https://leetcode.com/problems/time-based-key-value-store
//TC: O(logN) SC: O(N)
/*Description:
Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

TimeMap() Initializes the object of the data structure.
void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. 
If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".
*/
class TimeMap {
private:
    unordered_map<string,map<int,string>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].insert({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto it = mp[key].upper_bound(timestamp);  //finds the first value larger than the given value
        if(it==mp[key].begin()){  //if none is found
            return "";
        }
        it--;  //decrementing  to get the closest to timestamp
        return it->second; //returns the value
    }
};
/*We use hash map to lookup ordered {timestamp, value} pairs by key in O(1). Then, we use binary search to find the value with a timestamp less or equal than the requested one*/

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
