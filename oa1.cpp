#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void solve()
{
    int n;
    cin>>n;

    unordered_map<int, int> mp;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(x <=n) mp[x]++;
    }

    cout<<mp.size()<<endl;

}

int main()
{
    fast
        ll t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}