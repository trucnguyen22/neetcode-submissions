class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        heapq.heapify_max(stones)

        while len(stones) > 1:
            first = heapq.heappop_max(stones)
            second = heapq.heappop_max(stones)

            new = abs(first - second)
            if new:
                heapq.heappush_max(stones, new)

        if len(stones) == 1:
            return stones[0]
        return 0