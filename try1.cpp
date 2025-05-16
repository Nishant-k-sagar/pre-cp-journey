#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void codewithlove()
{
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll range = r - l + 1;

    r = min(r, n);

    l = max(1LL, l);
    ll start = l - 1;

    range = min(range, r);
    range = min(range, n - start);

    vector<ll> left, right;

    for (ll i = 0; i < r; i++) { 
        left.push_back(a[i]);
    }

    for (ll i = start; i < n; i++) {
        right.push_back(a[i]);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    ll lsum = 0;
    ll rsum = 0;

    for (ll i = 0; i < range; i++) {
        if (i < left.size()) {
            lsum += left[i];
        }

        if (i < right.size()) {
            rsum += right[i];
        }
    }

    cout << min(rsum, lsum) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        codewithlove();
    }

    return 0;
}
