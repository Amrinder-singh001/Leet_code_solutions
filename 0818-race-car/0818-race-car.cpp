class Solution {
public:
    int racecar(int target) {

        vector<int> dp(target + 1, INT_MAX);

        dp[0] = 0;

        for(int i = 1; i <= target; i++) {

            int n = 1;

            while((1 << n) - 1 < i) {
                n++;
            }

            if((1 << n) - 1 == i) {
                dp[i] = n;
                continue;
            }

            // Case 1: target cross
            dp[i] = n + 1 + dp[(1 << n) - 1 - i];

            // Case 2: target back
            for(int m = 0; m < n - 1; m++) {

                int remaining = i - ((1 << (n - 1)) - 1)
                                  + ((1 << m) - 1);

                dp[i] = min(dp[i],
                    n + m + 1 + dp[remaining]);
            }
        }

        return dp[target];
    }
};