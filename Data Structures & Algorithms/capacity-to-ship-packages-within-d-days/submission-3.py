class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        def search(curr_cap):
            ship, cap = 1, curr_cap

            for w in weights:
                if (cap - w < 0):
                    ship += 1
                    cap = curr_cap
                cap = cap - w

            if ship <= days:
                return True
            return False

        l, r = max(weights), sum(weights)
        res = r
        while (l <= r):
            mid = (l + r) // 2
            if search(mid):
                res = mid
                r = mid - 1
            else:
                l = mid + 1
        
        return res

        # 1 2 3 4 5
        # target_days = 5

        # cap = 5: days = 3
        # cap = 6: days = 3
        # cap = 7: days = 3
        # cap = 8: days = 2
        # ...
        # cap = 15: days = 1



