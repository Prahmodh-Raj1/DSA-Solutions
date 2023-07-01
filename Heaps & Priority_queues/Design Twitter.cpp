//Problem link:  https://leetcode.com/problems/design-twitter/
class Twitter {
public:
    int cnt;  //indicates the time slots in which the tweets are added, used to retrieve the latest tweets
    
    unordered_map<int,unordered_set<int>> mpf;
    unordered_map<int,vector<pair<int,int>>> mpt;
    Twitter() {
        cnt=0;
    }
    
    void postTweet(int userId, int tweetId) {
        cnt++;
        mpt[userId].push_back({cnt++,tweetId});
       

    }
    
    vector<int> getNewsFeed(int userid) {
        vector<int> tweets;
        priority_queue<pair<int,int>> pq;
        for(auto it=mpt[userid].begin();it!=mpt[userid].end();it++){  //for self tweets
            pq.push(*it);
        }  
        for(auto it=mpf[userid].begin();it!=mpf[userid].end();it++){  //for others' tweets
            int user = *it;  //getting the target user, for each person followed
            for(auto it1=mpt[user].begin();it1!=mpt[user].end();it1++){  //getting the tweets of ppl who the current user 
                pq.push(*it1);
            }
        }
        while(!pq.empty()){
            tweets.push_back(pq.top().second);
            if(tweets.size()==10) break;
            pq.pop(); 
        }
        return tweets;

    }
    
    void follow(int followerId, int followeeId) {
        mpf[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mpf[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
