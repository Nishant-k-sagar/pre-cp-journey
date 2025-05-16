#include <bits/stdc++.h>
using namespace std;

bool codewithlove()
{
    int n;
    cin >> n;
    vector<long long> a(n), b(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] < b[i])
        {
            goto second_check;
        }
    }
    return true;

second_check:
    for (int i = 0; i < n; i++)
    {
        long long needed = b[i] - a[i];
        if (needed <= 0)
            continue;

        long long minExcess = LLONG_MAX;
        for (int j = 0; j < n; j++)
        {
            if (j == i)
                continue;
            minExcess = min(minExcess, a[j] - b[j]);
        }

        if (minExcess >= needed)
        {
            return true;
        }
    }
    return false;
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
        cout << (codewithlove() ? "YES\n" : "NO\n");
    }
    return 0;
}