#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353

typedef long long ll;

// Function to calculate power with modulo
ll power(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> ones, threes;
    
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) ones.push_back(i);
        if (a[i] == 3) threes.push_back(i);
    }
    
    if (ones.empty() || threes.empty()) {
        cout << "0\n";
        return;
    }
    
    ll count = 0;
    for (int i : ones) {
        for (int j : threes) {
            if (i < j) {
                int twos = count_if(a.begin() + i + 1, a.begin() + j, [](int x) { return x == 2; });
                count = (count + power(2, twos, MOD)) % MOD;
            }
        }
    }
    
    cout << count << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}