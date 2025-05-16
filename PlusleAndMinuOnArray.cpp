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

    ll sum1 = 0;
    ll sum2 = 0;
    ll mini = INT_MAX;
    ll maxi = INT_MIN;
    for(ll i=0; i<n; i++){
        if(i&1){
            sum2+=abs(arr[i]);
            maxi = max(maxi, abs(arr[i]));
        }

        else {
            sum1+=abs(arr[i]);
            mini = min(mini, abs(arr[i]));
        }
    }

    if(maxi <= mini){
        cout<<(sum1-sum2)<<endl;
    }
    else cout<<sum1-sum2 + 2*(maxi - mini)<<endl;
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