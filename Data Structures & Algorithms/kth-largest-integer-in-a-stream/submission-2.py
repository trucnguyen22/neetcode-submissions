class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.arr = nums
        heapq.heapify(nums)
        while len(nums) > k:
            heapq.heappop(nums)

    def add(self, val: int) -> int:
        heapq.heappush(self.arr, val)
        if (len(self.arr) > self.k): 
            heapq.heappop(self.arr)
        print(val)
        return self.arr[0]
        
