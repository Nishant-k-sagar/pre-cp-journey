#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

int n, x, y;


bool prd(int t)
{
    // try it harder

    if(t< min(x, y))return false;

    int cnt = 1;
    t-= min(x, y);
    cnt += t/x + t/y;

    return (cnt >= n);  
}

int main()
{
    fast
    //     ll t;
    // cin >> t;

    cin>>n>>x>>y;

    int l = 0;

    int r = min(x, y)*n + 1;

    int mid = 0;

    while(l+1 < r){
        mid = l + (r-l)/2;

        if(prd(mid)){
            r = mid;
        }
        else {
            l = mid;
        }
    }

    cout<<r<<endl;
}