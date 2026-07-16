class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        ins, des = True, True
        pre = nums[0]

        for i in range(1, len(nums)):
            if (nums[i] < pre):
                ins = False
            if (nums[i] > pre):
                des = False

            pre = nums[i]

        return ins or des