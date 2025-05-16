#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    ll x, y, z;
    cin >> x >> y >> z;
    
    vector<ll>arr = {x, y, z};
    ll mini = LONG_LONG_MAX;
    
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            ll a = arr[i], b = arr[j];
            ll score = 0;
            
            if((a == 0 || b == 0 || a % 2 == 0 || b % 2 == 0)){
                score =  a + b;
            }
            else {
                score = a + b - 1;
            }
            mini = min(mini, score);
        }
    }
    
    cout << mini << endl;
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