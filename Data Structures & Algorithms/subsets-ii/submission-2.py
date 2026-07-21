class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        # ITERATION METHOD
        # []
        # [1]
        # [2], [1, 2]

        # 1. only append to last-round subsets

        res = [[]]
        start, last = 0, 0
        nums.sort()

        for i in range(len(nums)):
            start = last if i > 0 and nums[i] == nums[i-1] else 0
            last = len(res)
            res += [res[j] + [nums[i]] for j in range(start, len(res))]
            print(res)

        return res
