#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

int gcd_sum(const vector<int>& a) {
    int s = 0;
    for (int i = 0; i + 1 < (int)a.size(); ++i)
        s += __gcd(a[i], a[i + 1]);
    return s;
}

bool brute(int n, int k, vector<int>& ans) {
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    do {
        if (gcd_sum(v) == k) {
            ans = v;
            return true;
        }
    } while (next_permutation(v.begin(), v.end()));
    return false;
}

bool cons(int n, int k, vector<int>& ans) {
    if (k < n - 1) return false;
    int x = k - (n - 2);
    if (x <= n - 2 || 2LL * x > 1000000000LL) return false;
    ans.clear();
    for (int i = 1; i <= n - 2; ++i) ans.push_back(i);
    ans.push_back(x);
    ans.push_back(2 * x);
    return true;
}

void nottryingenouf()
{
    int n, k;
    cin >> n >> k;
    vector<int> ans;
    bool ok = false;
    if (n <= 8) ok = brute(n, k, ans);
    if (!ok) ok = cons(n, k, ans);
    if (!ok) cout << -1 << '\n';
    else for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i == n - 1];
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
