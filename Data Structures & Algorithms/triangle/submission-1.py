import copy
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        total = copy.deepcopy(triangle)
        for i in range(len(triangle)):
            for j in range(len(triangle[i])):
                total[i][j] = 1e4
                if (i - 1) < 0:
                    total[i][j] = triangle[i][j]
                    print(total[i][j])
                    print(triangle[i][j])
                    continue
                
                if j - 1 >= 0 and j - 1 < len(triangle[i-1]):
                    total[i][j] = min(
                        total[i][j],
                        triangle[i][j] + total[i-1][j-1]
                    )
                if j < len(triangle[i-1]):
                    total[i][j] = min(
                        total[i][j],
                        triangle[i][j] + total[i-1][j]
                    )

        res = 1e6
        for j in range(len(total[-1])):
            res = min(res, total[-1][j])
            # print(total[-4][j])

        return res