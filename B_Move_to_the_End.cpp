#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define ld  double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    vector<ll> pmax(n);
    pmax[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        pmax[i] = max(pmax[i-1], arr[i]);
    }

    vector<ll> ssum(n+1, 0);
    for (int i = n-1; i >= 0; --i) {
        ssum[n-i] = ssum[n-i-1] + arr[i];
    }

    for (int k = 1; k <= n; ++k) {
        ll ans = ssum[k];
        if (n - k > 0) {
            ans = max(ans, pmax[n - k - 1] + ssum[k - 1]);
        }
        cout << ans << " ";
    }
    cout << endl;
    
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