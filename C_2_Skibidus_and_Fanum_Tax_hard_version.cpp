#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    
    int maxB = *max_element(b.begin(), b.end()); // Get the maximum value from b
    
    for (int i = 0; i < n; i++) {
        a[i] = maxB - a[i]; // Apply the operation greedily using maxB
    }
    
    if (is_sorted(a.begin(), a.end())) {
        cout << "YES\n";
        return;
    }
    
    // If not sorted, check whether we can achieve sorted order with another approach
    sort(a.begin(), a.end());
    if (is_sorted(a.begin(), a.end())) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}