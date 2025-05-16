#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll codewithlove(ll n, ll k) {
    if (n < k) return 0;

    queue<pair<ll, ll>> q;
    q.push(make_pair(1, n));
    ll ans = 0;

    while (!q.empty()) {
        auto range = q.front();
        q.pop();

        ll l = range.first;
        ll r = range.second;

        if (r - l + 1 < k) continue;

        ll m = (l + r) / 2;

        if ((r - l + 1) % 2 == 1) {
            ans += m;
            if (m - 1 >= l) q.push(make_pair(l, m - 1));
            if (m + 1 <= r) q.push(make_pair(m + 1, r));
        } else {
            if (m >= l) q.push(make_pair(l, m));
            if (m + 1 <= r) q.push(make_pair(m + 1, r));
        }
    }

    return ans;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    ll ans = codewithlove(n, k);
    cout << ans << endl;
}

int main() {
    ll t;
    cin >> t;

    while (t--) {
        
    }

    return 0;
}
