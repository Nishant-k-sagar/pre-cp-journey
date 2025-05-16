#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    ll n, k, d;
    cin >> n >> k >> d;

    vector<ll> arr(n);
    for (ll i = 0; i < n; ++i)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    ll cnt = 0;
    for (ll i = 0; i < max(0LL, n - k); ++i)
    {
        cnt += (d + arr[i] - 1) / arr[i];
    }

    cout << cnt << endl;
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