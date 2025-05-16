#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    int x, y, k;
    cin >> x >> y >> k;

    int diff = abs(x - y);

    if (diff == k)
    {
        cout << 0 << endl;
        return;
    }

    int tot = x + y;
    if (k > tot || (k % 2 != diff % 2))
    {
        cout << -1 << endl;
        return;
    }

    cout << abs(diff - k) / 2 << endl;
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