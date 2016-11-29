class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        message_queue.push_back(make_pair(userId, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        int len = message_queue.size();
        
        for (int i = len-1; i >= 0; --i) {
            auto msg = message_queue[i];
            int id = msg.first;
            if (id == userId || (followmap.find(userId) != followmap.end() && followmap[userId].count(id))) {
                result.push_back(msg.second);
                if (result.size() >= RecentTweet) break;
            }
        }
        
        return result;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        followmap[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followmap.find(followerId) == followmap.end()) return;
        
        followmap[followerId].erase(followeeId);
    }
    
private:
    unordered_map<int, unordered_set<int>> followmap;
    vector<pair<int, int>> message_queue;
    const int RecentTweet = 10;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
