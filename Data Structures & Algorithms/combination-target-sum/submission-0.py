class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []

        def backtracking(i, group):
            if sum(group) >= target or i == len(nums):
                if sum(group) == target: res.append(group.copy())
                return

            group.append(nums[i])
            backtracking(i, group)

            group.pop()
            backtracking(i+1, group)

        backtracking(0, [])
        return res
            
            