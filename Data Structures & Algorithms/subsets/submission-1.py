class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        # Hint 1: from [1] -> [[], [1]]
        # Hint 2: set [abc] -> 2*2*2 subsets
        # Hint 3: use 'backtracking' to generate all subsets (select or not)
        # Hint 4: when 'i' == end, we know it forms a subset (tree)
        
        res = []
        def backtracking(subset, i):
            if i >= len(nums):
                res.append(subset.copy())
                return

            # select 
            subset.append(nums[i])
            backtracking(subset, i+1)

            # NOT select
            subset.pop()
            backtracking(subset, i+1)
            
        backtracking([], 0)
        return res
