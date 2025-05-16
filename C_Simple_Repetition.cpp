#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);


bool chkPrime(long long n) {
    if (n < 2) return false;
    if (n == 2) return true;
    for ( ll i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

void nottryingenouf()
{   
    // try it harder
    ll x;
    int k;
    cin >> x >> k;

    if (k == 1) {
        if (chkPrime(x)) {
            cout << "YES" <<endl;
        } else {
            cout << "NO" <<endl;
        }
    } else {
        if(x == 1 && k == 2){
            cout<<"YES" <<endl;
        }
        else 
        cout << "NO" << endl;
    }
}

int main()
{
    fast
    int t;
    cin >> t;
    while (t--) {
        nottryingenouf();
    }
    return 0;
}
