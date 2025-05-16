#include <iostream>
#include <vector>
using namespace std;
const int MOD = 998244353;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> B(N);
        for (int i = 0; i < N; ++i) cin >> B[i];

        // Check for consistency
        bool valid = true;
        for (int i = 1; i < N-1; ++i) {
            int k = min(i+1, N-i);
            if (B[i] < max(B[i-1], B[i+1])) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            cout << 0 << '\n';
            continue;
        }

        // Count degrees of freedom
        long long ans = 1;
        for (int i = 1; i < N-1; ++i) {
            int k = min(i+1, N-i);
            if (B[i] > max(B[i-1], B[i+1])) {
                ans = (ans * (B[i] - max(B[i-1], B[i+1]))) % MOD;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
