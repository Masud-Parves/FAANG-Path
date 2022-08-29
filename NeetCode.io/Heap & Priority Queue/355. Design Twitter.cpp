class Twitter {
private:
    vector<pair<int, int>> tweets;
    unordered_map<int, unordered_set<int>> userFollowing;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        int taken = 10;
        
        for(int i=tweets.size()-1; i>=0; i--){
            if(taken == 0) break;
            int whoTweet = tweets[i].first;
            int tweet = tweets[i].second;
            
            unordered_set<int> following = userFollowing[userId];
            if(following.find(whoTweet) != following.end() || whoTweet == userId){
                result.push_back(tweet);
                taken--;
            }
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        userFollowing[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(userFollowing[followerId].find(followeeId) != userFollowing[followerId].end())
            userFollowing[followerId].erase(followeeId);
    }
};