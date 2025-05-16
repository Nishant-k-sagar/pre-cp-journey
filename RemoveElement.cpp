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

    ll k;
    cin>>k;

    vector<ll> arr(n);
    
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }
    
    ll maxi = *max_element(arr.begin(), arr.end());
    ll mini = *min_element(arr.begin(), arr.end());
    
    if(n == 1){
        cout<<"YES"<<endl;
        return;
    }

    if(mini+maxi <=k){
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
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