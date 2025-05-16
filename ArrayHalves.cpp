#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    ll n;
    cin>>n;

    vector<ll> arr(2*n);

    for(ll i=0; i<2*n; i++){
        cin>>arr[i];
    }

    ll cnt = 0;
    ll ans = 0;

    for(ll i=0; i<2*n; i++){
        if(arr[i]>n)cnt++;
        else ans+=cnt;
    }
    cout<<ans<<endl;
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