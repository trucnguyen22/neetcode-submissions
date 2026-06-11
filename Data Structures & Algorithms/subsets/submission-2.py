class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        # from [[]] -> [[], [1]] -> [[], [1], [2], [1, 2]] -> ...
        # 2*2*2*... = 2^n subsets

        res = [[]]
        for num in nums:
            res += [subset + [num] for subset in res]
        
        return res
