#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf() {
    ll x;
    cin >> x;
    
    if ((x & (x - 1)) == 0 || ((x + 1) & x) == 0) {
        cout << "-1" <<endl;
        return;
    }
    
    ll y = 1;
    while ((y << 1) < x) {
        y <<= 1;
    }
    y -= 1;
    
    cout << y << endl;
}

int main() {
    fast;
    ll t;
    cin >> t;
    while (t--) {
        nottryingenouf();
    }
    return 0;
}