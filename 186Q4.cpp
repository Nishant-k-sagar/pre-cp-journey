#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define MOD 998244353

void nottryingenouf()
{
    // try it harder
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    ll ans = 1;
    for (int i = 0; i < n; i++) {
        int temp = vec[i] - i;
        if (temp <= 0) {
            cout << 0 << endl;
            return;
        }
        ans = (ans * temp) % MOD;
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