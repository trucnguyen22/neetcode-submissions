class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []

        def generate(i, subset):
            res.append(subset.copy())

            for j in range(i, len(nums)):
                if j > i and nums[j] == nums[j-1]:
                    continue
                subset.append(nums[j])
                generate(j+1, subset)
                subset.pop()
            
        generate(0, [])
        return res