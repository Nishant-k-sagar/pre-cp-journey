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

    vector<int> arr(n), brr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> brr[i];
    }

    set<pair<int, int>> nums;

    for (int i = 0; i < n; i++)
    {
        int ca = arr[i], cb = brr[i];

        for (int j = -cb; j <= cb; j++)
        {
            int da = sqrt(cb * cb - j * j);
            for (int ta = ca - da; ta <= ca + da; ta++)
            {
                nums.insert({ta, j});
            }
        }
    }

    cout << nums.size() << endl;
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