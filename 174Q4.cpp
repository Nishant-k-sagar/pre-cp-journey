#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMaxPower(vector<int>& A) {
    int N = A.size();
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        dp[i][i] = A[i];
    }
    for (int len = 2; len <= N; len++) {
        for (int i = 0; i <= N - len; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                dp[i][j] = max(dp[i][j], max(0, abs(dp[i][k] - dp[k + 1][j])));
            }
        }
    }
    return dp[0][N - 1];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        cout << getMaxPower(A) << endl;
    }
    return 0;
}
