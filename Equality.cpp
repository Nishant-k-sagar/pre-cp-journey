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

    vector<ll> vec(n);

    ll sum = 0;
    for(ll i=0; i<n; i++){
        cin>>vec[i];
        sum+=vec[i];
    }

    ll tot = sum/(n-1);

    for(ll i=0; i<n; i++){
        cout<<tot-vec[i]<<" ";
    }
    cout<<endl;

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