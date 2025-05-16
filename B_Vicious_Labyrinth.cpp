#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> res;
    
    if (x % 2 == 1)
    {
        for (int i = 1; i < n; i++)
            res.push_back(n);
        res.push_back(n - 1);
    }
    else
    {
        for (int i = 1; i < n - 1; i++)
            res.push_back(n - 1);
        res.push_back(n);
        res.push_back(n - 1);
    }
    
    for (ll num : res)
        cout << num << " ";
    cout << '\n';
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
    return 0;
}