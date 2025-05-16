#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    
    for (int i = 0; i < k; i++) {
        int pos = -1;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0' && s[i+1] == '1') {
                pos = i;
                break;
            }
        }
        
        if (pos == -1) break;
        
        s[pos] = '1';
    }
    
    int cnt1 = count(s.begin(), s.end(), '1');
    cout << cnt1 << endl;
}

int main() {
    fast
    ll t;
    cin >> t;
    while (t--) {
        nottryingenouf();
    }
}
