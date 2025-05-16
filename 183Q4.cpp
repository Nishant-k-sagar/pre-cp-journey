#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    ll n, m;
    cin>>n>>m;

    if (n <= 1) {
        cout<<0<<endl;
        return;
    }

    ll total = n * (n - 1) / 2;
    ll rem = total - m;

    ll min_w = max(0ll, n - 1 - rem);

    ll l = 1, r = n, k = n;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (mid * (mid - 1) >= 2 * rem) {
            k = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    ll max_w = n - k;
    ll cnt = max_w - min_w + 1;

    if (cnt > 0) cout<< (min_w + max_w) * cnt / 2<<endl;
    else cout<<0<<endl;
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