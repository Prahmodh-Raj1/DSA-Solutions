//Problem link: https://leetcode.com/problems/closest-room/description/
//TC: O( MAX(NlogN,MlogM)) N: rooms.size(), M: queries.size(),  SC:O(N)
class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        for(int i = 0; i < queries.size(); i++) queries[i].push_back(i);  //adding the particular index of the query, useful to create the answer vector at the end

        sort(queries.begin(), queries.end(), [](auto &a, auto &b) {
            
            return a[1] > b[1];  //sorting in descending order of minsize
        });
        sort(rooms.begin(), rooms.end(), [](auto &a, auto &b){
            return a[1] > b[1];  //sorting in descending order of size
        });
        int i = 0;
        set<int> st; //used to store the valid room-id's which have size>=minsize
        //we can iterate from the largest minSize query and put all the valid room to an ordered set, and then do binary search to get room id in the ordered set.
        vector<int> ans(queries.size());
        for(auto q : queries) {
            int prefer = q[0], minSize = q[1], idx = q[2];
            while(i < rooms.size() && rooms[i][1] >= minSize)
                st.insert(rooms[i++][0]);  //adding all the roomids, that have size greater than minsize
            if(st.size()) {
                auto it = st.upper_bound(prefer);  //applying bsearch on the set, returns an interator
                int res = it != st.end() ? abs(*it - prefer) : INT_MAX;  //if it's not the last index of set,assign absolute difference, which is essentially the difference btwn the preferred room id and the current upper-bounded roomid 
                int resRoomId = it != st.end() ? *it : INT_MAX;  //if it's not the last index of set,assign abs(*it-prefer) to the room id
                if(it != st.begin()) {
                    --it;
                    if(abs(*it - prefer) <= res)  //res is the difference of the upperbounded roomid with the preferred room id
                        resRoomId = *it;  //trying to find the minimal difference's roomid
                }
                ans[idx] = resRoomId;
            }else
                ans[idx] = -1;
        }
        return ans;
    }
};
