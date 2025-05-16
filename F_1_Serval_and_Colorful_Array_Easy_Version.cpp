#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    unordered_map<int, int> freq;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int left = 0, distinct = 0, min_swaps = INT_MAX;

    for (int right = 0; right < n; right++) {
        if (++freq[a[right]] == 1) { 
            distinct++; 
        }

        while (distinct == k) { 
            int window_size = right - left + 1;
            min_swaps = min(min_swaps, window_size - k);
            

            if (--freq[a[left]] == 0) {
                distinct--; 
            left++;
        }
    }

    cout << min_swaps << '\n';
}

int main() {
    fast
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
