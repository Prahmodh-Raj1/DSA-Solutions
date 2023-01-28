//Problem link: https://leetcode.com/problems/maximal-rectangle/

class Solution {
public:
//TC:O(N*M + N)  SC:O(N)
    int largestarea(vector<int>& hist){
        stack<int> st;
        int maxi=0;
        int n=hist.size();
        for(int i=0;i<=n;i++){
            while(!st.empty() and (i==n || hist[st.top()]>=hist[i])){
                int length=hist[st.top()];
                st.pop();
                int breadth;
                if(st.empty()) breadth=i;
                else breadth=i-st.top()-1;
                maxi=max(maxi,breadth*length);
            }
            st.push(i);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        //we require the largest histogram for every row
        int maxarea=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> height(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    height[j]++;
                }else height[j]=0;
            }
            int area=largestarea(height);
            maxarea=max(area,maxarea);
        }
        return maxarea;
    }
};
