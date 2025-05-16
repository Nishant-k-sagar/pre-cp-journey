#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll codewithlove(ll n, unordered_map<ll, ll>& mp) {
    if (n <= 3) return 1;

    if (mp.count(n)) return mp[n];

    ll split = n / 4;
    ll ans = 2 * codewithlove(split, mp);

    return mp[n] = ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        unordered_map<ll, ll> mp;
        ll n;
        cin >> n;

        cout << codewithlove(n, mp) << endl;
    }

    return 0;
}
