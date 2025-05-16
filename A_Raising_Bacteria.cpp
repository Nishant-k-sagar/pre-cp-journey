#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    int x;
    cin>>x;

    int cnt = 0;
    while(x){
        cnt+=x&1;
        x=x>>1;
    }
    cout<<cnt<<endl;
}

int main()
{
    fast
        ll t=1;
    // cin >> t;
    while (t--)
    {
        nottryingenouf();
    }
}