#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld ll double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    ll D, d, p, Q;
    cin >> D >> d >> p >> Q;

    ll x = D / d;
    ll y = D % d;

    ll ans = (x * (2 * p + (x - 1) * Q)) / 2;
    ans = ans * d;
    ans += (p + x * Q) * y;

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