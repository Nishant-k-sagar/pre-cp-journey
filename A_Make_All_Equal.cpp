#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &a, int n)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }

    int maxFreq = 0;
    for (auto &p : freq)
    {
        maxFreq = max(maxFreq, p.second);
    }

    return n - maxFreq;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int res = helper(a, n);

        cout << res << endl;
    }
    return 0;
}
