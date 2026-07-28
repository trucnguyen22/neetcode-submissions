class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        five, ten, twenty = 0, 0, 0
        # bills=[5,5,5,5,20,20,5,5,5,5]

        for b in bills:
            if b == 5:
                five += 1
            if b == 10:
                if five > 0:
                    five -= 1
                else:
                    return False
                ten += 1
            if b == 20:
                if five > 0 and ten > 0:
                    five -= 1
                    ten -= 1
                elif five > 2:
                    five -= 3
                else:
                    return False
        
        return True