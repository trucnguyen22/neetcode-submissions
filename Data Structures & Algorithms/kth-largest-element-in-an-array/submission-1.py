class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        minheap = []
        for i in range(k):
            minheap.append(nums[i])
        
        heapq.heapify(minheap)

        for i in range(k, len(nums)):
            heapq.heappush(minheap, nums[i])
            heapq.heappop(minheap)

        return minheap[0]