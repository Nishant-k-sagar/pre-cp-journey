#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder

    int n = 3;
    vector<string> v;

    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        v.push_back(s);
    }

    // for(int i=0; i<n; i++){
    //     cout<<v[i]<<" ";
    // }
    string ans = "";
    for(int i = 0; i<n; i++){
        ans+=v[i][0];
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