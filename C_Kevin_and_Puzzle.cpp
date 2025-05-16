#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

void codewithlove()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    unordered_map<int, int> mp1, mp2;
    mp1[0] = 1;

    for (int i = 0; i < n; i++) {
        int ai = arr[i];
        int wh = (mp1[ai] + mp2[ai]) % MOD;

        unordered_map<int, int> ch, cl;
        if (wh > 0) ch[ai] = wh;
        for (auto& it : mp1) cl[it.first + 1] = (cl[it.first + 1] + it.second) % MOD;

        mp1 = move(ch);
        mp2 = move(cl);
    }

    int ans = 0;
    for (auto& it : mp1) ans = (ans + it.second) % MOD;
    for (auto& it : mp2) ans = (ans + it.second) % MOD;

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        codewithlove();
    }
    return 0;
}
