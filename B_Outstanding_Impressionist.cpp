#include <bits/stdc++.h>
using namespace std;
#define ll long long

void codewithlove() {
    ll n;
    cin >> n;

    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    string res = "";
    unordered_map<ll, ll> freq;
    vector<ll> unique;

    for (auto &it : v) {
        if (it.first == it.second) {
            if (freq[it.first]++ == 0) {
                unique.push_back(it.first);
            }
        }
    }

    sort(unique.begin(), unique.end());

    for (auto &it : v) {
        ll l = it.first, r = it.second;

        if (l == r) {
            res += (freq[l] > 1) ? '0' : '1';
        } else {
            auto lower = lower_bound(unique.begin(), unique.end(), l);
            auto upper = upper_bound(unique.begin(), unique.end(), r);

            ll countInRange = distance(lower, upper);
            if (countInRange == (r - l + 1)) {
                res += '0';
            } else {
                res += '1';
            }
        }
    }

    cout << res << endl;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        codewithlove();
    }
    return 0;
}
