//Problem link: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1?
static bool comp(pair<int,int>& p1,pair<int,int>& p2){
        return p1.second<p2.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> times;
        for(int i=0;i<n;i++){
            times.push_back({start[i],end[i]});
        }
        sort(times.begin(),times.end(),comp);
        int cnt=1;
        int prevend = times[0].second;
        for(int i=1;i<n;i++){
            if(times[i].first>prevend){
                prevend = times[i].second;
                cnt++;
            }
        }
        return cnt;
        
    }

//Meeting rooms 2: https://www.geeksforgeeks.org/minimum-halls-required-for-class-scheduling/
