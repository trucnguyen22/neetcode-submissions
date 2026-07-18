class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        all_ = []

        def search(i, subset, total):
            if total >= target or i == len(nums):
                if total == target: all_.append(subset[:])
                return

            subset.append(nums[i])
            search(i, subset, total + nums[i])

            subset.pop()
            search(i+1, subset, total)

        search(0, [], 0)
        return all_
            
            