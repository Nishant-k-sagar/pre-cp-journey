#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

bool prd(ll w, ll h, ll high, ll n){
    ll cnt = 0;
    ll cnt1 = high/w;
    ll cnt2 = high/h;
    cnt = cnt1 * cnt2;

    return cnt >= n;
}
void nottryingenouf()
{
    // try it harder
    ll w, h, n;
    cin>>w>>h>>n;

    ll low = 0;
    ll high = 1;
    int mid;

    while(prd(w, h, high, n) == false){
        high*=3;
    }

    while(low+1<high){
        ll mid = low + (high - low)/2;

        if(prd(w, h, mid, n)){
            high = mid;
        }
        else {
            low = mid;
        }
    }
    cout<<high<<endl;

}

int main()
{
    fast
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        nottryingenouf();
    }
}