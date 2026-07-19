class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        self.res = []
        self.backtrack([], nums, 0)
        return self.res

    def backtrack(self, perms, nums, mask):
        if (len(perms) == len(nums)):
            self.res.append(perms[:])
            return

        for i in range(len(nums)):
            if not (mask & (1 << i)):
                perms.append(nums[i])
                self.backtrack(perms, nums, mask | (1 << i))
                perms.pop()