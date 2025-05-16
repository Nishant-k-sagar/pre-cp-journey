#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    int mini = min(n / (m + 1), n - m * k);
    
    vector<int> arr(n, mini);
    
    if (m == 0) {
        for (int i = 0; i < mini; i++) {
            arr[i] = i;
        }
    } else {
        int block = (n - mini) / m;
        if (block == 0) block = 1;
        
        for (int i = 0; i < mini; i++) {
            for (int j = 0; j <= m; j++) {
                int pos = i + j * block;
                if (pos < n) {
                    arr[pos] = i;
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    fast
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}