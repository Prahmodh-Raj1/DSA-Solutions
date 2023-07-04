//Problem link : https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1
//TC: O(N) SC: O(N)
vector <int> countDistinct (int nums[], int n, int k)
    {
        //code here.
        map<int,int> mp;
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
        }
        vector<int> ans;
        ans.push_back(mp.size());
        for(int i=k;i<n;i++){
            int rem = nums[i-k];
            mp[rem]--;
            if(mp[rem]<=0){
                mp.erase(rem);
            }
            mp[nums[i]]++;
            ans.push_back(mp.size());
            
        }
        return ans;
    }
