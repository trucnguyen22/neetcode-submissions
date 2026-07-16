class Solution:
    def maxScore(self, s: str) -> int:
        zeros, ones = [], []
        c_0, c_1 = 0, 0

        for n in s:
            if n == '0':
                c_0 += 1 
                zeros.append(c_0)
                ones.append(c_1)
            else: 
                c_1 += 1
                zeros.append(c_0)
                ones.append(c_1)

        total = 0
        for idx in range(0, len(s) - 1):
            total = max(total, zeros[idx] + ones[len(s)-1] - ones[idx])
            # print(zeros[idx] + ones[len(s)-1] - ones[idx])

        return total