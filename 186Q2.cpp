#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    ll n, m, a, b;
    cin >> n >> m >> a >> b;

    ll diff = a - b;
    ll rhs = m - b * n;

    if (diff == 0) {
        cout << (b * n == m ? "Yes" : "No");
        cout<<endl;
        return;
    }

    if (rhs % diff != 0) {
        cout << "No";
        cout<<endl;
        return;
    }

    ll x = rhs / diff;
    if (x >= 0 && x <= n) {
        cout << "Yes";
        cout<<endl;
        } else {
        cout << "No";
        cout<<endl;
    }
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