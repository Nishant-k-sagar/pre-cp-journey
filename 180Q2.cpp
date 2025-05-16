#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define ll long long

void solve() {
    ll n;
    cin >> n;

    // Starting with the score of 0
    ll maxScore = 0, minScore = 0;

    // Simulate the game round by round
    for (ll i = 1; i <= n; ++i) {
        ll delta = (1LL << (i - 1)) % MOD; // This is 2^(i-1) % MOD
        if (i % 2 == 1) {
            // Alice's turn: She tries to minimize the difference, so she can either
            // add or subtract to keep the range as small as possible.
            maxScore += delta;
            minScore -= delta;
        } else {
            // Bob's turn: He tries to maximize the difference, so he will try to
            // push the range as large as possible.
            maxScore += delta;
            minScore -= delta;
        }
    }

    // Calculate the difference X - Y
    ll result = (maxScore - minScore + MOD) % MOD;
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
