class Twitter {
private:

    // user -> people they follow
    unordered_map<int, unordered_set<int>> following;

    // user -> {tweetId, time}
    unordered_map<int, vector<pair<int, int>>> tweets;

    int time = 0;

public:

    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {

        time++;

        tweets[userId].push_back({tweetId, time});
    }

    vector<int> getNewsFeed(int userId) {

        // {time, tweetId, userId, index}
        priority_queue<tuple<int, int, int, int>> pq;

        // User's own tweets
        if (!tweets[userId].empty()) {

            int index = tweets[userId].size() - 1;

            auto [tweetId, tweetTime] = tweets[userId][index];

            pq.push({
                tweetTime,
                tweetId,
                userId,
                index
            });
        }

        // Tweets from people user follows
        for (int followee : following[userId]) {

            if (!tweets[followee].empty()) {

                int index = tweets[followee].size() - 1;

                auto [tweetId, tweetTime] =
                    tweets[followee][index];

                pq.push({
                    tweetTime,
                    tweetId,
                    followee,
                    index
                });
            }
        }

        vector<int> result;

        while (!pq.empty() && result.size() < 10) {

            auto [tweetTime, tweetId, currentUser, index] =
                pq.top();

            pq.pop();

            result.push_back(tweetId);

            // Move to previous tweet of this user
            if (index > 0) {

                index--;

                auto [prevTweetId, prevTweetTime] =
                    tweets[currentUser][index];

                pq.push({
                    prevTweetTime,
                    prevTweetId,
                    currentUser,
                    index
                });
            }
        }

        return result;
    }

    void follow(int followerId, int followeeId) {

        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {

        following[followerId].erase(followeeId);
    }
};