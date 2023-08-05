//problem link: https://leetcode.com/problems/online-stock-span/
//TC: O(N) SC: O(N)
class StockSpanner {
private:
    stack<pair<int,int>> st; //stores the price,count
    //the second parameter will store the number of days for which the current stock can be valid
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt=1;
        while(!st.empty() && st.top().first<=price){  //previous greater element stack
            //keep popping and adding to count, the previous stock's spans to the current stock's span
            cnt+=st.top().second;
            st.pop();
        }
        st.push({price,cnt});
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
