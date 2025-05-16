#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios::sync_with_stdio(false), cin.tie(0);

const ll maxi = 1e6 + 5;
vector<bool> prime(maxi, true);

void sieve() {
    prime[0] = prime[1] = false;
    for (ll i = 2; i * i < maxi; i++) {
        if (prime[i]) {
            for (ll j = i * i; j < maxi; j += i) {
                prime[j] = false;
            }
        }
    }
}

void nottryingenouf(ll x) {
    ll y = sqrt(x);
    if (y * y == x && prime[y]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    fast;
    sieve();
    ll n;
    cin >> n;
    while (n--) {
        ll x;
        cin >> x;
        nottryingenouf(x);
    }
    return 0;
}
