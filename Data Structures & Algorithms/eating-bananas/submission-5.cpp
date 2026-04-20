class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Hint 1
        // Hint 2

        int lo = 1, hi = *max_element(piles.begin(), piles.end()), mid;
        int k = -1;

        while (lo <= hi) {
            mid = (hi + lo) / 2;
            int time = costToEatAllBananas(piles, mid);
            if (time > h) {
                lo = mid + 1;
            } else {
                k = mid;
                hi = mid - 1;
            }
        }

        return k == -1 ? hi : k;
    }

    int costToEatAllBananas(vector<int>& piles, int k) {
        int time = 0;
        for (int i = 0; i < piles.size(); i++) {
            time += ceil(double(piles[i]) / k);
        }

        return time;
    }
};
