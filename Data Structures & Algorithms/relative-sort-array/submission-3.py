class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        count = {}
        for a in arr2:
            if a not in count:
                count[a] = 0
        
        for a in sorted(arr1):
            if a in count:
                count[a] += 1
            else: count[a] = 1
        
        res = []
        # O(n * m)
        for a in count:
            fre = count[a]
            for _ in range(fre):
                res.append(a)

        return res
