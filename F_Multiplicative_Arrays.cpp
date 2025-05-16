#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    // Precompute results for each test case
    vector<vector<int>> results;
    results.reserve(t);

    int maxK = 0;
    vector<pair<int, int>> testCases(t);
    for (int i = 0; i < t; ++i) {
        int k, n;
        cin >> k >> n;
        testCases[i] = {k, n};
        maxK = max(maxK, k);
    }

    // To handle all k values up to the maximum k found
    vector<vector<int>> dp(maxK + 1, vector<int>(maxK + 1, 0));

    // Base case: dp[x][1] = 1 for all 1 <= x <= maxK
    for (int x = 1; x <= maxK; ++x) {
        dp[x][1] = 1;
    }

    // Fill dp table
    for (int len = 2; len <= maxK; ++len) {
        for (int x = 1; x <= maxK; ++x) {
            for (int factor = 1; factor <= x; ++factor) {
                if (x % factor == 0) {
                    dp[x][len] = (dp[x][len] + dp[x / factor][len - 1]) % MOD;
                }
            }
        }
    }

    // For each test case, compute the results
    for (const auto& [k, n] : testCases) {
        vector<int> answer(k + 1, 0);
        for (int x = 1; x <= k; ++x) {
            // Sum dp[x][1] to dp[x][min(n, k)]
            for (int len = 1; len <= min(n, k); ++len) {
                answer[x] = (answer[x] + dp[x][len]) % MOD;
            }
        }
        results.push_back(answer);
    }

    // Output the results
    for (const auto& result : results) {
        for (int i = 1; i < result.size(); ++i) {
            cout << result[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
