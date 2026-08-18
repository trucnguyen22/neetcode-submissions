class MedianFinder:

    def __init__(self):
        self.small = []
        self.large = []

    def addNum(self, num: int) -> None:
        small, large = self.small, self.large

        if len(small) == 0 or len(large) == 0:
            if len(small) == 0:
                small.append(num)
            else:
                if small[0] > num:
                    large.append(small[0])
                    small.pop()
                    small.append(num)
                else:
                    large.append(num)
            return

        s0, l0 = small[0], large[0]
        if num > l0:
            heapq.heappush(large, num)
            while len(large) > len(small):
                heapq.heappush_max(small, heapq.heappop(large))
        else:
            heapq.heappush_max(small, num)
            while len(small) - 1 > len(large):
                heapq.heappush(large, heapq.heappop_max(small))
            
    def findMedian(self) -> float:
        small, large = self.small, self.large
        # print("-" * 5)
        # print(small)
        # print(large)
        # print("-" * 5)
        if len(small) > len(large):
            return float(small[0])
        else:
            return (float(small[0]) + float(large[0])) / 2.0
        
        