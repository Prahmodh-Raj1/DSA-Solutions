Q.Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0] 
        //brute force
		vector<int> answer;
        for(int i=0;i<temperatures.size();i++){
            int temp=temperatures[i];
            int dif=0;
            for(int j=i;j<temperatures.size();j++){
                if(temperatures[j]>temp){
                    dif=j-i;
                    break;
                }
            }
            if(dif==0){
                answer.push_back(0);
            }else{
                answer.push_back(dif);
            }
        }
        return answer;
    }
    
    //optimized
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        stack<int> s;
        vector<int> res(n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() and t[i]>=t[s.top()]) s.pop();
            if(s.empty())res[i]=0;
            else res[i]=s.top()-i;
            s.push(i);
        }
      return res;
    }

//using a stack of pairs:
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<pair<int,int>> st;
        int n= t.size();
        vector<int>  res(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and st.top().first<=t[i]){
                st.pop();
            }
            if(!st.empty()){
                res[i]=st.top().second-i;
            }else{
                res[i]=0;
            }
            st.push({t[i],i});
        }

      return res;
    }
};
