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

    if(n == 0){
        cout<<0<<endl;
        return;
    }

    if(n%3 == 0){
        cout<<n<<endl;
        return;
    }

    int rem = n%3;

    if(rem == 1){
        cout<<n-1<<endl;
    }
    else cout<<n+1<<endl;
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