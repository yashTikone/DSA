class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();

        vector<int> diff(n);
        int high = 0;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            high = max(high, diff[i]);
            sum += diff[i];
        }

        if (sum <= k)
            return 0;

        int low = 0;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long operations = 0;

            for (int x : diff) {
                if (x > mid)
                    operations += x - mid;
            }

            if (operations <= k)
                high = mid;
            else
                low = mid + 1;
        }

        long long ans = 0;
        long long operations = 0;

        for (int x : diff) {
            if (x > low) {
                operations += x - low;
                x = low;
            }
            ans += 1LL * x * x;
        }

        long long remaining = k - operations;

        for (int i = 0; i < n && remaining > 0; i++) {
            if (diff[i] >= low && diff[i] > 0) {
                ans -= 2LL * low - 1;
                remaining--;
            }
        }

        return ans;
    }
};
