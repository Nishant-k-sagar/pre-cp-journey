#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

int n, k;
vector<int> arr;

bool prd(ld x){
    int s = 0;

    for(int i=0; i<n; i++){
        s+=(arr[i]/x);
    }
    return s>=k;
}

int main()
{
    fast
    //     ll t;
    // cin >> t;

    cin>>n>>k;

    arr.resize(n);

    for(int i=0; i<n; i++)cin>>arr[i];

    ld l = 0;
    ld r = 1e8;

    for(int i = 0; i<100; i++){
        ld mid = (r+l)/2;

        if(prd(mid)){
            l = mid;
        }
        else {
            r = mid;
        }
    }

    cout<< setprecision(20) <<l<<endl;

}