#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

bool chk(string& s, int k) {
    int cnt = 1;
    for (int i = 1; i < s.size(); ++i) {
        cnt = (s[i] == s[i - 1]) ? cnt + 1 : 1;
        if (cnt >= k) return false;
    }
    return true;
}

string nottryingenouf() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    vector<int> l(n), r(n);
    l[0] = 1;
    for (int i = 1; i < n; ++i)
        l[i] = (s[i] == s[i - 1]) ? l[i - 1] + 1 : 1;

    r[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i)
        r[i] = (s[i] == s[i + 1]) ? r[i + 1] + 1 : 1;

    int cnt = *max_element(l.begin(), l.end());
    if (cnt < k) return "YES";

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < min(n, i + 2 * k); ++j) {
            string temp = s;
            reverse(temp.begin() + i, temp.begin() + j + 1);
            if (chk(temp, k)) return "YES";
        }
    }

    return "NO";
}

int main() {
    fast
    ll t;
    cin >> t;
    while (t--) {
        cout << nottryingenouf() << '\n';
    }
}
