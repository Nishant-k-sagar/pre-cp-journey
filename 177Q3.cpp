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

    vector<int> arr(n), brr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> brr[i];
    }

    for (int i = 0; i < n; i++)
    {
        vector<pair<int, int>> vp;
        int pivot = arr[i];

        for (int j = 0; j < n; j++)
        {
            vp.push_back({abs(arr[j] - pivot), arr[j]});
        }

        sort(vp.begin(), vp.end());

        bool flag = true;
        for (int j = 0; j < n; j++)
        {
            if (brr[j] != vp[j].second)
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
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