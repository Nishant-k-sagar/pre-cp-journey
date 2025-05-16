#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    int left = 0, nonZeroPairs = 0;
    for (auto &it : mpp)
    {
        if (it.first != 0)
        {
            left += (it.second % 2);
            nonZeroPairs += (it.second / 2);
        }
    }

    int zeroCnt = mpp[0];

    if (left == 0)
    {
        cout << 1 << "\n";
        return;
    }

    int totZero = zeroCnt + nonZeroPairs;
    int finalZero = (totZero > 0) ? 1 : 0;

    int ans = left + finalZero;
    cout << ans << "\n";
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
