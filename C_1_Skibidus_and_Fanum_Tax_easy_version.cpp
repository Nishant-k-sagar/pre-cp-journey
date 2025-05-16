#include<bits/stdc++.h>
using namespace std;
#define ll long long

void nottryingenouf() {
    //try harder
    ll n, m;
    cin >> n >> m;
    
    vector<ll> a(n);
    ll x;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> x;
    
    ll prev = LONG_LONG_MIN;
    bool flag = true;
    
    ll i=0;
    while(i<n){
        ll mini = min(a[i], x - a[i]);
        ll maxi = max(a[i], x - a[i]);
        
        if(mini >= prev) {
            prev = mini;
        }
        else if(maxi >= prev) {
            prev = maxi;
        }
        else {
            flag = false;
            break;
        }
        i++;
    }
    
    cout << (flag ? "YES" : "NO");
    cout<<endl;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        nottryingenouf();
    }
}