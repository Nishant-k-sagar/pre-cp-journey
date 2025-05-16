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

    vector<ll> arr(n);

    ll sum = 0;
    
    for(ll i=0; i<n; i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    
    ll prefsum = 0;

    ll ans = sum;
    for(ll i=0; i<n; i++){
        prefsum+=arr[i];
        ll rem = sum - prefsum;
        ll req = max(prefsum, rem);
        ans = min(req, ans);
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