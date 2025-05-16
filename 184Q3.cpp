#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD 998244353
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    ll n;
    cin >> n;
    vector<ll> arr(n);
    vector<ll> mp(n, 0);
    for (ll i = 0; i < n; ++i)
    {
        cin >> arr[i];
        if (arr[i] >= n)
            mp[0] = -1;
        else
            mp[arr[i]]++;
    }
    if (mp[0] == -1)
    {
        cout << 0 << endl;
        return;
    }

    ll ans = 1;
    for (ll i = 0; i < n; ++i)
    {
        ll possible = 0;
        if (mp[i] > 0)
            possible += mp[i];
        if (i != n - 1 - i && mp[n - 1 - i] > 0)
            possible += mp[n - 1 - i];
        if (possible == 0)
        {
            ans = 0;
            break;
        }

        if (mp[i] > 0)
            mp[i]--;
        else
            mp[n - 1 - i]--;
        ans = (ans * possible) % MOD;
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