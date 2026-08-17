class Twitter:

    def __init__(self):
        self.time = 0
        self.map_followee: defaultdict(set) = {}
        self.map_tweet: Dict[int, List[Tuple[int, int]]] = {}

    def postTweet(self, userId: int, tweetId: int) -> None:

        if userId not in self.map_tweet:
            self.map_tweet[userId] = []
        tweets = self.map_tweet[userId]

        heapq.heappush(tweets, (self.time, tweetId))
        if len(tweets) > 10:
            heapq.heappop(tweets)

        self.time += 1

    def getNewsFeed(self, userId: int) -> List[int]:
        if userId not in self.map_followee:
            self.map_followee[userId] = {}
        followees = self.map_followee[userId]
        if userId not in self.map_tweet:
            self.map_tweet[userId] = []
        cur_tweets = self.map_tweet[userId]

        all_tweets = []

        all_tweets.extend(cur_tweets.copy())
        for fId in followees:
            other_tweets = self.map_tweet[fId]
            all_tweets.extend(other_tweets.copy())

        res: List[int] = []
        heapq.heapify_max(all_tweets)
        count = 10
        while (all_tweets and count > 0):
            res.append(heapq.heappop_max(all_tweets)[1])
            count -= 1
        return res

    def follow(self, followerId: int, followeeId: int) -> None:
        if followerId == followeeId:
            return
        if not isinstance(self.map_followee.get(followerId), set):
            self.map_followee[followerId] = set()
        self.map_followee[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followerId == followeeId:
            return
        if followerId in self.map_followee:
            self.map_followee[followerId].discard(followeeId)
