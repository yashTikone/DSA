class Solution {
public:
    long long func(vector<int>& piles, int n, int speed) {
        long long j = 0;

        for (int i = 0; i < n; i++) {
            j += piles[i] / speed;

            if (piles[i] % speed != 0) {
                j++;
            }
        }

        return j;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int res = -1;

        while (low <= high) {
            int guess = low + (high - low) / 2;

            long long hour = func(piles, n, guess);

            if (hour > h) {
                low = guess + 1;
            }
            else {
                res = guess;
                high = guess - 1;
            }
        }

        return res;
    }
};