#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    ll n, m, l, r;
    cin >> n >> m >> l >> r;

    ll a = min(-l, m);
    ll b = -a;
    ll c = m - a;

    cout << b << " " << c << endl;
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