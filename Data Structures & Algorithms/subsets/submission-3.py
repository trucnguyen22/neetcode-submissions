class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        all_ = []

        def backtracking(i, subset):
            if (i == len(nums)):
                all_.append(subset[:])
                return

            backtracking(i+1, subset)

            subset.append(nums[i])
            backtracking(i+1, subset)
            subset.pop()

        backtracking(0, [])
        return all_

