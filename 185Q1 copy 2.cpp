#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    int n;
    ll h;
    cin >> n >> h;
    int d1 = 0, d2 = 0;
    ll ans = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        int s, d;
        cin >> s >> d;
        if (s == 1 && d > d1) d1 = d;
        if (s == 2 && d > d2) d2 = d;
        if (d >= h) ans = min(ans, (ll)s);
    }
    if (d1 > 0) {
        ll cnt = (h + d1 - 1) / d1;
        ans = min(ans, cnt);
    }
    if (d2 > 0) {
        ll cnt = (h + d2 - 1) / d2;
        ans = min(ans, cnt * 2);
    }
    if (d1 > 0 && d2 > 0) {
        ll maxi = (h + d2 - 1) / d2;
        for (ll k = max(0LL, maxi - 100); k <= maxi; ++k) {
            ll rem = h - k * d2;
            if (rem <= 0) {
                ans = min(ans, k * 2LL);
            } else {
                ll cnt1 = (rem + d1 - 1) / d1;
                ans = min(ans, k * 2LL + cnt1);
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    fast
        ll t;
    cin >> t;
    while (t--)
    {
        nottryingenouf();
    }
}