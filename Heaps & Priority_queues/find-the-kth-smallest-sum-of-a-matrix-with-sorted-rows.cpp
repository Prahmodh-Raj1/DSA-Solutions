//Problem link: https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows
class Solution {
public:
    void findpair(int i,int j,vector<vector<int>>& mat,int k,priority_queue<int>& pq){

    }
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> row(mat[0]);
        for(int i=1;i<mat.size();i++){
            vector<int> nextrow; //next row
            for(int j=0;j<mat[i].size();j++){
                for(auto pathsum:row){
                    nextrow.push_back(mat[i][j]+pathsum);
                }
                //cout<<"\nwithin loop 1: \n";
                //for(auto it:nextrow) cout<<it<<" ";
                //cout<<"\n";
            }
            sort(nextrow.begin(),nextrow.end());
            //cout<<"\nwithin loop 2-posts sort\n";
            //for(auto it:nextrow) cout<<it<<" ";
            nextrow.resize(min(k,(int)nextrow.size()));  //retaining only k elements
            row = move(nextrow); //store first k elements from nextrow in row and swap it 
            //cout<<"post swap:\n";
            //for(auto it:row) cout<<it<<" ";
            //cout<<"\n";
            /*
            //row = vector<int>(nr.begin(), nr.begin() + min(k, int(nr.size())) ); //ok   
            //swap(row, nr); // ok
            //row=nr;        // ok   
            */
        }
        return row[k-1];
    }
};
