#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    int n;
        cin >> n;
        string s, t;
        cin >> s >> t;

        if (s[0] != t[0]) {
            cout << -1 << endl;
            return;
        }
        if (s == t) {
            cout << 0 << endl;
            return;
        }

        int idx1s = -1, idx1t = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                idx1s = i;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (t[i] == '1') {
                idx1t = i;
                break;
            }
        }

        if (idx1s != idx1t) {
            cout << -1 << endl;
            return;
        }

        vector<int> ops;

        for (int i = idx1s + 1; i < n; i++) {
            if (s[i] == '0') {
                s[i] = '1';
                ops.push_back(i);
            }
        }

        for (int i = n - 1; i > idx1s; i--) {
            if (s[i] != t[i]) {
                s[i] = t[i];
                ops.push_back(i);
            }
        }

        if (s == t) {
            cout << ops.size() << endl;
            for (int i : ops) cout << i << " ";
            cout << endl;
        } else {
            cout << -1 << endl;
        }
}

int main()
{
    fast
        ll t;
    cin >> t;
    while (t--)
    {
        nottryingenouf();
    }
}