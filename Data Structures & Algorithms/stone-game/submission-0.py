class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        stones = {}  # stones[(l, r)]: total stones in (left, right) range

        def pick(l, r):
            if (l > r):
                return 0
            if (l, r) in stones:
                return stones[(l, r)]

            if (r - l + 1) % 2 == 1:
                piles[l] = piles[r] = 0

            stones[(l, r)] = max(
                pick(l + 1, r) + piles[l], 
                pick(l, r - 1) + piles[r]
            )

            return stones[(l, r)]

        alice = pick(0, len(piles) - 1)
        return alice > (sum(piles) - alice)
