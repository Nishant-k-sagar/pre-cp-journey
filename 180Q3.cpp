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

    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }

    // if(n == 1){
    //     cout<<arr[0]<<endl;
    //     return;
    // }
    // else 
    // if(n<=3){
    //     for(int i=0; i<n; i++){
    //         if(i%2 == 0){
    //             arr[i]++;
    //         }
    //     }

    //     int maxi = *max_element(arr.begin(), arr.end());
    //     cout<<maxi<<endl;
    //     return;
    // }

    // for(int i=0; i<n-3; i++){
    //     int maxi = max(max(arr[i]+1, arr[i+1]), arr[i+2] + 1);
    //     arr[i] = maxi;
    //     arr[i+1] = maxi;
    //     arr[i+2] = maxi;
    // }

    // int ans = *max_element(arr.begin(), arr.end());

    // cout<<ans<<endl;

    ll ans = arr[0];
    
    for (ll i = 0; i < n - 2; i++) {
        ll maxi = max(arr[i] + 1, arr[i + 2] + 1);
        ans = max(ans, max(maxi, arr[i + 1]));
    }
    
    cout << ans << endl;
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