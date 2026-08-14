class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        minheap: list[tuple] = []
        for p in points:
            x, y = p
            minheap.append((x**2 + y**2, x, y))
            print((x^2 + y^2, x, y))
        
        heapq.heapify(minheap)
        print(minheap[0])

        res = []
        while k:
            dis, x, y = heapq.heappop(minheap)
            res.append([x, y])
            k -= 1
        
        return res