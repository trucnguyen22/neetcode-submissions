class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        # [9,2,2,4,6,1,5]
        # [1,2,2,4,5,6,9]
        all_ = []
        candidates.sort()

        def search(i, subset, total):
            if total >= target or i >= len(candidates):
                if total == target:
                    all_.append(subset[:])
                return

            subset.append(candidates[i])
            search(i+1, subset, total+candidates[i])
            subset.pop()

            while i + 1 < len(candidates) and candidates[i] == candidates[i+1]:
                i += 1
            search(i+1, subset, total)

        search(0, [], 0)
        return all_