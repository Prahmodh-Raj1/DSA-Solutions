//Problem link: https://leetcode.com/problems/my-calendar-
//TC: O(N*1000) SC:O(N)

class MyCalendar {
    vector<pair<int,int>> books;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto it:books){
            //an interval is overlapping if max(it.first,start) < min(it.second,end)
            if(max(it.first,start)<min(it.second,end)){
                return false;
            }

        }
        books.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
