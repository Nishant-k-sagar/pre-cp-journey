#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    int n, k;
    cin >> n >> k;

    if (k < n / 2 || k > n) {
        cout << -1 <<endl;
        return;
    }

    string s = "";
    string t = "";
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            s += 'A';
            t += 'A';
        } else {
            s += 'B';
            t += 'B';
        }
    }

    int d = n - k;
    for (int i = 0; i < n; i += 2) {
        if(d>0){
            t[i] = 'C';
            d--;
        }
    }

    cout << s << endl << t << endl;
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