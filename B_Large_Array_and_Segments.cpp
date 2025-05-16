#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

int count(vector<ll>& arr, ll val) {
    return upper_bound(arr.begin(), arr.end(), val) - arr.begin();
}

void nottryingenouf()
{
    // try it harder
    int n, k;
    ll x;
    cin >> n >> k >> x;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<ll> brr(n);
    brr[0] = 0;
    for (int i = 1; i < n; i++) {
        brr[i] = brr[i - 1] + arr[i - 1];
    }
    
    ll sumArr = brr[n - 1] + arr[n - 1];

    if (k * sumArr < x) {
        cout << "0"<<endl;
        return;
    }

    ll tot = k * sumArr - x;
    ll ans = 0;

    for (int i = 0; i < k; i++) {
        ll lim = tot - (i * sumArr);
        if (lim < 0) break;
        ans += count(brr, lim);
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
