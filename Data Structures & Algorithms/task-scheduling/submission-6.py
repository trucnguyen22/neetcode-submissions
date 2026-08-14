class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        # x x y y
        # r1 x              queue r3 x
        # r2 x y            queue r3 x r4 y
        # r3 x y idle       
        # r4 x y idle x     
        # r5 x y idle x y

        counter = Counter(tasks)

        q = deque() # [(r_i, count), ...]
        maxheap = []
        for _, val in counter.items():
            heapq.heappush_max(maxheap, val)
            # print(val)
        
        # print(maxheap[0])
        
        cost = 0
        run = 1
        while q or maxheap:
            cost += 1

            if q and q[0][0] == run:
                heapq.heappush_max(maxheap, q[0][1])
                q.popleft()
            
            if maxheap:
                count = heapq.heappop_max(maxheap)
                count -= 1
                if count > 0:
                    q.append((run + n + 1, count))
                # print(q[0])

            run += 1

        return cost
