#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int tot = n * m;
    int ans = tot;

    for (int row = -1; row <= 1; row += 2) {
        for (int col = -1; col <= 1; col += 2) {
            map<int, int> mp;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int val = a[i][j] - (row * i + col * j);
                    mp[val]++;
                }
            }

            int maxFreq = 0;
            for (auto &p : mp) {
                maxFreq = max(maxFreq, p.second);
            }

            ans = min(ans, tot - maxFreq);
        }
    }

    cout << ans << endl;
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