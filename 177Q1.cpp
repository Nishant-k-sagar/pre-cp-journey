#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    int a,b,c;
    cin>>a>>b>>c;

    if(a+b>c && b+c>a && a+c>b){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
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