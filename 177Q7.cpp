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

        unordered_map<int, int> mp;
        vector<int> uniq;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (mp[x] == 0)
                uniq.push_back(x);
            mp[x]++;
        }

        ll notuniq = 0;
        int d = uniq.size();

        for (int i = 0; i < d; i++) {
            for (int j = i + 1; j < d; j++) {
                if ((uniq[i] & uniq[j]) == 0) {
                    notuniq += (ll)mp[uniq[i]] * mp[uniq[j]];
                }
            }
        }

        ll pairCnt = (ll)n * (n - 1) / 2;
        ll ans = 2LL * pairCnt - notuniq;

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