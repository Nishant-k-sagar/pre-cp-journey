#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios::sync_with_stdio(false), cin.tie(0);

void solve() {
    ll n;
    cin >> n;
    vector<ll> vec(n - 2);
    for (ll i = 0; i < n - 2; i++) {
        cin >> vec[i];
    }

    if (n == 3) {
        cout << "YES"<<endl;
        return;
    }

    for (ll i = 1; i < n - 3; i++) {
        if (vec[i - 1] == 1 && vec[i] == 0 && vec[i + 1] == 1) {
            cout << "NO"<<endl;
            return;
        }
    }

    cout << "YES"<<endl;
}

int main() {
    fast
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}
