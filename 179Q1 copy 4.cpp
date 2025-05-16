#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    int n;
    cin>>n;

    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    int idx = -1;

    int cur = v[n-1];

    for(int i=0; i<n; i++){
        if(i==n-1)idx = n;
        if(v[i]<cur){
            continue;
        }
        else{
            idx = i+1;
            break;
        }
    }

    // cout<<"IDX"<< idx<<endl;
    cout<<n-idx<<endl;
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